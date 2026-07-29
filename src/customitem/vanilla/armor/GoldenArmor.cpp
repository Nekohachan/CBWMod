#include "config/Config.h"
#include <mc/world/actor/RenderParams.h>
#include <mc/world/item/Item.h>
#include <mc/world/item/ItemStackBase.h>
#include <mc/world/item/enchanting/Enchant.h>
#include <modapi/item/CustomItemRegistry.h>
#include <modapi/item/base/ICustomArmorItem.h>
#include <modapi/item/types/DamageChance.h>
#include <modapi/item/types/ItemIcon.h>
#include <modapi/item/types/RepairItems.h>
#include <modapi/item/types/mc/HumanoidArmorItem.h>

using namespace cb;
using namespace modapi;

// 金头盔
class GoldenHelmet;
// 金胸甲
class GoldenChestplate;
// 金护腿
class GoldenLeggings;
// 金靴子
class GoldenBoots;

class GoldenHelmet : public ICustomArmorItem {
public:
    // 构造函数
    GoldenHelmet() : ICustomArmorItem("minecraft:golden_helmet", ICustomArmorItem::Tier::Gold) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("golden_helmet"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.golden_helmet.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.helmet"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 77; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:golden_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorHead; }

    // 附魔能力
    int getEnchantValue() const override { return 25; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Head; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipGold;
    }
};
class GoldenChestplate : public ICustomArmorItem {
public:
    // 构造函数
    GoldenChestplate() : ICustomArmorItem("minecraft:golden_chestplate", ICustomArmorItem::Tier::Gold) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("golden_chestplate"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.golden_chestplate.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.helmet"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 112; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:golden_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorTorso; }

    // 附魔能力
    int getEnchantValue() const override { return 25; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Torso; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipGold;
    }
};
class GoldenLeggings : public ICustomArmorItem {
public:
    // 构造函数
    GoldenLeggings() : ICustomArmorItem("minecraft:golden_leggings", ICustomArmorItem::Tier::Gold) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("golden_leggings"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.golden_leggings.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.leggings"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 105; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:golden_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorLegs; }

    // 附魔能力
    int getEnchantValue() const override { return 25; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Legs; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipGold;
    }
};
class GoldenBoots : public ICustomArmorItem {
public:
    // 构造函数
    GoldenBoots() : ICustomArmorItem("minecraft:golden_boots", ICustomArmorItem::Tier::Gold) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("golden_boots"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.golden_boots.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.boots"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 91; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:golden_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorFeet; }

    // 附魔能力
    int getEnchantValue() const override { return 25; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Feet; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipGold;
    }
};

// 物品注册
MODAPI_REGISTER_ITEM(GoldenHelmet);
MODAPI_REGISTER_ITEM(GoldenChestplate);
MODAPI_REGISTER_ITEM(GoldenLeggings);
MODAPI_REGISTER_ITEM(GoldenBoots);