#include "Combat.h"
#include "Attribute.h"
#include "config/Config.h"
#include "gmlib/gm/enum/WeatherType.h"
#include "gmlib/mc/world/Level.h"
#include "gmlib/mc/world/Scoreboard.h"
#include "gmlib/mc/world/actor/Player.h"
#include "ila/event/minecraft/world/actor/MobHealthChangeEvent.h"
#include "ll/api/event/EventBus.h"
#include "ll/api/event/player/PlayerDieEvent.h"
#include "ll/api/event/world/SpawnMobEvent.h"
#include "mc/deps/core/math/Vec3.h"
#include "mc/deps/shared_types/legacy/actor/ActorDamageCause.h"
#include "mc/server/commands/CommandUtils.h"
#include "mc/world/actor/Actor.h"
#include "mc/world/actor/ActorDamageSource.h"
#include "mc/world/actor/Mob.h"
#include "mc/world/actor/ai/util/BossBarColor.h"
#include "mc/world/actor/item/ItemActor.h"
#include "mc/world/actor/player/Player.h"
#include "mc/world/actor/projectile/ThrownTrident.h"
#include "mc/world/attribute/AttributeBuff.h"
#include "mc/world/effect/MobEffect.h"
#include "mc/world/effect/MobEffectInstance.h"
#include "mc/world/inventory/FillingContainer.h"
#include "mc/world/item/Item.h"
#include "mc/world/item/ItemStack.h"
#include "mc/world/item/enchanting/EnchantUtils.h"
#include "mc/world/level/Level.h"
#include "mc/world/level/Spawner.h"
#include "mc/world/level/block/Block.h"
#include "mc/world/level/dimension/Dimension.h"
#include "mc/world/phys/AABB.h"
#include "mc/world/scores/PlayerScoreSetFunction.h"
#include <algorithm>
#include <cmath>
#include <format>
#include <nlohmann/json.hpp>
#include <random>
#include <string>


using json = nlohmann::json;

