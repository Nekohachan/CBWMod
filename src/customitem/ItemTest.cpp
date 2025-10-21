#include "ItemTest.h"
#include "config/Config.h"
#include "mc/world/actor/RenderParams.h"
#include <mc/deps/shared_types/legacy/item/UseAnimation.h>
#include <mc/world/item/CameraItemComponentLegacy.h>
#include <mc/world/item/FoodItemComponentLegacy.h>
#include <mc/world/item/Item.h>
#include <mc/world/item/ItemStackBase.h>
#include <mc/world/item/ItemTag.h>
#include <mc/world/item/SeedItemComponentLegacy.h>
#include <mc/world/item/VanillaItemNames.h>
#include <mc/world/level/block/Block.h>
#include <modapi/item/CustomItemRegistry.h>
#include <modapi/item/base/ICustomArmorItem.h>
#include <modapi/item/base/ICustomItem.h>
#include <modapi/item/base/ICustomToolItem.h>
#include <modapi/item/types/DamageChance.h>
#include <modapi/item/types/ItemIcon.h>
#include <modapi/item/types/RepairItems.h>
#include <modapi/item/types/mc/HumanoidArmorItem.h>


Item::Item() = default;

BaseGameVersion::BaseGameVersion() = default;

using namespace cb;
using namespace modapi;


class Trident : public ICustomToolItem {
    TridentItem mOriginItem;

public:
    // 键名
    Trident() : ICustomToolItem("minecraft:trident"), mOriginItem() { setDescriptionId("trident"); };
    // 贴图
    ItemIcon getIcon() const override { return ItemIcon("trident"); }
    // 名字
    std::string getDisplayName() const override { return "item.trident.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 在创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }
    // 耐久
    short getItemDurability() const override { return 250; }
    //  物品标签
    std::vector<std::string> getItemTags() const override { return std::vector<std::string>{"minecraft:is_trident"}; }
    // 手持动作
    bool isHandEquipped() const override { return true; }

    void releaseUsing(::ItemStack& item, ::Player* player, int durationLeft) const override {
        return mOriginItem.releaseUsing(item, player, durationLeft);
    };

    bool
    dispense(::BlockSource& region, ::Container& container, int slot, ::Vec3 const& pos, uchar face) const override {
        return mOriginItem.dispense(region, container, slot, pos, face);
    };

    ItemStack& use(::ItemStack& instance, ::Player& player) const override {
        return mOriginItem.use(instance, player);
    };

    bool isThrowable() const override { return true; };

    void hurtActor(::ItemStack& item, ::Actor& actor, ::Mob& attacker) const override {
        return mOriginItem.hurtActor(item, actor, attacker);
    };
};

GMLIB_REGISTER_ITEM(Trident);