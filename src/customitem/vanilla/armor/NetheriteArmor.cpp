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

// 下界合金头盔
class NetheriteHelmet;
// 下界合金胸甲
class NetheriteChestplate;
// 下界合金护腿
class NetheriteLeggings;
// 下界合金靴子
class NetheriteBoots;

class NetheriteHelmet : public ICustomArmorItem {
public:
    // 构造函数
    NetheriteHelmet() : ICustomArmorItem("minecraft:netherite_helmet", ICustomArmorItem::Tier::Netherite) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("netherite_helmet"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.netherite_helmet.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.helmet"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 407; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:netherite_tier"};
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
        return SharedTypes::Legacy::LevelSoundEvent::EquipNetherite;
    }

    // 防火属性
    bool isFireResistant() const override { return true; }
};
class NetheriteChestplate : public ICustomArmorItem {
public:
    // 构造函数
    NetheriteChestplate() : ICustomArmorItem("minecraft:netherite_chestplate", ICustomArmorItem::Tier::Netherite) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("netherite_chestplate"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.netherite_chestplate.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.helmet"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 592; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:netherite_tier"};
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
        return SharedTypes::Legacy::LevelSoundEvent::EquipNetherite;
    }

    // 防火属性
    bool isFireResistant() const override { return true; }
};
class NetheriteLeggings : public ICustomArmorItem {
public:
    // 构造函数
    NetheriteLeggings() : ICustomArmorItem("minecraft:netherite_leggings", ICustomArmorItem::Tier::Netherite) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("netherite_leggings"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.netherite_leggings.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.leggings"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 555; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:netherite_tier"};
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
        return SharedTypes::Legacy::LevelSoundEvent::EquipNetherite;
    }

    // 防火属性
    bool isFireResistant() const override { return true; }
};
class NetheriteBoots : public ICustomArmorItem {
public:
    // 构造函数
    NetheriteBoots() : ICustomArmorItem("minecraft:netherite_boots", ICustomArmorItem::Tier::Netherite) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("netherite_boots"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.netherite_boots.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.boots"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 481; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags =
            {"minecraft:is_armor", "minecraft:trimmable_armors", "minecraft:netherite_tier"};
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
        return SharedTypes::Legacy::LevelSoundEvent::EquipNetherite;
    }

    // 防火属性
    bool isFireResistant() const override { return true; }
};

// 物品注册
MODAPI_REGISTER_ITEM(NetheriteHelmet);
MODAPI_REGISTER_ITEM(NetheriteChestplate);
MODAPI_REGISTER_ITEM(NetheriteLeggings);
MODAPI_REGISTER_ITEM(NetheriteBoots);