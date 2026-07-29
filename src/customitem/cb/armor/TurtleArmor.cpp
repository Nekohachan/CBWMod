#include "config/Config.h"
#include <mc/world/actor/RenderParams.h>
#include <mc/world/item/Item.h>
#include <mc/world/item/ItemStackBase.h>
#include <mc/world/item/VanillaItemNames.h>
#include <mc/world/item/enchanting/Enchant.h>
#include <modapi/item/CustomItemRegistry.h>
#include <modapi/item/base/ICustomArmorItem.h>
#include <modapi/item/types/DamageChance.h>
#include <modapi/item/types/ItemIcon.h>
#include <modapi/item/types/RepairItems.h>
#include <modapi/item/types/mc/HumanoidArmorItem.h>

using namespace cb;
using namespace modapi;

// 海龟头盔
class TurtleHelmet;

class TurtleHelmet : public ICustomArmorItem {
public:
    // 构造函数
    TurtleHelmet() : ICustomArmorItem("minecraft:turtle_helmet", ICustomArmorItem::Tier::Turtle) {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("turtle_helmet"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.turtle_helmet.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 275; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Turtle, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_armor", "minecraft:trimmable_armors"};
        return tags;
    }

    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };

    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Head; }

    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipGeneric;
    }
};

// 物品注册
MODAPI_REGISTER_ITEM(TurtleHelmet);