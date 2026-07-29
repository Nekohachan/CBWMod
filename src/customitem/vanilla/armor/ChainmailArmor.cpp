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

// 锁链头盔
class ChainmailHelmet;
// 锁链胸甲
class ChainmailChestplate;
// 锁链护腿
class ChainmailLeggings;
// 锁链靴子
class ChainmailBoots;

class ChainmailHelmet : public ICustomArmorItem {
public:
    // 构造函数
    ChainmailHelmet() : ICustomArmorItem("minecraft:chainmail_helmet", ICustomArmorItem::Tier::Chain) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("chainmail_helmet"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.chainmail_helmet.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.helmet"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 165; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:chainmail_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorHead; }

    // 附魔能力
    int getEnchantValue() const override { return 12; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Head; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipChain;
    }
};
class ChainmailChestplate : public ICustomArmorItem {
public:
    // 构造函数
    ChainmailChestplate() : ICustomArmorItem("minecraft:chainmail_chestplate", ICustomArmorItem::Tier::Chain) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("chainmail_chestplate"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.chainmail_chestplate.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.helmet"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 240; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:chainmail_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorTorso; }

    // 附魔能力
    int getEnchantValue() const override { return 12; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Torso; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipChain;
    }
};
class ChainmailLeggings : public ICustomArmorItem {
public:
    // 构造函数
    ChainmailLeggings() : ICustomArmorItem("minecraft:chainmail_leggings", ICustomArmorItem::Tier::Chain) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("chainmail_leggings"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.chainmail_leggings.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.leggings"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 225; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:chainmail_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorLegs; }

    // 附魔能力
    int getEnchantValue() const override { return 12; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Legs; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipChain;
    }
};
class ChainmailBoots : public ICustomArmorItem {
public:
    // 构造函数
    ChainmailBoots() : ICustomArmorItem("minecraft:chainmail_boots", ICustomArmorItem::Tier::Chain) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("chainmail_boots"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.chainmail_boots.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.boots"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 195; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:chainmail_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorFeet; }

    // 附魔能力
    int getEnchantValue() const override { return 12; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Feet; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipChain;
    }
};

// 物品注册
MODAPI_REGISTER_ITEM(ChainmailHelmet);
MODAPI_REGISTER_ITEM(ChainmailChestplate);
MODAPI_REGISTER_ITEM(ChainmailLeggings);
MODAPI_REGISTER_ITEM(ChainmailBoots);