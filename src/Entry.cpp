#include "Entry.h"
#include "config/Config.h"
#include "customitem/CustomCI.h"
#include <gmlib/gm/i18n/ResourceI18n.h>
#include <ll/api/mod/RegisterHelper.h>

namespace cb {

Entry& Entry::getInstance() {
    static Entry instance;
    return instance;
}

#define logger cb::Entry::getInstance().getSelf().getLogger()

bool Entry::load() const {
    /* // 加载语言文件
    cb::ModConfig::Config();
    auto config = cb::ModConfig::config;
    // 加载语言文件
    auto version  = getSelf().getManifest().version.value_or(ll::data::Version{0, 0, 0});
    auto resource = gmlib::i18n::ResourceI18n(
        getSelf().getModDir(),
        getSelf().getName(),
        version.major,
        version.minor,
        version.patch
    );
    resource.addLanguagesFromDirectory(getSelf().getModDir() / config.lang_path);
    resource.loadAllLanguages(); */
    // 加载完成提示
    logger.info("CBWMod 已加载!");
    logger.info("作者: Nekohachan");
    return true;
}

bool Entry::enable() const {
    // 加载自定义创造背包物品
    cb::RegistryCI();
    return true;
}

bool Entry::disable() const { return true; }

bool Entry::unload() const {
    // 卸载自定义创造背包物品
    cb::UnregistryCI();
    return true;
}

} // namespace cb

LL_REGISTER_MOD(cb::Entry, cb::Entry::getInstance());