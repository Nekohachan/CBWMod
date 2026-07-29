#include "Entry.h"
#include "core/Hook.h"
#include "core/Ontick.h"
#include "customitem/CustomCI.h"
#include "customitem/CustomRecipe.h"
#include "ll/api/thread/ServerThreadExecutor.h"
#include <ll/api/mod/RegisterHelper.h>

namespace cb {

Entry& Entry::getInstance() {
    static Entry instance;
    return instance;
}

#define logger cb::Entry::getInstance().getSelf().getLogger()

bool Entry::load() const {
    // 加载完成提示
    logger.info("CBWMod 已加载!");
    logger.info("作者: Nekohachan");
    return true;
}

bool Entry::enable() {
    // 重置停止标志，确保新协程能够运行
    mShouldStop.store(false);
    // 加载自定义创造背包物品
    cb::RegistryCI();
    // 注册和卸载部分配方
    cb::RegistryRecipe();
    // 加载Lore检测循环
    cb::OnTick(mShouldStop).launch(ll::thread::ServerThreadExecutor::getDefault());
    // 拦截凋零生成
    cb::witherHook();
    //  拦截铁傀儡生成
    cb::ironGolemHook();
    return true;
}

bool Entry::disable() {
    // 卸载自定义创造背包物品
    cb::UnregistryCI();
    mShouldStop.store(true); // 通知协程停止
    // 等待协程完全退出（更复杂，可能需要额外同步）
    return true;
}

bool Entry::unload() const { return true; }

} // namespace cb

LL_REGISTER_MOD(cb::Entry, cb::Entry::getInstance());