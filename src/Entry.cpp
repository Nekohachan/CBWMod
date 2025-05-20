#include "Entry.h"
#include "CustomItems.h"
#include <gmlib/gm/i18n/ResourceI18n.h>
#include <ll/api/mod/RegisterHelper.h>

namespace cb {

Entry& Entry::getInstance() {
    static Entry instance;
    return instance;
}

bool Entry::load() {
    //加载语言文件
    auto version  = getSelf().getManifest().version.value_or(ll::data::Version{0, 0, 0});
    auto resource = gmlib::i18n::ResourceI18n(
        getSelf().getModDir(),
        getSelf().getName(),
        version.major,
        version.minor,
        version.patch
    );
    resource.addLanguagesFromDirectory(getSelf().getLangDir());
    resource.loadAllLanguages();
    //加载完成提示
    getSelf().getLogger().info("CustomItems 已加载!");
    getSelf().getLogger().info("作者: Nekohachan");
    return true;
}

bool Entry::enable() {
    //加载自定义创造背包物品
    cb::RegistryCI();
    return true;
}

bool Entry::disable() { return true; }

bool Entry::unload() { return true; }

} // namespace cb

LL_REGISTER_MOD(cb::Entry, cb::Entry::getInstance());