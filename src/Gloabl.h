#pragma once
#include <ll/api/mod/Mod.h>

namespace cb {
class CustomItems;
CustomItems&          getInstance();
ll::mod::Mod&   getSelfMod();
ll::io::Logger& getLogger();
} // namespace CustomItems