#include "Entry.h"
#include <gmlib/gm/i18n/ResourceI18n.h>
#include <ll/api/mod/RegisterHelper.h>

namespace cb {

Entry& Entry::getInstance() {
    static Entry instance;
    return instance;
}

bool Entry::load() {
    getSelf().getLogger().info("CustomItems 已加载!");
    getSelf().getLogger().info("作者: Nekohachan");
    return true;
}

bool Entry::enable() { return true; }

bool Entry::disable() { return true; }

bool Entry::unload() { return true; }

} // namespace cb

LL_REGISTER_MOD(cb::Entry, cb::Entry::getInstance());