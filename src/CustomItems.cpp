#include "Gloabl.h"
#include "CustomItems.h"
#include "Config.h"
// 导入自定义创造背包物品注册
#include <gmlib/mod/item/CustomCreativeItemRegistry.h>
// 导入自定义物品注册
#include <gmlib/mod/item/CustomItemRegistry.h>
// 导入自定义物品
#include <gmlib/mod/item/base/ICustomItem.h>
// 导入自定义护甲
#include <gmlib/mod/item/base/ICustomArmorItem.h>
#include <ll/api/Config.h>
#include <ll/api/mod/RegisterHelper.h>

namespace cb {

CustomItems& CustomItems::getInstance() {
    static CustomItems instance;
    return instance;
}

bool CustomItems::load() { return true; }

bool CustomItems::enable() {
    // 设置配置文件位置
    auto path = getSelf().getConfigDir() / u8"config.json";
    // 获取配置文件结构
    Config config;
    try {
        // 加载配置文件
        ll::config::loadConfig(config, path);
    } catch (...) {}
    // 保存配置文件
    ll::config::saveConfig(config, path);

    // 自定义创造背包物品注册API
    auto& registry = gmlib::mod::CustomCreativeItemRegistry::getInstance();

    for (auto& group : config.extra_groups) {
        registry
            .registerCreativeGroup(group.name, ::ItemInstance(group.icon), ::CreativeItemCategory((int)group.category));
    }

    for (auto& item : config.creative_items) {
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
    getSelf().getLogger().info("CustomItems 已加载!");
    getSelf().getLogger().info("作者: Nekohachan");
    return true;
}


CustomItems&          getInstance() { return CustomItems::getInstance(); }
ll::mod::Mod&   getSelfMod() { return getInstance().getSelf(); }
ll::io::Logger& getLogger() { return getSelfMod().getLogger(); }
bool CustomItems::disable() { return true; }

} // namespace cb

// 注册插件
LL_REGISTER_MOD(cb::CustomItems, cb::CustomItems::getInstance());
