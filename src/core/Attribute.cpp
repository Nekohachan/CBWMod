#include "mc/world/attribute/Attribute.h"
#include "Attribute.h"
#include "LoreTest.h"
#include "config/Config.h"
#include "gmlib/mc/world/Level.h"
#include "gmlib/mc/world/actor/Player.h"
#include "helper/AttributeHelper.h"
#include "mc/deps/core/utility/MCRESULT.h"
#include "mc/entity/components/AttributesComponent.h"
#include "mc/world/actor/player/Player.h"
#include "mc/world/attribute/AttributeInstance.h"
#include "mc/world/attribute/AttributeInstanceConstRef.h"
#include "mc/world/attribute/AttributeInstanceHandle.h"
#include "mc/world/attribute/SharedAttributes.h"
#include "mc/world/effect/MobEffect.h"
#include "mc/world/effect/MobEffectInstance.h"
#include "mc/world/level/Level.h"
#include "mc/world/phys/HitResult.h"
#include "mc/world/phys/HitResultType.h"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <format>
#include <iomanip>
#include <nlohmann/json.hpp>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>


using json = nlohmann::json;

namespace cb {

#define logger cb::Entry::getInstance().getSelf().getLogger()

// ---------- 静态常量：属性关键词映射 ----------
static const std::unordered_map<std::string, std::string> ATTRIBUTE_KEYWORDS = {
    {"伤害减免",     "damage_reduction"         },
    {"格挡值",       "block"                    },
    {"移动速度",     "movement"                 },
    {"水下移速",     "underwater_movement"      },
    {"熔岩移速",     "lava_movement"            },
    {"血量上限",     "max_health"               },
    {"物理防御",     "defense"                  },
    {"魔法防御",     "magic_defense"            },
    {"锐伤防护",     "sharp_defense"            },
    {"钝伤防护",     "blunt_defense"            },
    {"结构强度",     "structure_defense"        },
    {"击退抗性",     "knockback_resistance"     },
    {"暴击概率",     "crit_rate"                },
    {"暴击伤害",     "cirtical_damage"          },
    {"攻击伤害",     "attack_damage"            },
    {"每格下落伤害", "falling_additional_damage"},
    {"攻击速度",     "attack_speed"             },
    {"冲刺倍率",     "charge_level"             },
    {"横扫范围",     "sweep_range"              },
    {"横扫倍率",     "sweep_damage"             },
    {"钝伤特化",     "blunt_level"              },
    {"锐伤特化",     "sharp_level"              },
    {"结构穿透",     "structure_level"          }
};

// ---------- 静态常量：正则表达式 ----------
static const std::regex PATTERN_PCT(R"(^x(\d+(?:\.\d+)?)\s+(\S+))");
static const std::regex PATTERN_FLAT(R"(^([+-]?\d+(?:\.\d+)?)\s+(\S+))");

// ---------- 清理 Lore 行：移除自定义标记 §ε 和所有标准格式码 ----------
static std::string cleanLoreLine(const std::string& line) {
    std::string result = line;

    // 1. 如果以 §ε 开头，移除该前缀（它是整体标记）
    static const std::string EPSILON_MARK = "§ε";
    size_t                   pos          = result.find(EPSILON_MARK);
    if (pos == 0) {
        result.erase(pos, EPSILON_MARK.length());
    }

    // 2. 移除所有标准格式码：§ + 一个 ASCII 字符（格式码）
    static const std::string SECTION = "§";
    size_t                   i       = 0;
    while (i < result.length()) {
        if (result.compare(i, SECTION.length(), SECTION) == 0) {
            // 删除 § 及其后的一个字节（标准格式码为 ASCII，占 1 字节）
            if (i + SECTION.length() + 1 <= result.length()) {
                result.erase(i, SECTION.length() + 1);
            } else {
                result.erase(i, SECTION.length());
            }
            // 继续从当前位置检查
        } else {
            ++i;
        }
    }
    return result;
}

// ---------- 属性合并函数 ----------
json& replaceProperties(json& target, const json& source) {
    if (!target.is_object() || !source.is_object()) return target;
    for (auto it = source.begin(); it != source.end(); ++it) {
        const auto& key = it.key();
        if (target.contains(key)) {
            target[key] = it.value();
        }
    }
    return target;
}

// ---------- 从物品描述提取属性 ----------
json& loreToAttr(ItemStack& item, const std::string& slot, json& attr) {
    // 1. 若传入物品为空，直接返回
    if (item.isNull()) {
        return attr;
    }

    // 2. 创建副本，后续操作全部使用副本
    ItemStack temp = item;

    // 3. 若物品类型在配置中存在，调用 LoreTest 修改副本
    if (!getItemAttrData()[temp.getTypeName()].empty()) {
        temp = LoreTest(temp, true); // LoreTest 返回 ItemStack
        if (temp.isNull()) {
            return attr;
        }
    }

    // 4. 获取副本的 Lore
    auto lore = temp.getCustomLore();
    if (lore.size() < 2) {
        // 没有足够描述行，直接返回（但注意，此时可能已被 LoreTest 修改，但无法提取属性）
        return attr;
    }

    // 5. 槽位关键词匹配
    std::string slotKeyword;
    if (slot == "main_hand") slotKeyword = "在主手时";
    else if (slot == "off_hand") slotKeyword = "在副手时";
    else if (slot == "head") slotKeyword = "戴在头上时";
    else if (slot == "torso") slotKeyword = "穿在身上时";
    else if (slot == "legs") slotKeyword = "穿在腿上时";
    else if (slot == "feet") slotKeyword = "穿在脚上时";
    else {
        return attr;
    }

    if (lore[1].find(slotKeyword) == std::string::npos) {
        return attr;
    }

    // 6. 解析所有行，提取属性
    for (const auto& line : lore) {
        std::string cleaned = cleanLoreLine(line);
        if (cleaned.empty()) continue;

        std::smatch match;
        if (std::regex_search(cleaned, match, PATTERN_PCT)) {
            double      value = std::stod(match[1].str());
            std::string id    = match[2].str();
            auto        it    = ATTRIBUTE_KEYWORDS.find(id);
            if (it != ATTRIBUTE_KEYWORDS.end()) {
                std::string key = it->second + "_pct";
                attr[key]       = attr.value(key, 0.0) + value - 1.0;
            }
        } else if (std::regex_search(cleaned, match, PATTERN_FLAT)) {
            double      value = std::stod(match[1].str());
            std::string id    = match[2].str();
            auto        it    = ATTRIBUTE_KEYWORDS.find(id);
            if (it != ATTRIBUTE_KEYWORDS.end()) {
                std::string key = it->second;
                attr[key]       = attr.value(key, 0.0) + value;
            }
        }
    }

    return attr;
}

// ---------- 攻击冷却计算 ----------
json attackCold(Player& player, json& attr) {
    auto  level = gmlib::GMLevel::getInstance();
    auto& pl    = static_cast<gmlib::GMPlayer&>(player);

    int haste = 0, mining_fatigue = 0;
    if (player.hasEffect(*MobEffect::getByName("haste"))) {
        haste = player.getEffect(*MobEffect::getByName("haste"))->mAmplifier + 1;
        if (haste > 5) haste = 5;
    }
    if (player.hasEffect(*MobEffect::getByName("mining_fatigue"))) {
        mining_fatigue = player.getEffect(*MobEffect::getByName("mining_fatigue"))->mAmplifier + 1;
        if (mining_fatigue > 5) mining_fatigue = 5;
    }

    double attack_speed = attr.value("attack_speed", 4.0);
    if (attack_speed == 0) {
        attack_speed = 4.0;
    }
    double attack_speed_pct  = attr.value("attack_speed_pct", 1.0);
    attack_speed            *= attack_speed_pct;
    attack_speed            += attack_speed * haste * 0.1 - attack_speed * mining_fatigue * 0.1;

    int cd_time;
    int cd = attr.value("atk_cd", 0);
    if (attack_speed <= 0) {
        attack_speed = 0;
        cd_time      = 1000;
    } else {
        cd_time = std::lround(20 / attack_speed);
        if (cd_time < 0) cd_time = 0;
    }

    if (player.hasTag("attack_cold")) {
        cd = cd_time;
        player.removeTag("attack_cold");
    }
    if (cd > cd_time) cd = cd_time;
    if (cd >= 1) --cd;

    attr["attack_speed"] = attack_speed;
    attr["atk_cd_time"]  = cd_time;
    attr["atk_cd"]       = cd;

    /* logger.info(
            "攻击冷却: 攻速={}, 急迫={}, 挖掘疲劳={}, 冷却总时长={}, 当前冷却={}",
            attack_speed,
            haste,
            mining_fatigue,
            cd_time,
            cd
        ); */

    // 同步冷却值到客户端
    level->executeCommandEx(
        std::format(
            "execute as \"{}\" at @s run scriptevent cb:player_set_attack_cold {}",
            player.getRealName(),
            std::lround(cd_time)
        )
    );

    // ---- 判断是否瞄准目标 ----
    bool      hasTarget = false;
    HitResult result    = player.traceRay(3.5, true, true);
    Actor*    entity    = result.getEntity();
    if (result.mType != HitResultType::NoHit && result.mType != HitResultType::Tile && entity) {
        if (entity != &player && entity->isAlive() && entity->hasFamily("mob")) {
            hasTarget = true;
        }
    }

    // ---- 冷却显示符号（十进制两位，范围 00~80） ----
    static const std::vector<std::string> ALL_SYMBOLS = [] {
        std::vector<std::string> symbols;
        symbols.reserve(81);
        for (int i = 0; i <= 80; ++i) {
            std::ostringstream oss;
            oss << "!jc." << std::setw(2) << std::setfill('0') << i; // 十进制
            symbols.push_back(oss.str());
        }
        return symbols;
    }();

    if (cd > 0) {
        // 冷却中：显示进度条（无视瞄准）
        double progress           = 1.0 - (double)cd / cd_time; // 0~1
        int    idx                = (int)std::round(progress * 80);
        idx                       = std::clamp(idx, 0, 80);
        const std::string& symbol = ALL_SYMBOLS[idx];
        pl.sendTitle(symbol);
        // logger.info("冷却进度: {:.2f}%, 符号={}", progress * 100, symbol);
    } else {
        // 冷却完成：根据瞄准显示指示器或空白
        if (hasTarget && cd_time > 0) {
            pl.sendTitle("!jc.81");
        } else {
            pl.sendTitle(" ");
        }
    }

    return attr;
}

// ---------- 属性实际设置到游戏 ----------
json attrSet(Player& player, json& attr, json& last_attr) {
    // logger.info("属性设置开始，玩家 {}", player.getRealName());

    // ---- 补全所有默认属性键，确保后续访问都有值 ----
    for (auto& [key, value] : defaultAttr.items()) {
        if (!attr.contains(key)) {
            attr[key] = value;
        }
    }
    auto& pl    = static_cast<gmlib::GMPlayer&>(player);
    int   speed = 0, slowness = 0;
    if (player.hasEffect(*MobEffect::getByName("speed"))) {
        speed = player.getEffect(*MobEffect::getByName("speed"))->mAmplifier + 1;
    }
    if (player.hasEffect(*MobEffect::getByName("slowness"))) {
        slowness = player.getEffect(*MobEffect::getByName("slowness"))->mAmplifier + 1;
    }

    // 移速
    {
        double movement         = attr["movement"].get<double>();
        double movement_pct     = attr["movement_pct"].get<double>();
        movement               += movement * 0.2 * speed - movement * 0.15 * slowness;
        movement               *= movement_pct;
        attr["movement_value"]  = movement;
        if (movement != last_attr["movement_value"]) {
            if (auto component = player.getEntityContext().tryGetComponent<AttributesComponent>()) {
                AttributeHelper::setDefaultValue(
                    component->mAttributes,
                    SharedAttributes::MOVEMENT_SPEED(),
                    static_cast<float>(movement)
                );
            }
            // logger.info("移速变化: 从 {} 变为 {}", last_attr["movement_value"].get<double>(), movement);
            last_attr["movement_value"] = movement;
        }
    }

    // 水下移速
    {
        double underwater_movement         = attr["underwater_movement"].get<double>();
        double underwater_movement_pct     = attr["underwater_movement_pct"].get<double>();
        underwater_movement               += underwater_movement * 0.2 * speed - underwater_movement * 0.15 * slowness;
        underwater_movement               *= underwater_movement_pct;
        attr["underwater_movement_value"]  = underwater_movement;
        if (underwater_movement != last_attr["underwater_movement_value"]) {
            if (auto component = player.getEntityContext().tryGetComponent<AttributesComponent>()) {
                AttributeHelper::setDefaultValue(
                    component->mAttributes,
                    SharedAttributes::UNDERWATER_MOVEMENT_SPEED(),
                    static_cast<float>(underwater_movement)
                );
            }
            /* logger.info(
                "水下移速变化: 从 {} 变为 {}",
                last_attr["underwater_movement_value"].get<double>(),
                underwater_movement
            ); */
            last_attr["underwater_movement_value"] = underwater_movement;
        }
    }

    // 熔岩移速
    {
        double lava_movement         = attr["lava_movement"].get<double>();
        double lava_movement_pct     = attr["lava_movement_pct"].get<double>();
        lava_movement               += lava_movement * 0.2 * speed - lava_movement * 0.15 * slowness;
        lava_movement               *= lava_movement_pct;
        attr["lava_movement_value"]  = lava_movement;
        if (lava_movement != last_attr["lava_movement_value"]) {
            if (auto component = player.getEntityContext().tryGetComponent<AttributesComponent>()) {
                AttributeHelper::setDefaultValue(
                    component->mAttributes,
                    SharedAttributes::LAVA_MOVEMENT_SPEED(),
                    static_cast<float>(lava_movement)
                );
            }
            // logger.info("熔岩移速变化: 从 {} 变为 {}", last_attr["lava_movement_value"].get<double>(),
            // lava_movement);
            last_attr["lava_movement_value"] = lava_movement;
        }
    }

    // 击退抗性
    {
        double knockback_resistance = attr["knockback_resistance"].get<double>();
        if (knockback_resistance != last_attr["knockback_resistance"]) {
            pl.setAttributeCurrent(SharedAttributes::KNOCKBACK_RESISTANCE(), static_cast<float>(knockback_resistance));
            /* logger.info(
                "击退抗性变化: 从 {} 变为 {}",
                last_attr["knockback_resistance"].get<double>(),
                knockback_resistance
            ); */
            last_attr["knockback_resistance"] = knockback_resistance;
        }
    }

    // 血量上限
    {
        double level     = player.getAttribute(Player::LEVEL()).mPtr->mCurrentValue;
        attr["level"]    = level;
        int health_boost = 0;
        if (player.hasEffect(*MobEffect::getByName("health_boost"))) {
            health_boost = player.getEffect(*MobEffect::getByName("health_boost"))->mAmplifier + 1;
        }
        double max_health        = attr["max_health"].get<double>();
        double max_health_pct    = attr["max_health_pct"].get<double>();
        double level_bonus       = std::min(5.0, std::round(0.5 * level));
        max_health               = (max_health + health_boost * 4 + level_bonus) * max_health_pct;
        attr["max_health_value"] = max_health;
        pl.setAttributeMax(SharedAttributes::HEALTH(), static_cast<float>(std::round(max_health)));
        // logger.info("血量上限设置为: {}", max_health);
    }

    return attr;
}

// ---------- 主循环：更新玩家属性 ----------
void ModifiedAttributeLoop(Player& player) {
    auto player_name = player.getRealName();
    // logger.info("属性更新循环: 正在更新玩家 {} 的属性", player_name);

    json player_attr = getPlayerAttrData().value(player_name, defaultAttr);
    if (!player_attr.is_object()) player_attr = defaultAttr;

    // 记录旧值（用于比较变化）
    json last_attr = {
        {"movement_value",            player_attr["movement_value"]           },
        {"underwater_movement_value", player_attr["underwater_movement_value"]},
        {"lava_movement_value",       player_attr["lava_movement_value"]      },
        {"knockback_resistance",      player_attr["knockback_resistance"]     }
    };

    // 补全缺失的默认属性
    player_attr = replaceProperties(player_attr, defaultAttr);

    // 各槽位物品属性提取
    auto main_hand = player.getEquippedSlot(SharedTypes::Legacy::EquipmentSlot::Mainhand);
    if (!main_hand.isNull()) player_attr = loreToAttr(main_hand, "main_hand", player_attr);

    auto off_hand = player.getEquippedSlot(SharedTypes::Legacy::EquipmentSlot::Offhand);
    if (!off_hand.isNull()) player_attr = loreToAttr(off_hand, "off_hand", player_attr);

    auto head = player.getEquippedSlot(SharedTypes::Legacy::EquipmentSlot::Head);
    if (!head.isNull()) player_attr = loreToAttr(head, "head", player_attr);

    auto torso = player.getEquippedSlot(SharedTypes::Legacy::EquipmentSlot::Torso);
    if (!torso.isNull()) player_attr = loreToAttr(torso, "torso", player_attr);

    auto legs = player.getEquippedSlot(SharedTypes::Legacy::EquipmentSlot::Legs);
    if (!legs.isNull()) player_attr = loreToAttr(legs, "legs", player_attr);

    auto feet = player.getEquippedSlot(SharedTypes::Legacy::EquipmentSlot::Feet);
    if (!feet.isNull()) player_attr = loreToAttr(feet, "feet", player_attr);

    // 攻击冷却
    player_attr = attackCold(player, player_attr);

    // 应用属性到游戏（内部会更新 last_attr 中的值）
    player_attr = attrSet(player, player_attr, last_attr);

    // 保存到文件
    modifyPlayerAttrData([&](json& data) { data[player_name] = player_attr; });

    // logger.info("属性更新循环: 玩家 {} 属性更新完成", player_name);
}

} // namespace cb