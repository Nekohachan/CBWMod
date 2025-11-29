#include "Config.h"
#include "Entry.h"
#include <ll/api/Config.h>

namespace cb {

// 自定义创造背包配置
CreativeInventory CreativeInventory::config;

bool CreativeInventory::Config() {
    auto& mSelf = cb::Entry::getInstance().getSelf();
    auto  path  = mSelf.getConfigDir() / "creative_inventory.json";
    bool  ok    = ll::config::loadConfig(config, path);
    return ok;
}


// 物品属性
Attributes Attributes::config;

bool Attributes::Config() {
    auto& mSelf = cb::Entry::getInstance().getSelf();
    auto  path  = mSelf.getConfigDir() / "item_attr.json";
    bool  ok    = ll::config::loadConfig(config, path);
    return ok;
}


} // namespace cb