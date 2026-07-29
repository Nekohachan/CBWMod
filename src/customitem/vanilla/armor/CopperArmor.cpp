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

// 铜头盔
class CopperHelmet;
// 铜胸甲
class CopperChestplate;
// 铜护腿
class CopperLeggings;
// 铜靴子
class CopperBoots;

class CopperHelmet : public ICustomArmorItem {
public:
    // 构造函数
    CopperHelmet() : ICustomArmorItem("minecraft:copper_helmet", ICustomArmorItem::Tier::Copper) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("copper_helmet"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.copper_helmet.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.helmet"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 121; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Copper, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:copper_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorHead; }

    // 附魔能力
    int getEnchantValue() const override { return 8; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Head; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipCopper;
    }
};
class CopperChestplate : public ICustomArmorItem {
public:
    // 构造函数
    CopperChestplate() : ICustomArmorItem("minecraft:copper_chestplate", ICustomArmorItem::Tier::Copper) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("copper_chestplate"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.copper_chestplate.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.helmet"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 176; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Copper, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:copper_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorTorso; }

    // 附魔能力
    int getEnchantValue() const override { return 8; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Torso; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipCopper;
    }
};
class CopperLeggings : public ICustomArmorItem {
public:
    // 构造函数
    CopperLeggings() : ICustomArmorItem("minecraft:copper_leggings", ICustomArmorItem::Tier::Copper) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("copper_leggings"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.copper_leggings.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.leggings"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 165; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Copper, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:copper_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorLegs; }

    // 附魔能力
    int getEnchantValue() const override { return 8; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Legs; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipCopper;
    }
};
class CopperBoots : public ICustomArmorItem {
public:
    // 构造函数
    CopperBoots() : ICustomArmorItem("minecraft:copper_boots", ICustomArmorItem::Tier::Copper) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("copper_boots"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.copper_boots.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.boots"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 143; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Copper, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:copper_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorFeet; }

    // 附魔能力
    int getEnchantValue() const override { return 8; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Feet; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipCopper;
    }
};

// 物品注册
MODAPI_REGISTER_ITEM(CopperHelmet);
MODAPI_REGISTER_ITEM(CopperChestplate);
MODAPI_REGISTER_ITEM(CopperLeggings);
MODAPI_REGISTER_ITEM(CopperBoots);