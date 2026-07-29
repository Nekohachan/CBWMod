#pragma once
#include "Entry.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include <vector>


using json = nlohmann::json;

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

const json& getBlockLootData();
const json& getPickaxeLevelData();
const json& getPlayerAttrData();
const json& getItemAttrData();
const json& getEntityLevelData();
const json& getEntityCritResistanceData();
const json& getBossBarData();
const json& getPlayData();


template <typename Func>
inline void modifyPlayerAttrData(Func&& modify) {
    json data;
    auto path = cb::Entry::getInstance().getSelf().getDataDir() / "player_attr.json";

    // 读取现有数据
    std::ifstream in(path);
    if (in) in >> data;
    else data = json::object();
    in.close();

    // 执行修改（传入 lambda）
    modify(data);

    // 写回文件
    std::ofstream out(path);
    if (out) out << data.dump(4);
}

template <typename Func>
inline void modifyBossBarData(Func&& modify) {
    json data;
    auto path = cb::Entry::getInstance().getSelf().getDataDir() / "bossbar_data.json";

    // 读取现有数据
    std::ifstream in(path);
    if (in) in >> data;
    else data = json::object();
    in.close();

    // 执行修改（传入 lambda）
    modify(data);

    // 写回文件
    std::ofstream out(path);
    if (out) out << data.dump(4);
}

template <typename Func>
inline void modifyPlayData(Func&& modify) {
    json data;
    auto path = cb::Entry::getInstance().getSelf().getDataDir() / "play_data.json";

    // 读取现有数据
    std::ifstream in(path);
    if (in) in >> data;
    else data = json::object();
    in.close();

    // 执行修改（传入 lambda）
    modify(data);

    // 写回文件
    std::ofstream out(path);
    if (out) out << data.dump(4);
}

// 默认属性表
inline json defaultAttr = {
    {"damage_reduction_pct",      1.0 },
    {"damage_reduction",          0   },
    {"block",                     0   },
    {"movement_pct",              1.0 },
    {"movement",                  0.1 },
    {"underwater_movement_pct",   1.0 },
    {"underwater_movement",       0.02},
    {"lava_movement_pct",         1.0 },
    {"lava_movement",             0.02},
    {"max_health_pct",            1.0 },
    {"max_health",                20  },
    {"defense_pct",               1   },
    {"defense",                   0   },
    {"magic_defense_pct",         1.0 },
    {"magic_defense",             0   },
    {"sharp_defense_pct",         1.0 },
    {"sharp_defense",             0   },
    {"blunt_defense_pct",         1.0 },
    {"blunt_defense",             0   },
    {"structure_defense_pct",     1.0 },
    {"structure_defense",         0   },
    {"knockback_resistance",      0   },
    {"crit_rate",                 0.02},
    {"cirtical_damage",           0.5 },
    {"attack_damage",             0   },
    {"attack_damage_pct",         1.0 },
    {"falling_additional_damage", 0   },
    {"attack_speed",              0   },
    {"attack_speed_pct",          1.0 },
    {"charge_level",              0   },
    {"sweep_range",               0   },
    {"sweep_damage",              0   },
    {"blunt_level_pct",           1.0 },
    {"blunt_level",               0   },
    {"sharp_level_pct",           1.0 },
    {"sharp_level",               0   },
    {"structure_level_pct",       1.0 },
    {"structure_level",           0   },
    {"level",                     0   },
    {"crit_resistance",           0   }
};

inline json defaultBossBarData = {
    {"version",     1   },
    {"main_switch", true},
    {"time",        true},
    {"play_time",   true},
    {"ping",        true},
    {"tps",         true},
    {"block_value", true}
};


inline json defaultPlayData = {
    {"last_join",        ""},
    {"last_left",        ""},
    {"last_playing",     ""},
    {"play_time",        0 },
    {"play_time_tick",   0 },
    {"play_time_second", 0 }
};

inline json defaultBlockAttr = {
    {"vulnerability_level",       0.0},
    {"vulnerability_level_timer", 0.0},
    {"block_value",               0.0},
    {"max_block_value",           0.0},
    {"TrPrecondition",            0.0},
    {"block_value_recover_timer", 0.0},
    {"block_value_overrun_timer", 0.0}
};

inline json defaultRegenTimer = {
    {"sneak_regen", 0},
    {"ride_regen",  0},
    {"sleep_regen", 0}
};


} // namespace cb