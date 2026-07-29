#pragma once
#include "mc/world/actor/player/Player.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace cb {

json& loreToAttr(ItemStack& item, const std::string& slot, json& attr);

void ModifiedAttributeLoop(Player&);

} // namespace cb