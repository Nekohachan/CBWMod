#pragma once
#include <gmlib/mod/item/types/DamageChance.h>
#include <gmlib/mod/item/types/ItemIcon.h>
#include <gmlib/mod/item/types/RepairItems.h>
#include <mc/deps/shared_types/legacy/item/UseAnimation.h>
#include <mc/nbt/CompoundTag.h>
#include <mc/world/item/Item.h>
#include <mc/world/item/Rarity.h>
#include <mc/world/item/enchanting/Enchant.h>
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

struct ItemConfig {
    // 配置文件版本号
    int version = 2;
    // 注册自定义物品
    // 物品配置
    struct Items {
        // 信息部分 ----------------------------------------

        // 物品键名
        std::string id;

        // 物品贴图
        gmlib::mod::ItemIcon icon;

        // 物品名称
        std::string name;

        // 物品所属分类
        std::optional<CreativeCategory> category;

        // 物品所在的组
        std::optional<std::string> group;

        // 物品标签
        std::optional<std::vector<std::string>> item_tag;

        // 常用部分 ----------------------------------------

        // 最大堆叠
        int max_stack;

        // 是否允许副手手持
        bool allow_off_hand;

        // 是否自带附魔光泽
        std::optional<bool> is_foil;

        // 物品最大耐久
        std::optional<short> durability;

        // 物品损耗概率
        std::optional<gmlib::mod::DamageChance> damage_change;

        // 铁砧修复相关
        std::optional<std::vector<gmlib::mod::RepairItems>> repair_items;

        // 使用动画
        std::optional<SharedTypes::Legacy::UseAnimation> use_animation;

        // 使用时间
        std::optional<int> use_duration;

        //

        // 非常用 ----------------------------------------

        // 是否会被爆炸破坏
        std::optional<bool> is_explodable;

        // 是否会被火焰破坏
        std::optional<bool> is_fire_resistant;

        // 是否会自然消失
        std::optional<bool> should_despawn;

        // 在物品栏显示动画(搭配贴图帧数)
        std::optional<bool> animates_in_tool_bar;

        // 贴图帧数(搭配在物品栏显示动画)
        std::optional<int> frame_count;
    };

    struct Armor {
        // 物品键名
        std::string id;
        // 物品贴图
        std::string icon;
        // 物品名称
        std::string name;
    };


    std::vector<Items> items = {Items{}};
    std::vector<Armor> armor = {Armor{}};


    static ItemConfig config;
    static bool       TryLoad();
    static bool       TrySave();
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

} // namespace cb