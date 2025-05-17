#include "CustomItems.h"
#include "Config.h"
#include "mc/world/item/Item.h"
#include <gmlib/mod/item/CustomCreativeItemRegistry.h>
#include <gmlib/mod/item/CustomItemRegistry.h>
#include <gmlib/mod/item/base/ICustomArmorItem.h>
#include <gmlib/mod/item/base/ICustomItem.h>
#include <mc/deps/core/string/HashedString.h>
#include <mc/world/item/VanillaItemNames.h>


namespace cb {

// 创造背包注册
void RegistryCI() {
    cb::CIConfig::TryLoad();
    auto config = cb::CIConfig::config;

    auto& registry = gmlib::mod::CustomCreativeItemRegistry::getInstance();

    // 注册物品分组
    for (auto& group : config.extra_groups) {
        registry
            .registerCreativeGroup(group.name, ::ItemInstance(group.icon), ::CreativeItemCategory((int)group.category));
    }

    // 注册创造背包物品
    for (auto& item : config.creative_items) {
        CompoundTag* nbt = nullptr;
        if (item.nbt) {
            if (auto userdata = ::CompoundTag::fromSnbt(*item.nbt)) {
                nbt = new ::CompoundTag(*userdata);
            }
        }
        registry.registerCreativeItem(
            ::ItemInstance(item.type, 1, 0, nbt),
            ::CreativeItemCategory((int)item.category),
            item.group
        );
    }
}

// 覆写原版物品
using namespace gmlib::mod;

// 木剑
class WoodenSword : public ICustomItem {
public:
    WoodenSword() : ICustomItem(VanillaItemNames::WoodenSword()) {};

    ItemIcon getIcon() const override { return "wood_sword"; }

    std::string getDisplayName() const override { return "item.wooden_sword.name"; }
};

GMLIB_REGISTER_ITEM(WoodenSword);

} // namespace cb