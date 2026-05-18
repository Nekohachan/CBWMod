#include "Entry.h"
#include "ila/event/minecraft/world/actor/MobHurtEffectEvent.h"
#include "ll/api/event/EventBus.h"
#include "ll/api/service/Bedrock.h"
#include "mc/world/actor/Actor.h"
#include "mc/world/actor/ActorDamageSource.h"
#include "mc/world/actor/Mob.h"
#include "mc/world/actor/item/ItemActor.h"
#include "mc/world/actor/player/Player.h"
#include "mc/world/attribute/Attribute.h"
#include "mc/world/attribute/AttributeInstanceConstRef.h"
#include "mc/world/effect/MobEffect.h"
#include "mc/world/effect/MobEffectInstance.h"
#include "mc/world/events/PlayerEventListener.h"
#include "mc/world/inventory/FillingContainer.h"
#include "mc/world/item/Item.h"
#include "mc/world/item/ItemStack.h"
#include "mc/world/level/Level.h"
#include <fstream>
#include <mc/deps/shared_types/legacy/actor/ActorDamageCause.h>
#include <mc/world/attribute/AttributeInstance.h>
#include <mc/world/attribute/SharedAttributes.h>
#include <nlohmann/json.hpp>
#include <string>


using json = nlohmann::json;

