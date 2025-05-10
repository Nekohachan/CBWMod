#pragma once
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

struct Config {
    // 配置文件版本号
    int version = 1;
    // 注册创造背包物品
    struct CreativeInventory {
        // 物品分组
        struct ItemGroup {
            // 分组名称
            std::string name;
            // 分组使用的贴图
            std::string icon;
            // 分组所属类型
            CreativeCategory category;
        } item_groups;
        // 物品条目
        struct Items {
            std::string                type;
            CreativeCategory           category;
            std::string                group;
            std::optional<std::string> nbt;
        } items;
    } creative_inventory;

    std::vector<CreativeInventory::ItemGroup> item_groups = {
        {.name = "itemGroup.name.test", .icon = "minecraft:command_block", .category = CreativeCategory::equipment}
    };
    std::vector<CreativeInventory::Items> items = {
        {.type     = "minecraft:netherite_sword",
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
                     "\"lvl\":32767s}],\"keep_on_death\":1b}"}
    };
};

} // namespace cb