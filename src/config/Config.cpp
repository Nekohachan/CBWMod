#include "Config.h"
#include "Entry.h"
#include <ll/api/Config.h>
namespace cb {

// 自定义创造背包配置
CreativeInventory CreativeInventory::config;

bool CreativeInventory::Config() {
    auto& mSelf = cb::Entry::getInstance().getSelf();
    auto  path  = mSelf.getConfigDir() / "creative_inventory.json";
    return ll::config::loadConfig(config, path);
}

} // namespace cb