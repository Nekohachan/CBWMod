#pragma once
#include <ll/api/mod/NativeMod.h>

namespace cb {

class CustomItems {

public:
    static CustomItems& getInstance();

    CustomItems() : mSelf(*ll::mod::NativeMod::current()) {}

    [[nodiscard]] ll::mod::NativeMod& getSelf() const { return mSelf; }

    /// @return True 表示 Mod 加载成功.
    bool load();

    /// @return True 表示 Mod 启用成功.
    bool enable();

    /// @return True 表示 Mod 被成功禁用.
    bool disable();

    // TODO: Implement this method if you need to unload the mod.
    // /// @return True if the mod is unloaded successfully.
    // bool unload();

private:
    ll::mod::NativeMod& mSelf;
};

} // namespace cb
