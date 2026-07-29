#include "customitem/CustomCI.h"
#include "config/Config.h"
#include "mc/deps/nbt/CompoundTag.h"
#include <modapi/item/CustomCreativeItemRegistry.h>

namespace cb {

// 开服时创造背包注册
void RegistryCI() {
    cb::CreativeInventory::Config();
    auto config = cb::CreativeInventory::config;

    auto& registry = modapi::CustomCreativeItemRegistry::getInstance();

    // 注册物品分组
    for (auto& group : config.extra_groups) {
        registry.registerCreativeGroup(
            group.name,
            ItemInstance(group.icon),
            SharedTypes::CreativeItemCategory((int)group.category)
        );
    }

    // 注册创造背包物品
    for (auto& item : config.creative_items) {
        CompoundTag* nbt = nullptr;
        if (item.nbt) {
            if (auto userdata = CompoundTag::fromSnbt(*item.nbt)) {
                nbt = new CompoundTag(*userdata);
            }
        }
        registry.registerCreativeItem(
            ItemInstance(item.type, 1, 0, nbt),
            SharedTypes::CreativeItemCategory((int)item.category),
            item.group
        );
    }
}

// 关服时创造背包注销
void UnregistryCI() {
    cb::CreativeInventory::Config();
    auto config = cb::CreativeInventory::config;

    auto& registry = modapi::CustomCreativeItemRegistry::getInstance();
    // 注销创造背包物品
    for (auto& item : config.creative_items) {
        CompoundTag* nbt = nullptr;
        if (item.nbt) {
            if (auto userdata = CompoundTag::fromSnbt(*item.nbt)) {
                nbt = new ::CompoundTag(*userdata);
            }
        }
        auto itemstack = ::ItemInstance(item.type, 1, 0, nbt);

        auto category = SharedTypes::CreativeItemCategory((int)item.category);

        modapi::CustomCreativeItemRegistry::CreativeItem creative_item =
            {.mItem = itemstack, .mCategory = category, .mGroup = item.group};
        registry.unregisterCreativeItem(creative_item);
    }
}

} // namespace cb