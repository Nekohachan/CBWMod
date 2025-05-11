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

bool CreativeInventory() {
    // 读取配置文件
    struct CreativeInventoryConfig CreativeInventoryConfig;
    const auto&                    CreativeInventoryConfigPath =
        cb::Entry::getInstance().getSelf().getConfigDir() / "creative_inventory.json";
    if (!ll::config::loadConfig(CreativeInventoryConfig, CreativeInventoryConfigPath)) {
        cb::Entry::getInstance().getSelf().getLogger().warn(
            "Cannot load configurations from {}",
            CreativeInventoryConfigPath
        );
        cb::Entry::getInstance().getSelf().getLogger().info("Saving default configurations");

        if (!ll::config::saveConfig(CreativeInventoryConfig, CreativeInventoryConfigPath)) {
            cb::Entry::getInstance().getSelf().getLogger().error(
                "Cannot save default configurations to {}",
                CreativeInventoryConfigPath
            );
        }
    }

    auto& registry = gmlib::mod::CustomCreativeItemRegistry::getInstance();
    // 注册物品分组
    for (auto& group : CreativeInventoryConfig.item_groups) {
        registry
            .registerCreativeGroup(group.name, ::ItemInstance(group.icon), ::CreativeItemCategory((int)group.category));
    }

    // 注册创造背包物品
    for (auto& item : CreativeInventoryConfig.items) {
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
    }
    return true;
}


} // namespace cb