#pragma once
#include "mc/world/actor/player/Player.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace cb {

void HealthDisplayLoop();

void BlockLoop(Player&);

void RegenerationLoop(Player&);

void MoblevelLoop();

json getBlockAttr();

} // namespace cb