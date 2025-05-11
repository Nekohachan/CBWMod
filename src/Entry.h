#pragma once
#include <ll/api/mod/NativeMod.h>

namespace cb {

class Entry {

public:
    static Entry& getInstance();

    Entry() : mSelf(*ll::mod::NativeMod::current()) {}

    [[nodiscard]] ll::mod::NativeMod& getSelf() const { return mSelf; }
    //加载插件
    bool load();
    //启用插件
    bool enable();
    //禁用插件
    bool disable();
    //卸载插件
    bool unload();

private:
    ll::mod::NativeMod& mSelf;
};

} // namespace cb