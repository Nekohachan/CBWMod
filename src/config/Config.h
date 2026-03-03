#pragma once
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace cb {

// 创造背包 -------------------------------------------------------------------------------------------------

enum class CreativeCategory {
    construction = 1,
    nature       = 2,
    equipment    = 3,
    items        = 4,
};

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


// 自定义物品 -------------------------------------------------------------------------------------------------

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

    std::vector<std::string> Copper = {
        "minecraft:copper_ingot",
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

    std::vector<std::string> Turtle = {
        "minecraft:turtle_scute",
    };
};

} // namespace cb