#pragma once
#include "include.h"
#include <map>
#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include <vector>

namespace cb {


using json = nlohmann::json;

// 修复材料品质列表
struct RepairMaterials {
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
        "minecraft:gold_ingout",
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

    // 获取对应材料的修复物品列表
    std::vector<std::string> getRepairMaterials(const std::string& materialType) const {
        if (materialType == "Wooden") return Wooden;
        if (materialType == "Stone") return Stone;
        if (materialType == "Iron") return Iron;
        if (materialType == "Golden") return Golden;
        if (materialType == "Diamond") return Diamond;
        if (materialType == "Netherite") return Netherite;
        if (materialType == "Mace") return Mace;
        if (materialType == "Leather") return Leather;
        return {};
    }
};

// 战斗属性结构体
struct ItemCombatAttributes {
    // 攻击伤害
    float attack_damage = 0.0f;
    // 攻击速度
    float attack_speed = 0.0f;
    // 横扫范围
    float sweep_range = 0.0f;
    // 横扫倍率
    float sweep_damage = 0.0f;

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
        // 使用 value() 提供默认值，而不是 at() 避免异常
        attr.attack_damage = j.value("attack_damage", 0.0f);
        attr.attack_speed  = j.value("attack_speed", 0.0f);
        attr.sweep_range   = j.value("sweep_range", 0.0f);
        attr.sweep_damage  = j.value("sweep_damage", 0.0f);
    }
};

// 玩家属性
struct PlayerAttributes {
    // 攻击力
    int attack = 0;
    // 暴击率
    float crit_rate = 0.0f;
    // 暴击伤害
    float critical_damage = 0.0f;
    // 命中率
    float hit_rate = 0.0f;
    // 血量上限
    int health = 0;
    // 物理防御力
    int defense = 0;
    // 魔法防御力
    int magic_defense = 0;
    // 百分比减伤
    float percentage_damage_reduction = 0.0f;
    // 固定减伤
    float flat_damage_reduction = 0.0f;
    // 闪避率
    float avoid_rate = 0.0f;
    // 格挡率
    float blocking_rate = 0.0f;
    // 击退抗性
    float knockback_resistance = 0.0f;
    // 移速
    float movement = 0.0f;
    // 水下移速
    float water_movement = 0.0f;
    // 熔岩移速
    float lava_movement = 0.0f;

    // 添加 to_json 函数
    friend void to_json(json& j, const PlayerAttributes& attr) {
        j = json{
            {"attack",                      attr.attack                     },
            {"crit_rate",                   attr.crit_rate                  },
            {"critical_damage",             attr.critical_damage            },
            {"hit_rate",                    attr.hit_rate                   },
            {"health",                      attr.health                     },
            {"defense",                     attr.defense                    },
            {"magic_defense",               attr.magic_defense              },
            {"percentage_damage_reduction", attr.percentage_damage_reduction},
            {"flat_damage_reduction",       attr.flat_damage_reduction      },
            {"avoid_rate",                  attr.avoid_rate                 },
            {"blocking_rate",               attr.blocking_rate              },
            {"knockback_resistance",        attr.knockback_resistance       },
            {"movement",                    attr.movement                   },
            {"water_movement",              attr.water_movement             },
            {"lava_movement",               attr.lava_movement              }
        };
    }

    // 添加 from_json 函数
    friend void from_json(const json& j, PlayerAttributes& attr) {
        // 使用 value() 提供默认值，而不是 at() 避免异常
        attr.attack                      = j.value("attack", 0);
        attr.crit_rate                   = j.value("crit_rate", 0.0f);
        attr.critical_damage             = j.value("critical_damage", 0.0f);
        attr.hit_rate                    = j.value("hit_rate", 0.0f);
        attr.health                      = j.value("health", 0);
        attr.defense                     = j.value("defense", 0);
        attr.magic_defense               = j.value("magic_defense", 0);
        attr.percentage_damage_reduction = j.value("percentage_damage_reduction", 0.0f);
        attr.flat_damage_reduction       = j.value("flat_damage_reduction", 0.0f);
        attr.avoid_rate                  = j.value("avoid_rate", 0.0f);
        attr.blocking_rate               = j.value("blocking_rate", 0.0f);
        attr.knockback_resistance        = j.value("knockback_resistance", 0.0f);
        attr.movement                    = j.value("movement", 0.0f);
        attr.water_movement              = j.value("water_movement", 0.0f);
        attr.lava_movement               = j.value("lava_movement", 0.0f);
    }
};

