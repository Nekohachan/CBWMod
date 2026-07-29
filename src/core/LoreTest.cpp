#include "LoreTest.h"
#include "config/Config.h"
#include "gmlib/mc/world/CompoundTag.h"
#include "gmlib/mc/world/ItemStack.h"
#include "ila/event/minecraft/world/actor/player/PlayerOpenContainerEvent.h"
#include "ll/api/event/EventBus.h"
#include "ll/api/service/Bedrock.h"
#include "mc/deps/shared_types/legacy/ContainerType.h"
#include "mc/legacy/ActorUniqueID.h"
#include "mc/server/ServerPlayer.h"
#include "mc/world/Container.h"
#include "mc/world/actor/player/Inventory.h"
#include "mc/world/actor/player/Player.h"
#include "mc/world/item/ItemStack.h"
#include "mc/world/item/enchanting/EnchantUtils.h"
#include "mc/world/level/BlockSource.h"
#include "mc/world/level/Level.h"
#include "mc/world/level/block/actor/BlockActor.h"
#include "mc/world/level/dimension/Dimension.h"
#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>


using json = nlohmann::json;

namespace cb {

#define logger cb::Entry::getInstance().getSelf().getLogger()

// ---------- 静态常量 ----------
static const std::string SECTION_SIGN = "§"; // UTF-8 编码的 § 符号

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

// 往每个字符前加上 §（直接插入 UTF-8 编码）
std::string addSymbolBeforeEachChar(const std::string& str) {
    std::string result;
    result.reserve(str.size() * 3);
    for (char c : str) {
        // 插入 § 的 UTF-8 字节序列（0xC2 0xA7）
        result.push_back(char(0xC2));
        result.push_back(char(0xA7));
        result.push_back(c);
    }
    return result;
}

// 格式化数值
std::string formatNumber(double value) {
    std::string str = std::to_string(value);
    size_t      dot = str.find('.');
    if (dot == std::string::npos) {
        return str + ".0";
    }
    size_t end = str.size() - 1;
    while (end > dot + 1 && str[end] == '0') {
        --end;
    }
    if (end == dot) {
        return str.substr(0, dot + 1) + "0";
    }
    return str.substr(0, end + 1);
}

// 替换物品
ItemStack replaceItem(ItemStack& item) {
    gmlib::GMItemStack it(item); // 使用构造函数
    auto               nbt = it.getNbt();
    if (nbt && nbt->mTags.contains("tag")) {
        auto& tag = nbt->at("tag").get<CompoundTag>(); // 引用避免拷贝
        if (tag.mTags.contains("ench")) {
            auto& ench = tag.at("ench").get<ListTag>(); // 引用以便修改列表
            for (auto index = ench.size(); index > 0; --index) {
                auto& enchantment = ench.at(index - 1).get<CompoundTag>(); // 引用，只读
                short enchant_id  = enchantment.at("id").get<ShortTag>().data;
                switch (enchant_id) {
                case 9:  // 锋利
                case 10: // 亡灵杀手
                case 11: // 节肢杀手
                case 29: // 穿刺
                case 39: // 致密
                case 40: // 破甲
                    ench.erase(ench.begin() + (index - 1));
                    break;
                default:
                    break;
                }
            }
            if (ench.size() == 0) {
                tag.erase("ench");
            }
            it.setNbt(*nbt); // 解引用指针
            item = it;       // 更新原物品
        }
    }

    if (item.getTypeName() == "minecraft:enchanted_book" && nbt && nbt->mTags.contains("tag")
        && !nbt->at("tag").get<CompoundTag>().mTags.contains("ench")) {
        item.reinit("minecraft:book", 1, 0);
    }

    if (item.getTypeName() == "minecraft:shield") {
        item = ItemStack::EMPTY_ITEM();
    }
    return item;
}

// 处理单个物品的描述更新
ItemStack LoreTest(ItemStack& item, bool ignore_version) {
    item = replaceItem(item);

    auto item_type = item.getTypeName();

    const auto& itemAttrData = cb::getItemAttrData();
    if (!itemAttrData.contains(item_type)) {
        return item;
    }

    auto        item_lore      = item.getCustomLore();
    const auto& attr           = itemAttrData[item_type];
    int         configVersion  = itemAttrData.value("version", 0);
    int         currentVersion = 0;

    // 解析已有版本号（从第一行提取）
    if (!item_lore.empty()) {
        std::string firstLine = item_lore[0];
        // 移除所有 § 字符（注意 UTF-8 多字节，需删除整个子串）
        size_t pos = 0;
        while ((pos = firstLine.find(SECTION_SIGN, pos)) != std::string::npos) {
            firstLine.erase(pos, SECTION_SIGN.length());
        }
        if (firstLine.compare(0, 7, "version") == 0) {
            try {
                currentVersion = std::stoi(firstLine.substr(7));
            } catch (...) {
                currentVersion = 0;
            }
        }
    }

    bool shouldUpdate = item_lore.empty() || currentVersion < configVersion;
    if (!ignore_version) {
        if (!shouldUpdate) {
            return item;
        }
    }

    // ---------- 1. 提取已有的特殊描述（以 §ε 开头） ----------
    std::unordered_map<std::string, std::string> extractedAttributes;
    std::vector<std::string>                     originalLore;

    auto startsWithSectionEpsilon = [](const std::string& s) -> bool { return s.rfind("§ε", 0) == 0; };

    for (const auto& lore : item_lore) {
        if (startsWithSectionEpsilon(lore)) {
            bool isAttributeLine = false;
            for (const auto& [keyword, baseAttr] : ATTRIBUTE_KEYWORDS) {
                if (lore.find(keyword) != std::string::npos) {
                    if (lore.find('x') != std::string::npos) {
                        extractedAttributes[baseAttr + "_pct"] = lore;
                    } else {
                        extractedAttributes[baseAttr] = lore;
                    }
                    isAttributeLine = true;
                    break;
                }
            }
            if (!isAttributeLine) {
                originalLore.push_back(lore);
            }
        }
    }

    // ---------- 2. 构建新描述 ----------
    std::vector<std::string> newLore;

    // 2.1 版本号行
    std::string versionStr = "version" + std::to_string(configVersion);
    newLore.push_back(addSymbolBeforeEachChar(versionStr));

    // 2.2 槽位描述
    if (attr.contains("slot")) {
        std::string slot = attr["slot"];
        if (slot == "mainhand") newLore.push_back("§r§7在主手时 ：");
        else if (slot == "offhand") newLore.push_back("§r§7在副手时 ：");
        else if (slot == "head") newLore.push_back("§r§7戴在头上时 ：");
        else if (slot == "torso") newLore.push_back("§r§7穿在身上时 ：");
        else if (slot == "legs") newLore.push_back("§r§7穿在腿上时 ：");
        else if (slot == "feet") newLore.push_back("§r§7穿在脚上时 ：");
    }

    auto getLoreLine = [&](const std::string& attrKey,
                           const std::string& displayName,
                           bool               isPercent = false) -> std::optional<std::string> {
        auto it = extractedAttributes.find(attrKey);
        if (it != extractedAttributes.end()) {
            return it->second;
        }
        if (attr.contains(attrKey)) {
            std::string valueStr;
            const auto& val = attr[attrKey];
            if (val.is_number_integer() || val.is_number_float()) {
                double numVal = val.get<double>();
                valueStr      = formatNumber(numVal);
                if (!isPercent && numVal > 0.0) {
                    valueStr = "+" + valueStr;
                }
            } else {
                valueStr = val.get<std::string>();
            }
            std::string prefix = isPercent ? "§r§2x" : "§r§2";
            return prefix + valueStr + " " + displayName;
        }
        return std::nullopt;
    };

    auto addLine = [&](const std::string& attrKey, const std::string& displayName, bool isPercent) {
        auto line = getLoreLine(attrKey, displayName, isPercent);
        if (line) {
            newLore.push_back(*line);
        }
    };

    // 按顺序添加所有属性（顺序已保证）
    addLine("damage_reduction_pct", "伤害减免", true);
    addLine("damage_reduction", "伤害减免", false);
    addLine("block", "格挡值", false);
    addLine("movement_pct", "移动速度", true);
    addLine("movement", "移动速度", false);
    addLine("underwater_movement_pct", "水下移速", true);
    addLine("underwater_movement", "水下移速", false);
    addLine("lava_movement_pct", "熔岩移速", true);
    addLine("lava_movement", "熔岩移速", false);
    addLine("max_health_pct", "血量上限", true);
    addLine("max_health", "血量上限", false);
    addLine("defense_pct", "物理防御", true);
    addLine("defense", "物理防御", false);
    addLine("magic_defense_pct", "魔法防御", true);
    addLine("magic_defense", "魔法防御", false);
    addLine("sharp_defense_pct", "锐伤防护", true);
    addLine("sharp_defense", "锐伤防护", false);
    addLine("blunt_defense_pct", "钝伤防护", true);
    addLine("blunt_defense", "钝伤防护", false);
    addLine("structure_defense_pct", "结构强度", true);
    addLine("structure_defense", "结构强度", false);
    addLine("knockback_resistance", "击退抗性", false);
    addLine("crit_rate", "暴击概率", false);
    addLine("cirtical_damage", "暴击伤害", false);
    addLine("attack_damage", "攻击伤害", false);
    addLine("attack_damage_pct", "攻击伤害", true);
    addLine("falling_additional_damage", "每格下落伤害", false);
    addLine("attack_speed", "攻击速度", false);
    addLine("attack_speed_pct", "攻击速度", true);
    addLine("charge_level", "冲刺倍率", false);
    addLine("sweep_range", "横扫范围", false);
    addLine("sweep_damage", "横扫倍率", false);
    addLine("blunt_level_pct", "钝伤特化", true);
    addLine("blunt_level", "钝伤特化", false);
    addLine("sharp_level_pct", "锐伤特化", true);
    addLine("sharp_level", "锐伤特化", false);
    addLine("structure_level_pct", "结构穿透", true);
    addLine("structure_level", "结构穿透", false);

    if (attr.contains("lore")) {
        auto& lore = attr["lore"];
        newLore.insert(newLore.end(), lore.begin(), lore.end());
    }

    if (!originalLore.empty()) {
        newLore.insert(newLore.end(), originalLore.begin(), originalLore.end());
    }

    item.setCustomLore(newLore);
    return item;
}

// 无视版本检查
int LoreTestIgnoreVersion;

// 玩家背包物品描述检测循环
void LoreTestLoop(Player& player) {
    ++LoreTestIgnoreVersion;
    bool modified = false;

    // 辅助 lambda：处理容器内单个物品（自动写回）
    auto processItemInContainer = [&](Container& container, int slot, const std::string& location) {
        const ItemStack& current = container.getItem(slot);
        if (current.isNull()) return;
        try {
            ItemStack copy     = current;
            ItemStack new_item = LoreTest(copy, false);
            if (LoreTestIgnoreVersion >= 10) {
                new_item = LoreTest(new_item, true);
            }
            if (!(current == new_item)) {
                container.setItem(slot, new_item);
                modified = true;
            }
        } catch (const std::exception& e) {
            logger.error("处理玩家 {} {} 第 {} 格异常: {}", player.getRealName(), location, slot, e.what());
        } catch (...) {
            logger.error("处理玩家 {} {} 第 {} 格未知异常", player.getRealName(), location, slot);
        }
    };

    // ---- 1. 处理主背包（36格） ----
    auto& inventory = player.getInventory();
    inventory.createTransactionContext(
        [](Container&, int, const ItemStack&, const ItemStack&) {},
        [&]() {
            for (int i = 0; i < inventory.getContainerSize(); ++i) {
                processItemInContainer(inventory, i, "背包");
            }
        }
    );

    // ---- 2. 处理装备槽（副手 + 盔甲） ----
    std::vector<std::pair<SharedTypes::Legacy::EquipmentSlot, std::string>> equipSlots = {
        {SharedTypes::Legacy::EquipmentSlot::Offhand, "副手"},
        {SharedTypes::Legacy::EquipmentSlot::Head,    "头盔"},
        {SharedTypes::Legacy::EquipmentSlot::Torso,   "胸甲"},
        {SharedTypes::Legacy::EquipmentSlot::Legs,    "护腿"},
        {SharedTypes::Legacy::EquipmentSlot::Feet,    "靴子"}
    };

    for (auto& [slot, name] : equipSlots) {
        const ItemStack& current = player.getEquippedSlot(slot);
        if (current.isNull()) continue;
        try {
            ItemStack copy     = current;
            ItemStack new_item = LoreTest(copy, false);
            if (LoreTestIgnoreVersion >= 10) {
                new_item = LoreTest(new_item, true);
            }
            if (!(current == new_item)) {
                player.setEquippedSlot(slot, new_item);
                modified = true;
            }
        } catch (const std::exception& e) {
            logger.error("处理玩家 {} {} 槽异常: {}", player.getRealName(), name, e.what());
        } catch (...) {
            logger.error("处理玩家 {} {} 槽未知异常", player.getRealName(), name);
        }
    }

    // ---- 3. 重置版本计数器并刷新 ----
    if (LoreTestIgnoreVersion >= 10) {
        LoreTestIgnoreVersion = 0;
    }

    if (modified) {
        player.refreshInventory();
    }
}

// 判断容器类型是否为方块容器
bool isBlockContainerType(SharedTypes::Legacy::ContainerType type) {
    switch (type) {
    case SharedTypes::Legacy::ContainerType::Container:
    case SharedTypes::Legacy::ContainerType::Furnace:
    case SharedTypes::Legacy::ContainerType::BlastFurnace:
    case SharedTypes::Legacy::ContainerType::Smoker:
    case SharedTypes::Legacy::ContainerType::Dispenser:
    case SharedTypes::Legacy::ContainerType::Dropper:
    case SharedTypes::Legacy::ContainerType::Hopper:
        return true;
    default:
        return false;
    }
}

// 监听玩家打开容器事件，自动更新容器内物品描述
auto LoreTestContainer = ll::event::EventBus::getInstance().emplaceListener<ila::mc::PlayerOpenContainerAfterEvent>(
    [](ila::mc::PlayerOpenContainerAfterEvent& event) {
        auto& player        = event.self();
        auto  containerType = event.containerType();
        if (isBlockContainerType(containerType)) {
            auto  pos        = event.containerBlockPos();
            auto& dimension  = player.getDimension();
            auto& region     = dimension.getBlockSourceFromMainChunkSource();
            auto* blockActor = region.getBlockEntity(pos);

            if (!blockActor) return;
            Container* container = blockActor->getContainer();
            if (!container) return;

            container->createTransactionContext(
                [](Container&, int, const ItemStack&, const ItemStack&) {},
                [&]() {
                    for (int i = 0; i < container->getContainerSize(); ++i) {
                        const ItemStack& current = container->getItem(i);
                        if (!current.isNull()) {
                            try {
                                ItemStack item_copy = current;
                                ItemStack new_item  = LoreTest(item_copy, false);
                                if (!(current == new_item)) {
                                    container->setItem(i, new_item);
                                }
                            } catch (const std::exception& e) {
                                logger.error("处理容器 {} 第 {} 格物品时异常: {}", pos.toString(), i, e.what());
                            } catch (...) {
                                logger.error("处理容器 {} 第 {} 格物品时发生未知异常", pos.toString(), i);
                            }
                        }
                    }
                }
            );
        };
    }
);

} // namespace cb