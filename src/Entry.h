#pragma once
#include "Config.h"
#include "Gloabl.h"

namespace cb {

class Entry {

public:
    static Entry& getInstance();

    Entry() : mSelf(*ll::mod::NativeMod::current()) {}

    [[nodiscard]] ll::mod::NativeMod& getSelf() const { return mSelf; }

    bool load();
    bool enable();
    bool disable();
    bool unload();

private:
    ll::mod::NativeMod&                  mSelf;
    std::optional<Config>                mConfig;
    std::optional<gmlib::i18n::LangI18n> mI18n;
};

} // namespace cb