// 物品其他属性
struct ItemOther {
    // 可烧制多少物品
    float furnace_burn_interval = 0.0f;
    // 是否有手持动作
    bool is_hand_equipped = false;
    // 创造下是否能破坏方块
    bool can_destroy_in_creative = true;
    // 标签数组
    std::vector<std::string> tags;

    // 添加 to_json 函数
    friend void to_json(json& j, const ItemOther& item_other) {
        j = json{
            {"furnace_burn_interval",   item_other.furnace_burn_interval  },
            {"is_hand_equipped",        item_other.is_hand_equipped       },
            {"can_destroy_in_creative", item_other.can_destroy_in_creative},
            {"tags",                    item_other.tags                   }
        };
    }

    // 添加 from_json 函数
    friend void from_json(const json& j, ItemOther& item_other) {
        // 使用 value() 提供默认值，而不是 at() 避免异常
        item_other.furnace_burn_interval   = j.value("furnace_burn_interval", 0.0f);
        item_other.is_hand_equipped        = j.value("is_hand_equipped", false);
        item_other.can_destroy_in_creative = j.value("can_destroy_in_creative", true);

        // 解析标签数组
        if (j.contains("tags")) {
            j.at("tags").get_to(item_other.tags);
        } else {
            item_other.tags.clear();
        }
    }
};

// 物品挖矿属性
struct ItemMiner {
    // 挖掘速度
    int mining_speed = 0;
    // 可破坏的标签
    std::string can_destroy_tag = "empty";

    // 添加 to_json 函数
    friend void to_json(json& j, const ItemMiner& item_miner) {
        j = json{
            {"mining_speed",    item_miner.mining_speed   },
            {"can_destroy_tag", item_miner.can_destroy_tag}
        };
    }

    // 添加 from_json 函数
    friend void from_json(const json& j, ItemMiner& item_miner) {
        // 使用 value() 提供默认值，而不是 at() 避免异常
        item_miner.mining_speed    = j.value("mining_speed", 0);
        item_miner.can_destroy_tag = j.value("can_destroy_tag", "empty");
    }
};

// 物品结构体
struct Item {
    // 物品名称
    std::string name = "empty";
    // 物品贴图
    std::string icon = "empty";
    // 物品最大堆叠数
    int max_stack_size = 64;
    // 物品耐久
    int durability = 0;
    // 修复材料品质
    std::string repair_material = "empty";
    // 物品其他属性
    ItemOther item_other;
    // 物品战斗相关属性
    ItemCombatAttributes item_combat_attributes;
    // 物品玩家相关属性
    PlayerAttributes player_attributes;
    // 物品挖矿属性
    ItemMiner item_miner;

    // 添加 to_json 函数
    friend void to_json(json& j, const Item& item) {
        j = json{
            {"name",                   item.name                  },
            {"icon",                   item.icon                  },
            {"max_stack_size",         item.max_stack_size        },
            {"durability",             item.durability            },
            {"repair_material",        item.repair_material       },
            {"item_other",             item.item_other            },
            {"item_combat_attributes", item.item_combat_attributes},
            {"player_attributes",      item.player_attributes     },
            {"item_miner",             item.item_miner            }
        };
    }

    // 添加 from_json 函数
    friend void from_json(const json& j, Item& item) {
        // 使用 value() 提供默认值，而不是 at() 避免异常
        item.name            = j.value("name", "empty");
        item.icon            = j.value("icon", "empty");
        item.max_stack_size  = j.value("max_stack_size", 64);
        item.durability      = j.value("durability", 0);
        item.repair_material = j.value("repair_material", "empty");

        // 对于嵌套对象，检查是否存在，如果存在则解析
        if (j.contains("item_other")) {
            j.at("item_other").get_to(item.item_other);
        }

        if (j.contains("item_combat_attributes")) {
            j.at("item_combat_attributes").get_to(item.item_combat_attributes);
        }

        if (j.contains("player_attributes")) {
            j.at("player_attributes").get_to(item.player_attributes);
        }

        if (j.contains("item_miner")) {
            j.at("item_miner").get_to(item.item_miner);
        }
    }

