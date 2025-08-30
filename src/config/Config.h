#pragma once
#include "include.h"
#include <optional>
#include <string>
#include <vector>


namespace cb {

enum class CreativeCategory {
    construction = 1,
    nature       = 2,
    equipment    = 3,
    items        = 4,
};

// 物品配置文件
struct ItemConfig {
    int version = 2;
    struct item {
        // 物品名称[键名]
        std::string name;
        // 物品使用的贴图
        std::string icon;
        // 分组所属类型
        CreativeItemCategory item_category;
        struct ItemAttackAttributes {
            // 攻击伤害
            float attack_damage;
            // 攻击速度
            float attack_speed;
            // 横扫范围
            float sweep_range;
            // 横扫伤害
            float sweep_damage;
        };
        struct ItemOtherAttributes {
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
    };

    static ItemConfig config;
    static bool       Config();
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