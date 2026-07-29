#include "config/Config.h"
#include <mc/world/actor/RenderParams.h>
#include <mc/world/item/Item.h>
#include <mc/world/item/ItemStackBase.h>
#include <mc/world/item/enchanting/Enchant.h>
#include <mc/world/level/block/Block.h>
#include <modapi/item/CustomItemRegistry.h>
#include <modapi/item/base/ICustomItem.h>
#include <modapi/item/base/ICustomToolItem.h>
#include <modapi/item/types/DamageChance.h>
#include <modapi/item/types/ItemIcon.h>
#include <modapi/item/types/RepairItems.h>


using namespace cb;
using namespace modapi;

class GoldenSword;
class GoldenAxe;
class GoldenPickaxe;
class GoldenShovel;
class GoldenHoe;

class GoldenSword : public ICustomToolItem {
public:
    // 构造函数
    GoldenSword() : ICustomToolItem("minecraft:golden_sword") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("golden_sword"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.golden_sword.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.sword"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }

    // 耐久度
    short getItemDurability() const override { return 32; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_sword", "minecraft:is_tool", "minecraft:digger", "minecraft:golden_tier"};
        return tags;
    }

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::Sword; }

    // 附魔能力
    int getEnchantValue() const override { return 22; }

    // 挖掘速度
    float getMiningSpeed() const override { return 12; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_sword_item_destructible")) {
            return true;
        }
        return false;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }
};
class GoldenAxe : public ICustomToolItem {
public:
    // 构造函数
    GoldenAxe() : ICustomToolItem("minecraft:golden_axe") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("golden_axe"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.golden_axe.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.axe"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 32; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_axe", "minecraft:is_tool", "minecraft:digger", "minecraft:golden_tier"};
        return tags;
    }

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::Axe; }

    // 附魔能力
    int getEnchantValue() const override { return 22; }

    // 挖掘速度
    float getMiningSpeed() const override { return 12; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_axe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }
};
class GoldenPickaxe : public ICustomToolItem {
public:
    // 构造函数
    GoldenPickaxe() : ICustomToolItem("minecraft:golden_pickaxe") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("golden_pickaxe"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.golden_pickaxe.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.pickaxe"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 32; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:digger", "minecraft:golden_tier"};
        return tags;
    }

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::Pickaxe; }

    // 附魔能力
    int getEnchantValue() const override { return 22; }

    // 挖掘速度
    float getMiningSpeed() const override { return 12; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        if ((block.hasTag("minecraft:is_pickaxe_item_destructible")
             || block.hasTag("minecraft:stone_tier_destructible"))
            && (!block.hasTag("minecraft:iron_tier_destructible")
                && !block.hasTag("minecraft:diamond_tier_destructible") && !block.hasTag("cb:Level_5_destructible")
                && !block.hasTag("cb:Level_6_destructible") && !block.hasTag("cb:Level_6_destructible")
                && !block.hasTag("cb:Level_7_destructible"))) {
            return true;
        }
        return false;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }
};
class GoldenShovel : public ICustomToolItem {
public:
    // 构造函数
    GoldenShovel() : ICustomToolItem("minecraft:golden_shovel") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("golden_shovel"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.golden_shovel.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.shovel"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 32; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_shovel", "minecraft:is_tool", "minecraft:digger", "minecraft:golden_tier"};
        return tags;
    }

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::Shovel; }

    // 附魔能力
    int getEnchantValue() const override { return 22; }

    // 挖掘速度
    float getMiningSpeed() const override { return 12; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_shovel_item_destructible")) {
            return true;
        }
        return false;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }
};
class GoldenHoe : public ICustomToolItem {
public:
    // 构造函数
    GoldenHoe() : ICustomToolItem("minecraft:golden_hoe") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("golden_hoe"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.golden_hoe.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.hoe"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 32; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_hoe", "minecraft:is_tool", "minecraft:digger", "minecraft:golden_tier"};
        return tags;
    }

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::Hoe; }

    // 附魔能力
    int getEnchantValue() const override { return 22; }

    // 挖掘速度
    float getMiningSpeed() const override { return 12; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_hoe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }
};

MODAPI_REGISTER_ITEM(GoldenSword);
MODAPI_REGISTER_ITEM(GoldenAxe);
MODAPI_REGISTER_ITEM(GoldenPickaxe);
MODAPI_REGISTER_ITEM(GoldenShovel);
MODAPI_REGISTER_ITEM(GoldenHoe);