namespace cb {

#define logger cb::Entry::getInstance().getSelf().getLogger()

// ========== 原有辅助函数（未改动） ==========
double reverseCombined(
    double final_damage,
    int    strength_level,
    int    weakness_level,
    bool   is_vanilla_crit,
    int    protection_level,
    int    resistance_level,
    double crit_multiplier = 1.5
) {
    if (resistance_level >= 5) return 0.0;
    double d             = final_damage;
    double resist_factor = 1.0 - 0.2 * resistance_level;
    if (resist_factor > 0.0) d /= resist_factor;
    else return 0.0;
    double protect_reduction = std::min(0.8, protection_level * 0.04);
    double protect_factor    = 1.0 - protect_reduction;
    if (protect_factor > 0.0) d /= protect_factor;
    else return 0.0;
    if (is_vanilla_crit) {
        if (crit_multiplier == 0.0) return 0.0;
        d /= crit_multiplier;
    }
    if (weakness_level > 0) {
        double p_weak     = std::pow(0.8, weakness_level);
        double const_weak = (p_weak - 1.0) / 0.4;
        if (std::abs(p_weak) < 1e-12) return 0.0;
        d = (d - const_weak) / p_weak;
    }
    if (strength_level > 0) {
        double p_str     = std::pow(1.3, strength_level);
        double const_str = (p_str - 1.0) / 0.3;
        if (std::abs(p_str) < 1e-12) return 0.0;
        d = (d - const_str) / p_str;
    }
    return std::max(0.0, d);
}

double forwardCombined(double base_damage, int strength_level, int weakness_level) {
    double d = base_damage;
    if (strength_level > 0) {
        double p_str = std::pow(1.3, strength_level);
        d            = p_str * d + (p_str - 1.0) / 0.3;
    }
    if (weakness_level > 0) {
        double p_weak = std::pow(0.8, weakness_level);
        d             = p_weak * d + (p_weak - 1.0) / 0.4;
    }
    return std::max(0.0, d);
}

class VelocityHelper {
public:
    static bool setVerticalVelocity(Player* player, float y) {
        if (!player) {
            logger.error("setVerticalVelocity: 玩家不存在");
            return false;
        }
        auto& ctx  = player->getEntityContext();
        auto  comp = ctx.tryGetComponent<StateVectorComponent>();
        if (!comp) {
            logger.error("setVerticalVelocity: 未找到玩家 {} 的 StateVectorComponent", player->getNameTag());
            return false;
        }
        comp->mPosDelta->y = y;
        return true;
    }
    static float getVerticalVelocity(Player* player) {
        if (!player) return 0.0f;
        auto& ctx  = player->getEntityContext();
        auto  comp = ctx.tryGetComponent<StateVectorComponent>();
        if (!comp) return 0.0f;
        return comp->mPosDelta->y;
    }
};

static bool isProcessingSweepDamage = false;
static json healthDisplayDuration   = {};
static json blockAttr               = {};
static json regenTimer              = {};

// ========== 新增：统一属性提取函数 ==========
static json getActorAttributes(Actor* actor, bool isAttacker = false) {
    json attr = defaultAttr;
    if (!actor) return attr;

    auto scoreboard = gmlib::GMScoreboard::getInstance();

    if (actor->isPlayer()) {
        auto player      = static_cast<Player*>(actor);
        auto name        = player->getRealName();
        auto player_attr = getPlayerAttrData()[name];
        if (!player_attr.is_null()) attr = player_attr;

        // 跳劈判定
        if (isAttacker) {
            if (!player->hasTag("cb.on_ground") && player->hasTag("cb.on_fall_delay")
                && !player->hasTag("cb.hold_spear") && !player->hasEffect(*MobEffect::getByName("slow_falling"))
                && !player->hasEffect(*MobEffect::getByName("levitation")) && !player->isFlying()) {
                attr["is_vanilla_crit"] = true;
            }
        }
    } else if (actor->hasFamily("mob")) { // 非玩家生物
        auto mob            = static_cast<Mob*>(actor);
        json attr_from_lore = defaultAttr;

        auto main_hand = mob->getEquippedSlot(SharedTypes::Legacy::EquipmentSlot::Mainhand);
        if (!main_hand.isNull()) attr_from_lore = loreToAttr(main_hand, "main_hand", attr_from_lore);
        auto off_hand = mob->getEquippedSlot(SharedTypes::Legacy::EquipmentSlot::Offhand);
        if (!off_hand.isNull()) attr_from_lore = loreToAttr(off_hand, "off_hand", attr_from_lore);
        auto head = mob->getEquippedSlot(SharedTypes::Legacy::EquipmentSlot::Head);
        if (!head.isNull()) attr_from_lore = loreToAttr(head, "head", attr_from_lore);
        auto torso = mob->getEquippedSlot(SharedTypes::Legacy::EquipmentSlot::Torso);
        if (!torso.isNull()) attr_from_lore = loreToAttr(torso, "torso", attr_from_lore);
        auto legs = mob->getEquippedSlot(SharedTypes::Legacy::EquipmentSlot::Legs);
        if (!legs.isNull()) attr_from_lore = loreToAttr(legs, "legs", attr_from_lore);
        auto feet = mob->getEquippedSlot(SharedTypes::Legacy::EquipmentSlot::Feet);
        if (!feet.isNull()) attr_from_lore = loreToAttr(feet, "feet", attr_from_lore);

        for (auto& [key, value] : attr_from_lore.items()) {
            attr[key] = value;
        }

        auto mob_level = scoreboard->getScore("cb.level", mob->getOrCreateUniqueID());
        attr["level"]  = mob_level.has_value() ? mob_level.value() : 0;
    }

    // 攻击者力量/虚弱效果
    if (isAttacker) {
        if (actor->hasEffect(*MobEffect::getByName("strength"))) {
            auto effect = actor->getEffect(*MobEffect::getByName("strength"));
            if (effect) attr["strength_level"] = effect->mAmplifier + 1;
        }
        if (actor->hasEffect(*MobEffect::getByName("weakness"))) {
            auto effect = actor->getEffect(*MobEffect::getByName("weakness"));
            if (effect) attr["weakness_level"] = effect->mAmplifier + 1;
        }
    }

    // 保护附魔等级（仅对生物有效）
    int protection_level = 0;
    if (actor->hasFamily("mob") && !actor->isPlayer()) {
        auto mob       = static_cast<Mob*>(actor);
        auto checkSlot = [&](SharedTypes::Legacy::EquipmentSlot slot) {
            auto item = mob->getEquippedSlot(slot);
            if (!item.isNull() && EnchantUtils::hasEnchant(Enchant::Type::Protection, item)) {
                protection_level += EnchantUtils::getEnchantLevel(Enchant::Type::Protection, item);
            }
        };
        checkSlot(SharedTypes::Legacy::EquipmentSlot::Head);
        checkSlot(SharedTypes::Legacy::EquipmentSlot::Torso);
        checkSlot(SharedTypes::Legacy::EquipmentSlot::Legs);
        checkSlot(SharedTypes::Legacy::EquipmentSlot::Feet);

        auto mob_crit_resistance = getEntityCritResistanceData()[mob->getTypeName()];
        attr["crit_resistance"]  = (mob_crit_resistance.is_object() ? mob_crit_resistance.value("value", 0.0) : 0.0);
    }
    attr["protection_level"] = protection_level;

    return attr;
}

// ========== MobOnHurt 事件 ==========
auto MobOnHurt = ll::event::EventBus::getInstance().emplaceListener<ila::mc::MobHealthChangeBeforeEvent>(
    [](ila::mc::MobHealthChangeBeforeEvent& event) {
        auto level = gmlib::GMLevel::getInstance();

        auto&  mob    = event.self();
        double damage = static_cast<double>(event.oldValue() - event.newValue());

        if (event.newValue() > event.oldValue()) return;

        level->executeCommandEx(std::format("tell @a[tag=damage_test] 是否为横扫伤害:{}", isProcessingSweepDamage));
        level->executeCommandEx(std::format("tell @a[tag=damage_test] 原伤害:{}", damage));

        auto&  damageSource = event.buff().mSource;
        auto   cause        = damageSource->mCause;
        Actor* source       = nullptr;
        if (damageSource->isEntitySource()) {
            auto uniqueId = damageSource->getDamagingEntityUniqueID();
            source        = level->fetchEntity(uniqueId, false);
            if (source && source->getOwner()) {
                source = source->getOwner();
            }
        }

        json attacker_attr   = defaultAttr;
        json hurted_mob_attr = defaultAttr;

        // 攻击者属性（仅实体攻击或重锤时）
        if (source != nullptr
            && (cause == SharedTypes::Legacy::ActorDamageCause::EntityAttack
                || cause == SharedTypes::Legacy::ActorDamageCause::MaceSmash)) {
            attacker_attr = getActorAttributes(source, true);
        }

        // 受伤实体属性
        hurted_mob_attr = getActorAttributes(&mob, false);

        // 玩家额外格挡数据
        if (mob.isPlayer()) {
            auto& player = static_cast<Player&>(mob);
            auto  name   = player.getRealName();
            if (!name.empty()) {
                // 确保 blockAttr 中有该玩家条目，若没有则插入默认
                auto it = blockAttr.find(name);
                if (it == blockAttr.end()) {
                    blockAttr.emplace(name, defaultBlockAttr);
                }
                auto& pBlock                           = blockAttr[name];
                hurted_mob_attr["vulnerability_level"] = pBlock.value("vulnerability_level", 0.0);
                hurted_mob_attr["toughness"]           = pBlock.value("toughness", 0.0);
                hurted_mob_attr["block_value"]         = pBlock.value("block_value", 0.0);
                hurted_mob_attr["max_block_value"]     = pBlock.value("max_block_value", 0.0);
            } else {
                // 如果 name 为空，使用默认值
                hurted_mob_attr["vulnerability_level"] = 0.0;
                hurted_mob_attr["toughness"]           = 0.0;
                hurted_mob_attr["block_value"]         = 0.0;
                hurted_mob_attr["max_block_value"]     = 0.0;
            }
        }

        // 抗性提升（作用于受伤实体）
        if (mob.hasEffect(*MobEffect::getByName("resistance"))) {
            auto effect = mob.getEffect(*MobEffect::getByName("resistance"));
            if (effect) {
                hurted_mob_attr["resistance_level"] = effect->mAmplifier + 1;
            }
        }

        // ---- 伤害计算 ----
        if (source != nullptr) {
            if (cause == SharedTypes::Legacy::ActorDamageCause::EntityAttack
                || cause == SharedTypes::Legacy::ActorDamageCause::MaceSmash) {
                if (!isProcessingSweepDamage) {
                    // 还原
                    damage = reverseCombined(
                        damage,
                        attacker_attr.value("strength_level", 0),
                        attacker_attr.value("weakness_level", 0),
                        attacker_attr.value("is_vanilla_crit", false),
                        hurted_mob_attr.value("protection_level", 0),
                        hurted_mob_attr.value("resistance_level", 0)
                    );
                    level->executeCommandEx(std::format("tell @a[tag=damage_test] 还原后伤害:{}", damage));

                    // 基础攻击加成
                    double attack_damage             = attacker_attr["attack_damage"];
                    double attack_damage_pct         = attacker_attr["attack_damage_pct"];
                    double falling_additional_damage = attacker_attr["falling_additional_damage"];
                    double falling_additional_dmg    = 0;
                    if (source->isPlayer()) {
                        auto player = static_cast<Player*>(source);
                        if (falling_additional_damage > 0 && player->hasTag("cb.on_fall_delay") && !player->isFlying()
                            && !player->hasEffect(*MobEffect::getByName("slow_falling"))
                            && !player->hasEffect(*MobEffect::getByName("levitation"))) {
                            if (player->getFallDistance() > 1.5) {
                                falling_additional_dmg = player->getFallDistance() * falling_additional_damage;
                                // 清除摔落伤害
                                VelocityHelper::setVerticalVelocity(player, 0.01f);
                                // 重锤其他效果
                                mob.addTag("cb.mace_hurter");
                                level->executeCommandEx(
                                    std::format(
                                        "execute as \"{}\" at @s run scriptevent cb:mace_effect {}",
                                        player->getRealName(),
                                        player->getFallDistance()
                                    )
                                );
                            }
                        }
                    }
                    damage = (damage + attack_damage) * attack_damage_pct + falling_additional_dmg;
                    level->executeCommandEx(std::format("tell @a[tag=damage_test] 基础伤害:{}", damage));
                    // 暴击加成
                    if (source->isPlayer() && !mob.isPlayer()) {
                        double                                 crit_rate       = attacker_attr["crit_rate"];
                        double                                 cirtical_damage = attacker_attr["cirtical_damage"];
                        double                                 crit_resistance = hurted_mob_attr["crit_resistance"];
                        std::random_device                     rd;
                        std::mt19937                           gen(rd());
                        std::uniform_real_distribution<double> realDist(0.00, 1.00);
                        double                                 randomReal = realDist(gen);
                        if (crit_rate - crit_resistance >= randomReal) {
                            damage          += damage * cirtical_damage;
                            auto player      = static_cast<Player*>(source);
                            auto name        = player->getRealName();
                            auto player_pos  = player->getFeetPos();
                            level->executeCommandEx(
                                std::format(
                                    "playsound hit_crit @a {} {} {} 1 1",
                                    player_pos.x,
                                    player_pos.y,
                                    player_pos.z
                                )
                            );
                        }
                        level->executeCommandEx(std::format("tell @a[tag=damage_test] 暴击计算后伤害:{}", damage));
                    }
                    // 玩家攻击冷却和横扫
                    if (source->isPlayer()) {
                        auto   player  = static_cast<Player*>(source);
                        double cd_time = attacker_attr["atk_cd_time"];
                        double cd      = attacker_attr["atk_cd"];
                        if (cd_time != cd && cd_time != 0) {
                            double rate   = cd / cd_time;
                            double multi  = 1.0 - 0.8 * rate;
                            damage       *= multi;
                        }
                        bool attack_cooled = true;
                        if (cd > 0 && cd_time > 0) {
                            if (cd / cd_time < 0.85) attack_cooled = false;
                        }
                        auto pos = player->getFeetPos();
                        if (!attack_cooled) {
                            level->executeCommandEx(
                                std::format("playsound player.attack.weak @a {} {} {} 1 1", pos.x, pos.y, pos.z)
                            );
                        } else {
                            level->executeCommandEx(
                                std::format("playsound player.attack.strong @a {} {} {} 1 1", pos.x, pos.y, pos.z)
                            );
                        }

                        // 横扫
                        double sweep_damage = attacker_attr["sweep_damage"];
                        double sweep_range  = attacker_attr["sweep_range"];
                        if (sweep_damage > 0 && sweep_range > 0 && !player->hasTag("cb.on_run")
                            && player->hasTag("cb.on_ground") && attack_cooled) {
                            isProcessingSweepDamage = true;
                            double sweep_dmg        = damage * sweep_damage;
                            auto   name             = player->getRealName();
                            auto   player_pos       = player->getFeetPos();
                            level->executeCommandEx(
                                std::format(
                                    "execute as \"{}\" at @s anchored eyes facing ^^^1 rotated ~ 0 positioned ^^^0.8 "
                                    "positioned ~~-0.5~ run particle cb:sweep",
                                    name
                                )
                            );
                            level->executeCommandEx(
                                std::format(
                                    "playsound player.attack.sweep @a {} {} {} 1 1",
                                    player_pos.x,
                                    player_pos.y,
                                    player_pos.z
                                )
                            );
                            player->addTag("cb.AtkEveAttacker");
                            mob.addTag("cb.AtkEveHiter");
                            auto mob_pos = mob.getFeetPos();
                            AABB aabb;
                            aabb.min                = mob_pos - sweep_range;
                            aabb.max                = mob_pos + sweep_range;
                            auto&        dimension  = player->getDimension();
                            BlockSource& bs         = dimension.getBlockSourceFromMainChunkSource();
                            auto         entityList = bs.getEntities(aabb, 0);
                            for (auto entity : entityList) {
                                if (entity->hasFamily("mob") && !entity->hasTag("cb.AtkEveAttacker")
                                    && !entity->hasTag("cb.AtkEveHiter")) {
                                    entity->hurtByCause(
                                        static_cast<float>(sweep_dmg),
                                        SharedTypes::Legacy::ActorDamageCause::EntityAttack,
                                        player
                                    );
                                }
                            }
                            player->removeTag("cb.AtkEveAttacker");
                            mob.removeTag("cb.AtkEveHiter");
                            isProcessingSweepDamage = false;
                        }
                    }
                }
            } else if (cause == SharedTypes::Legacy::ActorDamageCause::Projectile) {
                auto uniqueId   = damageSource->getDamagingEntityUniqueID();
                auto projectile = level->fetchEntity(uniqueId, false);
                if (projectile) {
                    // 三叉戟引雷
                    if (projectile->getEntityTypeId() == ActorType::Trident) {
                        auto trident      = static_cast<ThrownTrident*>(projectile);
                        auto trident_item = trident->_getPickupItem();
                        if (EnchantUtils::hasEnchant(Enchant::Type::Channeling, trident_item)
                            && level->getWeather() == gmlib::WeatherType::Thunder) {
                            auto pos = mob.getFeetBlockPos();
                            level->executeCommandEx(
                                std::format("summon minecraft:lightning_bolt {} {} {}", pos.x, pos.y, pos.z)
                            );
                        }
                    }
                }
            }
            // ---- 格挡处理 ----
            if (mob.isPlayer()) {
                auto& player = static_cast<Player&>(mob);
                auto  name   = player.getRealName();

                // Ten: 韧性
                // W: 弱点等级
                double Ten  = hurted_mob_attr["toughness"];
                double W    = hurted_mob_attr["vulnerability_level"];
                double Gmax = hurted_mob_attr["max_block_value"];
                double G    = hurted_mob_attr["block_value"];
                // 如果格挡上限为 0 或负数，则无格挡效果，跳过
                if (Gmax > 0) {
                    // 计算格挡吸收效率 N，确保分母不为 0
                    double N        = (G >= 0.5 * Gmax) ? (G / Gmax) : (0.5 + G / Gmax);
                    auto   off_hand = player.getEquippedSlot(SharedTypes::Legacy::EquipmentSlot::Offhand);
                    // 钳制 N 在 [0, 1] 之间，防止异常
                    N = std::max(0.0, std::min(1.0, N));

                    double AG = std::min(damage * N, G) * (1 - Ten);
                    if (W > 0) AG += Gmax * 0.05 * W;
                    G      -= AG;
                    damage -= AG;

                    blockAttr[name]["block_value"]               = G;
                    blockAttr[name]["max_block_value"]           = Gmax;
                    blockAttr[name]["TrPrecondition"]            = 0.0;
                    blockAttr[name]["block_value_recover_timer"] = 0.0;

                    auto player_pos = player.getFeetPos();
                    // 格挡音效
                    if (AG > 0) {
                        level->executeCommandEx(
                            std::format(
                                "playsound random.anvil_land @a {} {} {} 1 1",
                                player_pos.x,
                                player_pos.y,
                                player_pos.z
                            )
                        );
                    }
                } else {
                    // 无格挡能力，将当前格挡值置为上限（0.0）
                    blockAttr[name]["block_value"]     = 0.0;
                    blockAttr[name]["max_block_value"] = 0.0;
                }

                level->executeCommandEx(std::format("tell @a[tag=damage_test] 格挡计算后伤害:{}", damage));
            }

            // ---- 等级压制 ----
            {
                // Lx: 攻击者等级
                // Ly: 受伤实体等级
                // K: 温和基准线（40）
                // Q: 线性倍率（2.8）
                // q: 压制倍率（2）
                // S: 二次免伤率理论值（0.9）
                double Lx = attacker_attr["level"];
                double Ly = hurted_mob_attr["level"];
                double K  = 40;
                double Q  = 2.8;
                double q  = 2;
                double S  = 0.9;
                level->executeCommandEx(std::format("tell @a[tag=damage_test] 攻击者等级:{} 受攻击者等级:{}", Lx, Ly));

                // N_press: 压制计算中使用的格挡吸收效率，默认0.0，若受伤实体为玩家则取当前格挡效率
                double N_press = 0.0;
                if (mob.isPlayer()) {
                    auto name = static_cast<Player&>(mob).getRealName();
                    if (blockAttr[name].contains("block_value") && blockAttr[name].contains("max_block_value")) {
                        double G    = blockAttr[name]["block_value"];
                        double Gmax = blockAttr[name]["max_block_value"];
                        if (Gmax > 0) {
                            N_press = (G >= 0.5 * Gmax) ? (G / Gmax) : (0.5 + G / Gmax);
                            N_press = std::max(0.0, std::min(1.0, N_press)); // 钳制
                        }
                    }
                }

                // h: 温和值（等级差异标准化）
                // WL: 权修正
                // P: 压制系数
                // m: 最终增减伤比例
                double h  = (Lx - Ly) / (((Lx + Ly) / 2) + K);
                double WL = 0.5 + 0.75 * std::pow(std::max(Lx, Ly) / 100, 2);
                double P  = std::pow(std::max(Lx, Ly) / 100, 3.0 / 2.0);
                double m;
                if (h < 0) {
                    m = std::min(1 + N_press, std::max(1 - N_press, 1 + Q * h * WL + q * h * std::abs(h) * P));
                } else {
                    m = 1 + Q * h * WL * (1 + S * (1 - std::pow(std::exp(1.0), (-q * h * P))));
                }
                damage *= m;
                level->executeCommandEx(std::format("tell @a[tag=damage_test] 等级计算后伤害:{}", damage));
            }

            // ---- 最终伤害加成（力量/虚弱） ----
            damage = forwardCombined(
                damage,
                attacker_attr.value("strength_level", 0),
                attacker_attr.value("weakness_level", 0)
            );
            level->executeCommandEx(std::format("tell @a[tag=damage_test] 力量虚弱计算后伤害:{}", damage));

            // ---- 保护附魔减伤 ----
            damage = static_cast<double>(mob.getDamageAfterEnchantReduction(*damageSource, static_cast<float>(damage)));
            level->executeCommandEx(std::format("tell @a[tag=damage_test] 保护计算后伤害:{}", damage));

            // ---- 盔甲减伤 ----
            {
                // X: 基础防御力（防御值 * 防御百分比）
                // R: 锐伤防护（加算）
                // Rx: 锐伤防护（乘算）
                // B: 钝伤防护（加算）
                // Bx: 钝伤防护（乘算）
                // D: 结构强度（加算）
                // T: 结构强度（乘算）
                // d: 结构穿透（加算，攻击者）
                // t: 结构穿透（乘算，攻击者）
                // r: 锐伤特化（加算，攻击者）
                // rx: 锐伤特化（乘算，攻击者）
                // b: 钝伤特化（加算，攻击者）
                // bx: 钝伤特化（乘算，攻击者）
                // C: 阈值1（20）
                // J: 阈值2（100）
                // S: 二次免伤率理论值（0.9）
                double X  = hurted_mob_attr["defense"].get<double>() * hurted_mob_attr["defense_pct"].get<double>();
                double R  = hurted_mob_attr["sharp_defense"];
                double Rx = hurted_mob_attr["sharp_defense_pct"];
                double B  = hurted_mob_attr["blunt_defense"];
                double Bx = hurted_mob_attr["blunt_defense_pct"];
                double D  = hurted_mob_attr["structure_defense"];
                double T  = hurted_mob_attr["structure_defense_pct"];
                double d  = attacker_attr["structure_level"];
                double t  = attacker_attr["structure_level_pct"];
                double r  = attacker_attr["sharp_level"];
                double rx = attacker_attr["sharp_level_pct"];
                double b  = attacker_attr["blunt_level"];
                double bx = attacker_attr["blunt_level_pct"];
                double C  = 20;
                double J  = 100;
                double S  = 0.9;
                // E: 一次减伤量
                double E  = ((0.1 + D - d) * (1 + T - t) * ((X + R - r) * (1 + Rx - rx)))
                          / (1 + ((X + R - r) * (1 + Rx - rx)) / C);
                double Ex = 0.5 * damage; // 一次减伤上限（50%伤害）
                E         = std::min(E, Ex);
                // Fx: 二次减伤率（百分比）
                double Fx = S * ((X + B - b) * (1 + Bx - bx)) / (((X + B - b) * (1 + Bx - bx)) + J);
                Fx        = std::max(std::min(Fx, 0.9), 0.0);
                damage    = (damage - E) * (1 - Fx);
                level->executeCommandEx(std::format("tell @a[tag=damage_test] 盔甲计算后伤害:{}", damage));
            }

            // ---- 抗性提升减伤 ----
            damage = static_cast<double>(mob.getDamageAfterResistanceEffect(*damageSource, static_cast<float>(damage)));
        } else {
            // ---- 保护附魔减伤 ----
            damage = static_cast<double>(mob.getDamageAfterEnchantReduction(*damageSource, static_cast<float>(damage)));

            // ---- 抗性提升减伤 ----
            damage = static_cast<double>(mob.getDamageAfterResistanceEffect(*damageSource, static_cast<float>(damage)));
        }

        // 修改事件值
        event.newValue() = event.oldValue() - static_cast<float>(damage);
        level->executeCommandEx(std::format("tell @a[tag=damage_test] 计算后伤害:{}", damage));

        // ---- 血条显示 ----
        if (source != nullptr && !isProcessingSweepDamage && source->isPlayer()
            && source->getOrCreateUniqueID() != mob.getOrCreateUniqueID()) {
            auto        player         = static_cast<Player*>(source);
            auto        playerUniqueId = player->getOrCreateUniqueID();
            std::string key            = std::to_string(playerUniqueId.rawID);

            int   current_health = static_cast<int>(event.newValue());
            int   max_health     = mob.getMaxHealth();
            float percent =
                (max_health > 0) ? (static_cast<float>(current_health) / static_cast<float>(max_health)) : 0.0f;

            BossBarColor bossColor    = BossBarColor::Red;
            std::string  health_color = "§c";
            if (percent > 0.8f) {
                health_color = "§a";
                bossColor    = BossBarColor::Green;
            } else if (percent > 0.5f) {
                health_color = "§6";
                bossColor    = BossBarColor::Purple;
            } else if (percent > 0.3f) {
                health_color = "§d";
                bossColor    = BossBarColor::Yellow;
            }

            int         damage_dealt = static_cast<int>(event.oldValue() - event.newValue());
            std::string title        = std::format(
                "§a{} §b[{}{}§b/§a{}§b]<§c§l{}§r§b>",
                CommandUtils::getActorName(mob),
                health_color,
                current_health,
                max_health,
                damage_dealt
            );

            healthDisplayDuration[key]               = {};
            healthDisplayDuration[key]["title"]      = title;
            healthDisplayDuration[key]["percent"]    = percent;
            healthDisplayDuration[key]["color"]      = static_cast<int>(bossColor);
            healthDisplayDuration[key]["bossbar_id"] = 0;
            auto now                                 = std::chrono::steady_clock::now();
            auto expireTime                          = now + std::chrono::seconds(3);
            healthDisplayDuration[key]["expire_time"] =
                std::chrono::duration_cast<std::chrono::milliseconds>(expireTime.time_since_epoch()).count();
        }
    }
);

// ========== HealthDisplayLoop ==========
void HealthDisplayLoop() {
    auto now   = std::chrono::steady_clock::now();
    auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

    std::vector<std::string> keysToRemove;
    for (auto& item : healthDisplayDuration.items()) {
        const auto& key   = item.key();
        auto&       value = item.value();
        if (nowMs >= value["expire_time"].get<int64>()) {
            auto playerUniqueId = ActorUniqueID(static_cast<int64>(std::stoull(key)));
            auto level          = gmlib::GMLevel::getInstance();
            if (auto* player = level->getPlayer(playerUniqueId)) {
                auto&   pl        = static_cast<gmlib::GMPlayer&>(*player);
                int64_t bossBarId = value["bossbar_id"].get<int64>();
                if (bossBarId != 0) {
                    pl.removeClientBossbar(bossBarId);
                }
            }
            keysToRemove.push_back(key);
            continue;
        }
        auto  playerUniqueId = ActorUniqueID(static_cast<int64>(std::stoull(key)));
        auto  level          = gmlib::GMLevel::getInstance();
        auto* player         = level->getPlayer(playerUniqueId);
        if (!player) {
            keysToRemove.push_back(key);
            continue;
        }
        auto&        pl       = static_cast<gmlib::GMPlayer&>(*player);
        int64_t      fixedId  = 3652 + (playerUniqueId.rawID % 10000);
        int64_t      storedId = value["bossbar_id"].get<int64>();
        std::string  title    = value["title"].get<std::string>();
        float        percent  = value["percent"].get<float>();
        BossBarColor color    = static_cast<BossBarColor>(value["color"].get<int>());

        if (storedId == 0) {
            pl.setClientBossbar(fixedId, title, percent, color);
            value["bossbar_id"] = fixedId;
        } else {
            pl.updateClientBossbarName(storedId, title);
            pl.updateClientBossbarPercentage(storedId, percent);
            pl.updateClientBossbarColor(storedId, color);
        }
    }
    for (const auto& key : keysToRemove) {
        healthDisplayDuration.erase(key);
    }
}

// ========== BlockLoop ==========
void BlockLoop(Player& player) {
    auto scoreboard = gmlib::GMScoreboard::getInstance();
    if (!scoreboard) {
        return;
    }
    if (!player.isAlive() || !player.isPlayerInitialized()) return;
    auto name = player.getRealName();
    if (name.empty()) return;

    // 安全获取玩家属性
    auto   player_attr = getPlayerAttrData().value(name, defaultAttr);
    double Agi         = player_attr.value("movement_value", 0.0);

    // 确保 blockAttr 中有该玩家的条目
    auto& player_block_attr = blockAttr[name];
    if (player_block_attr.empty()) {
        player_block_attr = defaultBlockAttr;
    }

    // 使用 value() 读取所有需要的属性，提供默认值
    double Ten  = player_block_attr.value("toughness", 0.0);
    double G    = player_block_attr.value("block_value", 0.0);
    double Gmax = 0.0;

    // X: 基础防御力（防御值 * 防御百分比）
    // R: 锐伤防护（加算）
    // Rx: 锐伤防护（乘算）
    // B: 钝伤防护（加算）
    // Bx: 钝伤防护（乘算）
    // Eg: 其他属性提供的格挡值
    // D: 结构强度（加算）
    // T: 结构强度（乘算）
    // O: 格挡效率（此处默认为0）
    double X  = player_attr["defense"].get<double>() * player_attr["defense_pct"].get<double>();
    double R  = player_attr["sharp_defense"];
    double Rx = player_attr["sharp_defense_pct"];
    double B  = player_attr["blunt_defense"];
    double Bx = player_attr["blunt_defense_pct"];
    double Eg = player_attr["block"];
    double D  = player_attr["structure_defense"];
    double T  = player_attr["structure_defense_pct"];
    double O  = 0;

    // Gmax: 格挡上限
    Gmax = (0.5 * X + 0.5 * R * (1 + Rx) + 0.5 * B * (1 + Bx) + Eg) * D * (1 + T) * (1 + O);

    double Tr, Rg, Go, To, Trx, TrPrecondition;
    bool   Br = false;
    // 获取玩家分数
    auto scoreOpt = scoreboard->getPlayerScore("cb.Br", player.getOrCreateUniqueID());
    if (scoreOpt.has_value() && scoreOpt.value() > 0) {
        Br = true;
    }

    // 弱点等级处理
    double vul_level = player_block_attr.value("vulnerability_level", 0.0);
    if (vul_level > 0) {
        double vul_timer = player_block_attr.value("vulnerability_level_timer", 0.0) + 1.0;
        double threshold = 30.0 / (1.0 + 0.05 * Agi) * (1.0 + Ten);
        if (vul_timer >= threshold) {
            vul_level -= 1.0;
            vul_timer  = 0.0;
        }
        player_block_attr["vulnerability_level"]       = vul_level;
        player_block_attr["vulnerability_level_timer"] = vul_timer;
    }

    if (Br) {
        // 弱点击破
        G = -10.0 * Gmax / (1.0 + 0.5 * Agi) * (1.0 + 2.0 * Ten);
    } else if (Gmax >= 0.0) {
        if (G > Gmax) {
            // 格挡值溢出处理
            double overrun_timer = player_block_attr.value("block_value_overrun_timer", 0.0) + 1.0;
            if (overrun_timer >= 20.0) {
                Go             = G - Gmax;
                To             = 4.0 * (1.0 + 0.5 * Agi);
                G             -= Go / To;
                overrun_timer  = 0.0;
            }
            player_block_attr["block_value_overrun_timer"] = overrun_timer;
        } else if (!Br) {
            // 恢复前置条件
            TrPrecondition = 6.0 - 0.1 * Agi * (1.0 + Ten);
            if (TrPrecondition < 2.0) TrPrecondition = 2.0;

            double tr_pre = player_block_attr.value("TrPrecondition", 0.0);
            if (tr_pre < TrPrecondition * 20.0) {
                tr_pre += 1.0;
            }
            player_block_attr["TrPrecondition"] = tr_pre;

            double recover_timer = player_block_attr.value("block_value_recover_timer", 0.0);
            if (G < 0.0 || tr_pre >= TrPrecondition * 20.0) {
                recover_timer += 1.0;
            }

            if (G >= 0.0) {
                Tr = std::max(1.0, 4.0 / (1.0 + Agi));
                if (recover_timer >= Tr * 20.0) {
                    Rg            = Gmax * (0.1 * (1.0 + Ten));
                    G             = std::min(G + Rg, Gmax);
                    recover_timer = 0.0;
                }
            } else {
                // G < 0
                Trx = 1.0 / (1.0 + 0.5 * Agi);
                if (recover_timer >= Trx * 20.0) {
                    G             = std::min(G + Gmax * (0.1 + 0.2 * Ten), 0.0);
                    recover_timer = 0.0;
                }
            }
            player_block_attr["block_value_recover_timer"] = recover_timer;
        }
    }
    // 更新最终的 G
    player_block_attr["block_value"]     = G;
    player_block_attr["max_block_value"] = Gmax;
}

// ========== RegenerationLoop ==========
void RegenerationLoop(Player& player) {
    auto name = player.getRealName();
    if (!regenTimer.contains(name)) {
        regenTimer[name] = defaultRegenTimer;
    }
    int sneak_regen = regenTimer[name]["sneak_regen"];
    int ride_regen  = regenTimer[name]["ride_regen"];
    int sleep_regen = regenTimer[name]["sleep_regen"];
    if (player.isSneaking()) {
        sneak_regen++;
        if (sneak_regen >= 300) {
            player.addEffect(MobEffectInstance(10, EffectDuration(40), 1));
            sneak_regen = 0;
        }
    } else if (!player.isSneaking() && sneak_regen > 0) {
        sneak_regen = 0;
    }
    if (player.isRiding()) {
        ride_regen++;
        if (ride_regen >= 300) {
            player.addEffect(MobEffectInstance(10, EffectDuration(40), 1));
            ride_regen = 0;
        }
    } else if (!player.isSneaking() && ride_regen > 0) {
        ride_regen = 0;
    }
    if (player.isSleeping()) {
        sleep_regen++;
        if (sleep_regen >= 600) {
            player.addEffect(MobEffectInstance(10, EffectDuration(600), 1));
            sleep_regen = 0;
        }
    } else if (!player.isSneaking() && sleep_regen > 0) {
        sleep_regen = 0;
    }
    regenTimer[name]["sneak_regen"] = sneak_regen;
    regenTimer[name]["ride_regen"]  = ride_regen;
    regenTimer[name]["sleep_regen"] = sleep_regen;
}

// ========== OnMobSpawn ==========
auto OnMobSpawn = ll::event::EventBus::getInstance().emplaceListener<ll::event::world::SpawnedMobEvent>(
    [](ll::event::world::SpawnedMobEvent& event) {
        auto scoreboard = gmlib::GMScoreboard::getInstance();
        auto mobOpt     = event.mob();
        if (!mobOpt) {
            return;
        }
        auto& mob               = mobOpt.get();
        auto& entity_level_data = getEntityLevelData();
        auto& type              = mob.getTypeName();
        if (entity_level_data.contains(type)) {
            int level = 0;
            if (entity_level_data[type].contains("value")) {
                level = entity_level_data[type]["value"];
            } else if (entity_level_data[type].contains("min") && entity_level_data[type].contains("max")) {
                std::random_device                 rd;
                std::mt19937                       gen(rd());
                std::uniform_int_distribution<int> intDist(
                    entity_level_data[type]["min"],
                    entity_level_data[type]["max"]
                );
                level = intDist(gen);
            }
            scoreboard->setScore("cb.level", mob.getOrCreateUniqueID(), level);
        }
    }
);

// ========== MoblevelLoop ==========
void MoblevelLoop() {
    auto  level             = gmlib::GMLevel::getInstance();
    auto  scoreboard        = gmlib::GMScoreboard::getInstance();
    auto& entity_level_data = getEntityLevelData();
    auto  entityList        = level->getEntities();
    for (auto& i : entityList) {
        if (i.has_value() && i.tryUnwrap().has_value()) {
            auto& entity = i.tryUnwrap().get();
            if (entity.hasFamily("mob")) {
                auto& type = entity.getTypeName();
                if (type != "minecraft:player") {
                    if (entity_level_data.contains(type)) {
                        if (!scoreboard->getScore("cb.level", entity.getOrCreateUniqueID()).has_value()) {
                            int level = 0;
                            if (entity_level_data[type].contains("value")) {
                                level = entity_level_data[type]["value"];
                            } else if (
                                entity_level_data[type].contains("min") && entity_level_data[type].contains("max")
                            ) {
                                std::random_device                 rd;
                                std::mt19937                       gen(rd());
                                std::uniform_int_distribution<int> intDist(
                                    entity_level_data[type]["min"],
                                    entity_level_data[type]["max"]
                                );
                                level = intDist(gen);
                            }
                            scoreboard->setScore("cb.level", entity.getOrCreateUniqueID(), level);
                        }
                    }
                }
            }
        }
    }
}

// ========== OnPlayerDie ==========
auto OnPlayerDie = ll::event::EventBus::getInstance().emplaceListener<ll::event::player::PlayerDieEvent>(
    [](ll::event::player::PlayerDieEvent& event) {
        auto& player = event.self();
        player.resetPlayerLevel();
    }
);

json getBlockAttr() { return blockAttr; }

} // namespace cb