namespace cb {

auto mob_onhurt = ll::event::EventBus::getInstance().emplaceListener<ila::mc::world::actor::MobHurtEffectBeforeEvent>(
    [](ila::mc::world::actor::MobHurtEffectBeforeEvent& event) {
        // event.cancel(); // 取消事件
        // 获取level实例
        auto level = ll::service::getLevel();
        if (!level) {
            return;
        }
        // 伤害值
        auto damage = static_cast<double>(event.value());
        // 伤害原因
        auto& cause = event.cause();
        // 伤害源
        auto source = event.source();

        auto& mSelf = cb::Entry::getInstance().getSelf();

        auto          player_attr_path = mSelf.getDataDir() / "player_attr.json";
        std::ifstream player_attr(player_attr_path);
        json          player_attr_data = json::parse(player_attr);

        auto          item_attr_path = mSelf.getConfigDir() / "item_attr.json";
        std::ifstream item_attr(player_attr_path);
        json          item_attr_data = json::parse(item_attr);

        json attacker_attr;
        json hurt_mob_attr;


        // 如果伤害来源是实体
        if (source.has_value()) {
            auto& damage_source = event.source().value();
            // 获取造成伤害的实体
            auto attackerUniqueID = damage_source.getSourceUniqueID();
            if (damage_source.isPlayer()) {
                auto player      = level->getPlayer(attackerUniqueID);
                auto name        = player->getRealName();
                auto player_attr = player_attr_data[name];
                // 读取实体基础伤害
                auto attribute               = player->getAttribute(SharedAttributes::ATTACK_DAMAGE());
                auto baseDamage              = attribute.mPtr->mCurrentValue;
                player_attr["entity_damage"] = baseDamage;
                // 检测力量buff
                if (player->hasEffect(*MobEffect::getByName("strength"))) {
                    auto effectLevel = player->getEffect(*MobEffect::getByName("strength"))->mAmplifier + 1;
                    player_attr["strength_level"] = effectLevel;
                }
                // 检测虚弱buff
                if (player->hasEffect(*MobEffect::getByName("weakness"))) {
                    auto effectLevel = player->getEffect(*MobEffect::getByName("weakness"))->mAmplifier + 1;
                    player_attr["weakness_level"] = effectLevel;
                }

                attacker_attr = player_attr;
            } else {
                auto mob      = level->getMob(attackerUniqueID);
                auto mob_attr = player_attr_data["default_attr"];
                // 读取实体基础伤害
                auto attribute            = mob->getAttribute(SharedAttributes::ATTACK_DAMAGE());
                auto baseDamage           = attribute.mPtr->mCurrentValue;
                mob_attr["entity_damage"] = baseDamage;
                // 读取装备
                for (auto equipment : mob->getAllEquipment()) {
                    auto id        = equipment->getTypeName();
                    auto item_attr = item_attr_data[id];
                    for (auto& element : item_attr.items()) {
                        if (element.key().find("slot")) {
                        } else if (element.key().find("_rate") && element.key() != "crit_rate"
                                   && element.key() != "hit_rate") {
                            mob_attr[element.key()] = static_cast<double>(mob_attr[element.key()]) - 1.0
                                                    + static_cast<double>(item_attr[element.key()]);
                        } else {
                            mob_attr[element.key()] = static_cast<double>(mob_attr[element.key()])
                                                    + static_cast<double>(item_attr[element.key()]);
                        }
                    }
                }
                // 检测力量buff
                if (mob->hasEffect(*MobEffect::getByName("strength"))) {
                    auto effectLevel           = mob->getEffect(*MobEffect::getByName("strength"))->mAmplifier + 1;
                    mob_attr["strength_level"] = effectLevel;
                }
                // 检测虚弱buff
                if (mob->hasEffect(*MobEffect::getByName("weakness"))) {
                    auto effectLevel           = mob->getEffect(*MobEffect::getByName("weakness"))->mAmplifier + 1;
                    mob_attr["weakness_level"] = effectLevel;
                }

                attacker_attr = mob_attr;
            }
        } else if (!source.has_value()) {
        }

        // 受伤的生物
        auto& mob = event.self();
        // 如果受伤实体为玩家
        if (mob.isPlayer()) {
            auto playerUniqueID = mob.getSourceUniqueID();
            auto player         = level->getPlayer(playerUniqueID);
            auto name           = player->getRealName();
            auto player_attr    = player_attr_data[name];
            // 检测抗性提升buff
            if (player->hasEffect(*MobEffect::getByName("resistance"))) {
                auto effectLevel = player->getEffect(*MobEffect::getByName("resistance"))->mAmplifier + 1;
                player_attr["resistance_level"] = effectLevel;
            }

            hurt_mob_attr = player_attr;
        } else {
            auto mob_attr = player_attr_data["default_attr"];
            for (auto equipment : mob.getAllEquipment()) {
                auto id        = equipment->getTypeName();
                auto item_attr = item_attr_data[id];
                for (auto& element : item_attr.items()) {
                    if (element.key().find("slot")) {
                    } else if (element.key().find("_rate") && element.key() != "crit_rate"
                               && element.key() != "hit_rate") {
                        mob_attr[element.key()] = static_cast<double>(mob_attr[element.key()]) - 1.0
                                                + static_cast<double>(item_attr[element.key()]);
                    } else {
                        mob_attr[element.key()] = static_cast<double>(mob_attr[element.key()])
                                                + static_cast<double>(item_attr[element.key()]);
                    }
                }
            }
            // 检测抗性提升buff
            if (mob.hasEffect(*MobEffect::getByName("resistance"))) {
                auto effectLevel             = mob.getEffect(*MobEffect::getByName("resistance"))->mAmplifier + 1;
                mob_attr["resistance_level"] = effectLevel;
            }

            hurt_mob_attr = mob_attr;
        }
        // 开始计算伤害值

        if (source.has_value()) {

            // 检测力量buff
            if (attacker_attr.value("strength_level", false)) {
                auto effectLevel = attacker_attr["strength_level"];

                double power = pow(1.3, effectLevel);
                damage       = power * damage + (power - 1.0) / 0.3;
            }
            // 检测虚弱buff
            if (attacker_attr.value("weakness_level", false)) {
                auto effectLevel = attacker_attr["weakness_level"];

                double power = pow(0.8, effectLevel);
                damage       = power * damage + (power - 1.0) / 0.4;
            }
        }
        // 修改伤害值
        event.value() = static_cast<float>(damage);
        // 修改伤害类型
        event.cause() = SharedTypes::Legacy::ActorDamageCause::SelfDestruct;
    },
    ll::event::EventPriority::Normal // 优先级
);

} // namespace cb