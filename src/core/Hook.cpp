#include "Hook.h"
#include <ll/api/memory/Hook.h>
#include <mc/entity/components_json_legacy/ProjectileComponent.h>
#include <mc/world/level/BlockPos.h>
#include <mc/world/level/BlockSource.h>
#include <mc/world/level/Level.h>
#include <mc/world/level/block/Block.h>
#include <mc/world/level/block/PumpkinBlock.h>
#include <mc/world/level/block/SkullBlock.h>
#include <mc/world/level/dimension/Dimension.h>



namespace cb {

// 拦截凋零生成
LL_TYPE_INSTANCE_HOOK(
    SkullBlockCheckMobSpawnHook,
    HookPriority::Normal,
    SkullBlock,
    &SkullBlock::checkMobSpawn,
    bool,
    ::Level&,
    ::BlockSource&,
    ::BlockPos const&
) {
    return false;
}

// 拦截铁傀儡生成
LL_TYPE_INSTANCE_HOOK(
    PumpkinBlockCanSpawnGolemHook,
    HookPriority::Normal,
    PumpkinBlock,
    &PumpkinBlock::_canSpawnGolem,
    bool,
    ::BlockSource&,
    ::BlockPos const&
) {
    return false;
}

void witherHook() { SkullBlockCheckMobSpawnHook::hook(); }
void ironGolemHook() { PumpkinBlockCanSpawnGolemHook::hook(); }

} // namespace cb