#pragma once
#include "include.h"
#include <map>
#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include <vector>

using json = nlohmann::json;

namespace cb {

// 战斗属性结构体
struct ItemCombatAttributes {
    float attack_damage;
    float attack_speed;
    float sweep_range;
    float sweep_damage;

    // 添加 to_json 函数以便序列化
    friend void to_json(json& j, const ItemCombatAttributes& attr) {
        j = json{
            {"attack_damage", attr.attack_damage},
            {"attack_speed",  attr.attack_speed },
            {"sweep_range",   attr.sweep_range  },
            {"sweep_damage",  attr.sweep_damage }
        };
    }

    // 添加 from_json 函数以便反序列化
    friend void from_json(const json& j, ItemCombatAttributes& attr) {
        j.at("attack_damage").get_to(attr.attack_damage);
        j.at("attack_speed").get_to(attr.attack_speed);
        j.at("sweep_range").get_to(attr.sweep_range);
        j.at("sweep_damage").get_to(attr.sweep_damage);
    }
};


// 物品结构体
struct Item {
    std::string          name;
    std::string          icon;
    ItemCombatAttributes item_combat_attributes;

    // 添加 to_json 函数
    friend void to_json(json& j, const Item& item) {
        j = json{
            {"name",                   item.name                  },
            {"icon",                   item.icon                  },
            {"item_combat_attributes", item.item_combat_attributes}
        };
    }

    // 添加 from_json 函数
    friend void from_json(const json& j, Item& item) {
        j.at("name").get_to(item.name);
        j.at("icon").get_to(item.icon);
        j.at("item_combat_attributes").get_to(item.item_combat_attributes);
    }
};

// 顶层结构体
struct ItemCollection {
    int                         version;
    std::map<std::string, Item> items; // 使用map存储物品，键名为物品ID

    // 添加 to_json 函数
    friend void to_json(json& j, const ItemCollection& collection) {
        j = json{
            {"version", collection.version}
        };

        // 将每个物品添加到JSON对象中
        for (const auto& pair : collection.items) {
            j[pair.first] = pair.second;
        }
    }

    // 添加 from_json 函数
    friend void from_json(const json& j, ItemCollection& collection) {
        j.at("version").get_to(collection.version);

        // 遍历所有键值对，跳过"version"键
        for (auto it = j.begin(); it != j.end(); ++it) {
            if (it.key() != "version") {
                collection.items[it.key()] = it.value().get<Item>();
            }
        }
    }
    static ItemCollection    config;
    static bool              Config();
};


enum class CreativeCategory {
    construction = 1,
    nature       = 2,
    equipment    = 3,
    items        = 4,
};


// 插件配置文件

struct ModConfig {
    int version = 2;
    //  语言文件路径
    std::string lang_path;

    static ModConfig config;
    static bool      Config();
};


// 修复所需物品
struct RepairItemsList {
    std::vector<std::string> Wooden = {
        "minecraft:oak_planks",
        "minecraft:spruce_planks",
        "minecraft:birch_planks",
        "minecraft:jungle_planks",
        "minecraft:acacia_planks",
        "minecraft:dark_oak_planks",
        "minecraft:mangrove_planks",
        "minecraft:cherry_planks",
        "minecraft:pale_oak_planks",
        "minecraft:bamboo_planks",
        "minecraft:crimson_planks",
        "minecraft:warped_planks",
    };

    std::vector<std::string> Stone = {
        "minecraft:cobblestone",
        "minecraft:cobbled_deepslate",
        "minecraft:blackstone",
    };

    std::vector<std::string> Iron = {
        "minecraft:iron_ingot",
    };

    std::vector<std::string> Golden = {
        "minecraft:gold_ingot",
    };

    std::vector<std::string> Diamond = {
        "minecraft:diamond",
    };

    std::vector<std::string> Netherite = {
        "minecraft:netherite_ingot",
    };

    std::vector<std::string> Mace = {
        "minecraft:breeze_rod",
    };

    std::vector<std::string> Leather = {
        "minecraft:leather",
    };
};

// 玩家属性
struct PlayerAttributes {
    // 攻击力
    int attack;
    // 暴击率
    float crit_rate;
    // 暴击伤害
    float critical_damage;
    // 命中率
    float hit_rate;
    // 血量上限
    int health;
    // 物理防御力
    int defense;
    // 魔法防御力
    int magic_defense;
    // 百分比减伤
    float percentage_damage_reduction;
    // 固定减伤
    float flat_damage_reduction;
    // 闪避率
    float avoid_rate;
    // 格挡率
    float blocking_rate;
    // 击退抗性
    float knockback_resistance;
    // 移速
    float movement;
    // 水下移速
    float water_movement;
    // 熔岩移速
    float lava_movement;
};

// 创造背包 -------------------------------------------------------------------------------------------------


// 创造背包注册配置
struct CreativeInventory {
    int version = 2;
    // 物品分组
    struct ItemGroup {
        // 分组名称
        std::string name;
        // 分组使用的贴图
        std::string icon;
        // 分组所属类型
        CreativeCategory category;
    };
    // 物品条目
    struct Items {
        // 物品的键名
        std::string type;
        // 物品所属分类
        CreativeCategory category;
        // 物品所在的组
        std::string group;
        // 物品自带的NBT
        std::optional<std::string> nbt;
    };

    std::vector<ItemGroup>   extra_groups   = {};
    std::vector<Items>       creative_items = {};
    static CreativeInventory config;
    static bool              Config();
};

} // namespace cb