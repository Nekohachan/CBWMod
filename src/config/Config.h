#pragma once
#include "include.h"
#include <optional>
#include <string>
#include <vector>


namespace cb {

// 这里用小写，保持和Addon一致
enum class CreativeCategory {
    construction = 1,
    nature       = 2,
    equipment    = 3,
    items        = 4,
};

// 创造背包注册配置
struct CIConfig {
    // 配置文件版本号
    int version = 2;
    // 注册创造背包物品
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

    std::vector<ItemGroup> extra_groups = {
        ItemGroup{
                  .name     = "itemGroup.name.test",
                  .icon     = "minecraft:command_block",
                  .category = CreativeCategory::equipment
        }
    };
    std::vector<Items> creative_items = {
        Items{
              .type     = "minecraft:netherite_sword",
              .category = CreativeCategory::equipment,
              .group    = "itemGroup.name.test",
              .nbt      = "{\"Unbreakable\":1b,\"display\":{\"Lore\":[\"§r§9不可破坏§r\",\"§r§e测试§r\"],\"Name\":"
                        "\"§r§d32K下界合金剑§r\"},\"ench\":"
                        "[{\"id\":"
                        "9s,"
                        "\"lvl\":32767s},{\"id\":13s,\"lvl\":32767s},{\"id\":14s,\"lvl\":100s},{\"id\":17s,"
                        "\"lvl\":32767s},"
                        "{"
                        "\"id\":12s,\"lvl\":32767s},{\"id\":26s,\"lvl\":32767s},{\"id\":10s,\"lvl\":32767s},{"
                        "\"id\":11s,"
                        "\"lvl\":32767s}],\"keep_on_death\":1b}"
        },
        Items{
              .type     = "minecraft:command_block",
              .category = CreativeCategory::equipment,
              .group    = "itemGroup.name.test"
        },
        Items{.type = "minecraft:barrier", .category = CreativeCategory::equipment, .group = "itemGroup.name.test"}
    };
    static CIConfig config;
    static bool     TryLoad();
    static bool     TrySave();
};

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

    std::vector<std::string> Gold = {
        "minecraft:gold_ingot",
    };
};

} // namespace cb