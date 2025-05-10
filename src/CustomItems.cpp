#include "Config.h"
#include "Entry.h"
// 导入自定义创造背包物品注册
#include <gmlib/mod/item/CustomCreativeItemRegistry.h>
// 导入自定义物品注册
#include <gmlib/mod/item/CustomItemRegistry.h>
// 导入自定义物品
#include <gmlib/mod/item/base/ICustomItem.h>
// 导入自定义护甲
#include <gmlib/mod/item/base/ICustomArmorItem.h>
#include <ll/api/Config.h>

namespace cb {

bool Entry::enable() {
    // 读取配置文件
    Config config;
    // CreativeInventory
    auto path = getSelf().getConfigDir() / u8"config.json";
    try {
        ll::config::loadConfig(config, path);
    } catch (...) {}
    ll::config::saveConfig(config, path);
    /* auto& registry = gmlib::mod::CustomCreativeItemRegistry::getInstance();

    // 注册物品分组
    for (auto& group : config.creative_inventory.item_groups) {
        registry
            .registerCreativeGroup(group.name, ::ItemInstance(group.icon), ::CreativeItemCategory((int)group.category));
    }

    // 注册创造背包物品
    for (auto& item : config.creative_inventory.items) {
        CompoundTag* nbt = nullptr;
        if (item.nbt) {
            if (auto userdata = ::CompoundTag::fromSnbt(*item.nbt)) {
                nbt = new ::CompoundTag(*userdata);
            }
        }
        registry.registerCreativeItem(
            ::ItemInstance(item.type, 1, 0, std::move(nbt)),
            ::CreativeItemCategory((int)item.category),
            item.group
        );
    } */
    return true;
}


} // namespace cb