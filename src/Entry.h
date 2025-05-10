#pragma once
#include <ll/api/mod/NativeMod.h>

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

    void CreativeInventory();

    private:
        ll::mod::NativeMod& mSelf;
    };

} // namespace cb