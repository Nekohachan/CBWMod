#pragma once
#include "mc/world/actor/player/Player.h"

namespace cb {

ItemStack LoreTest(ItemStack& item, bool ignore_version);

void LoreTestLoop(Player&);

} // namespace cb