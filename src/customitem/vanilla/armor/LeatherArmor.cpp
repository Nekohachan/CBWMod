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

// 皮革帽子
class LeatherHelmet;
// 皮革外套
class LeatherChestplate;
// 皮革裤子
class LeatherLeggings;
// 皮革靴子
class LeatherBoots;

class LeatherHelmet : public ICustomArmorItem {
public:
    // 构造函数
    LeatherHelmet() : ICustomArmorItem("minecraft:leather_helmet", ICustomArmorItem::Tier::Leather) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("leather_helmet"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.leather_helmet.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.helmet"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 55; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Leather, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:leather_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorHead; }

    // 附魔能力
    int getEnchantValue() const override { return 15; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Head; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipLeather;
    }
};
class LeatherChestplate : public ICustomArmorItem {
public:
    // 构造函数
    LeatherChestplate() : ICustomArmorItem("minecraft:leather_chestplate", ICustomArmorItem::Tier::Leather) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("leather_chestplate"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.leather_chestplate.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.chestplate"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 80; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Leather, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:leather_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorTorso; }

    // 附魔能力
    int getEnchantValue() const override { return 15; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Torso; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipLeather;
    }
};
class LeatherLeggings : public ICustomArmorItem {
public:
    // 构造函数
    LeatherLeggings() : ICustomArmorItem("minecraft:leather_leggings", ICustomArmorItem::Tier::Leather) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("leather_leggings"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.leather_leggings.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.leggings"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 75; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Leather, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:leather_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorLegs; }

    // 附魔能力
    int getEnchantValue() const override { return 15; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Legs; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipLeather;
    }
};
class LeatherBoots : public ICustomArmorItem {
public:
    // 构造函数
    LeatherBoots() : ICustomArmorItem("minecraft:leather_boots", ICustomArmorItem::Tier::Leather) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("leather_boots"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.leather_boots.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.boots"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 65; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Leather, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:leather_tier"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::ArmorFeet; }

    // 附魔能力
    int getEnchantValue() const override { return 15; }

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Feet; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipLeather;
    }
};

// 物品注册
MODAPI_REGISTER_ITEM(LeatherHelmet);
MODAPI_REGISTER_ITEM(LeatherChestplate);
MODAPI_REGISTER_ITEM(LeatherLeggings);
MODAPI_REGISTER_ITEM(LeatherBoots);