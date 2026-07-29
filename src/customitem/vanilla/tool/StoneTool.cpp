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

// 石剑
class StoneSword;
// 石斧
class StoneAxe;
// 石镐
class StonePickaxe;
// 石楸
class StoneShovel;
// 石锄
class StoneHoe;

class StoneSword : public ICustomToolItem {
public:
    // 构造函数
    StoneSword() : ICustomToolItem("minecraft:stone_sword") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("stone_sword"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.stone_sword.name"; }

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
    short getItemDurability() const override { return 131; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_sword", "minecraft:is_tool", "minecraft:digger", "minecraft:stone_tier"};
        return tags;
    }

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::Sword; }

    // 附魔能力
    int getEnchantValue() const override { return 5; }

    // 挖掘速度
    float getMiningSpeed() const override { return 4; }

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
class StoneAxe : public ICustomToolItem {
public:
    // 构造函数
    StoneAxe() : ICustomToolItem("minecraft:stone_axe") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("stone_axe"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.stone_axe.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.axe"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 131; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_axe", "minecraft:is_tool", "minecraft:digger", "minecraft:stone_tier"};
        return tags;
    }

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::Axe; }

    // 附魔能力
    int getEnchantValue() const override { return 5; }

    // 挖掘速度
    float getMiningSpeed() const override { return 4; }

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
class StonePickaxe : public ICustomToolItem {
public:
    // 构造函数
    StonePickaxe() : ICustomToolItem("minecraft:stone_pickaxe") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("stone_pickaxe"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.stone_pickaxe.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.pickaxe"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 131; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:digger", "minecraft:stone_tier"};
        return tags;
    }

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::Pickaxe; }

    // 附魔能力
    int getEnchantValue() const override { return 5; }

    // 挖掘速度
    float getMiningSpeed() const override { return 4; }

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
class StoneShovel : public ICustomToolItem {
public:
    // 构造函数
    StoneShovel() : ICustomToolItem("minecraft:stone_shovel") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("stone_shovel"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.stone_shovel.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.shovel"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 131; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_shovel", "minecraft:is_tool", "minecraft:digger", "minecraft:stone_tier"};
        return tags;
    }

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::Shovel; }

    // 附魔能力
    int getEnchantValue() const override { return 5; }

    // 挖掘速度
    float getMiningSpeed() const override { return 4; }

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
class StoneHoe : public ICustomToolItem {
public:
    // 构造函数
    StoneHoe() : ICustomToolItem("minecraft:stone_hoe") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("stone_hoe"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.stone_hoe.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.hoe"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 131; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_hoe", "minecraft:is_tool", "minecraft:digger", "minecraft:stone_tier"};
        return tags;
    }

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::Hoe; }

    // 附魔能力
    int getEnchantValue() const override { return 5; }

    // 挖掘速度
    float getMiningSpeed() const override { return 4; }

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

// 物品注册
MODAPI_REGISTER_ITEM(StoneSword);
MODAPI_REGISTER_ITEM(StoneAxe);
MODAPI_REGISTER_ITEM(StonePickaxe);
MODAPI_REGISTER_ITEM(StoneShovel);
MODAPI_REGISTER_ITEM(StoneHoe);