#include "Config.h"
#include "Entry.h"
#include "ll/api/Config.h"

namespace cb {

// 自定义物品配置相关
ItemConfig ItemConfig::config;

bool ItemConfig::TryLoad() {
    auto&      mSelf = cb::Entry::getInstance().getSelf();
    const auto path  = mSelf.getModDir() / "config/custom_item.json";

    bool ok = ll::config::loadConfig(config, path);

    if (!ok) {
        CIConfig::TrySave();
    }
    return ok;
}

bool ItemConfig::TrySave() {
    auto&      mSelf = cb::Entry::getInstance().getSelf();
    const auto path  = mSelf.getModDir() / "config/custom_item.json";

    return ll::config::saveConfig(config, path);
}

// 自定义创造背包配置相关
CIConfig CIConfig::config;

bool CIConfig::TryLoad() {
    auto&      mSelf = cb::Entry::getInstance().getSelf();
    const auto path  = mSelf.getModDir() / "config/creative_inventory.json";

    bool ok = ll::config::loadConfig(config, path);

    if (!ok) {
        CIConfig::TrySave();
    }
    return ok;
}

bool CIConfig::TrySave() {
    auto&      mSelf = cb::Entry::getInstance().getSelf();
    const auto path  = mSelf.getModDir() / "config/creative_inventory.json";

    return ll::config::saveConfig(config, path);
}

} // namespace cb