    // 获取修复物品列表（固定修复四分之一耐久度）
    std::vector<std::pair<std::string, float>> getRepairItems(const RepairMaterials& materials) const {
        std::vector<std::pair<std::string, float>> result;

        // 如果没有指定修复材料，返回空列表
        if (repair_material.empty()) {
            return result;
        }

        // 计算修复量（固定为耐久度的四分之一）
        float repairAmount = static_cast<float>(durability) / 4.0f;

        // 获取对应材料的修复物品列表
        auto repairMaterials = materials.getRepairMaterials(repair_material);
        for (const auto& material : repairMaterials) {
            result.emplace_back(material, repairAmount);
        }

        return result;
    }
    // 便捷访问函数 - 类似于 JavaScript 的对象属性访问

    // 获取标签数组
    std::vector<std::string> getTags() const { return item_other.tags; }

    // 获取战斗属性（返回引用，允许修改）
    ItemCombatAttributes&       combat() { return item_combat_attributes; }
    const ItemCombatAttributes& combat() const { return item_combat_attributes; }

    // 获取玩家属性（返回引用，允许修改）
    PlayerAttributes&       player() { return player_attributes; }
    const PlayerAttributes& player() const { return player_attributes; }

    // 获取矿工属性（返回引用，允许修改）
    ItemMiner&       miner() { return item_miner; }
    const ItemMiner& miner() const { return item_miner; }

    // 获取其他属性（返回引用，允许修改）
    ItemOther&       other() { return item_other; }
    const ItemOther& other() const { return item_other; }

    // 获取特定战斗属性的便捷函数
    float getAttackDamage() const { return item_combat_attributes.attack_damage; }
    float getAttackSpeed() const { return item_combat_attributes.attack_speed; }
    float getSweepRange() const { return item_combat_attributes.sweep_range; }
    float getSweepDamage() const { return item_combat_attributes.sweep_damage; }

    // 获取特定玩家属性的便捷函数
    int   getPlayerAttack() const { return player_attributes.attack; }
    float getPlayerCritRate() const { return player_attributes.crit_rate; }
    int   getPlayerHealth() const { return player_attributes.health; }
    int   getPlayerDefense() const { return player_attributes.defense; }

    // 获取特定矿工属性的便捷函数
    int         getMiningSpeed() const { return item_miner.mining_speed; }
    std::string getCanDestroyTag() const { return item_miner.can_destroy_tag; }

    // 获取特定其他属性的便捷函数
    float getFurnaceBurnInterval() const { return item_other.furnace_burn_interval; }
    bool  isHandEquipped() const { return item_other.is_hand_equipped; }
    bool  canDestroyInCreative() const { return item_other.can_destroy_in_creative; }

    // 获取物品的显示名称（带格式）
    std::string getDisplayName() const { return name; }

    // 获取最大堆叠大小
    int getMaxStackSize() const { return max_stack_size; }
};

// 顶层结构体
struct ItemCollection {
    int                         version = 1;
    std::map<std::string, Item> items;            // 使用map存储物品，键名为物品ID

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
        // 使用 value() 提供默认值，而不是 at() 避免异常
        collection.version = j.value("version", 1);

        // 遍历所有键值对，跳过"version"键
        for (auto it = j.begin(); it != j.end(); ++it) {
            if (it.key() != "version") {
                collection.items[it.key()] = it.value().get<Item>();
            }
        }
    }

    static ItemCollection config;
    static bool           Config();
};


// 模组配置文件 -------------------------------------------------------------------------------------------------

struct ModConfig {
    int version = 2;
    //  语言文件路径
    std::string lang_path;

    static ModConfig config;
    static bool      Config();
};


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

} // namespace cb