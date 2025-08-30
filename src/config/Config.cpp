#include "Config.h"
#include "Entry.h"
#include "ll/api/Config.h"

namespace cb {

// 模组配置
ModConfig ModConfig::config;

bool ModConfig::Config() {
    auto& mSelf = cb::Entry::getInstance().getSelf();
    auto  path  = mSelf.getConfigDir() / "config.json";
    bool  ok    = ll::config::loadConfig(config, path);
    return ok;
}

// 自定义创造背包配置
CreativeInventory CreativeInventory::config;

bool CreativeInventory::Config() {
    auto& mSelf = cb::Entry::getInstance().getSelf();
    auto  path  = mSelf.getConfigDir() / "creative_inventory.json";
    bool  ok    = ll::config::loadConfig(config, path);
    return ok;
}

// 自定义物品配置
ItemCollection ItemCollection::config;

bool ItemCollection::Config() {
    auto& mSelf = cb::Entry::getInstance().getSelf();
    auto  path  = mSelf.getConfigDir() / "item.json";
    bool  ok    = ll::config::loadConfig(config, path);
    return ok;
}


} // namespace cb