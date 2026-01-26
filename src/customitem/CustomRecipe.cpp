#include "Entry.h"
#include <modapi/recipe/CustomRecipeRegistry.h>
namespace cb {

void UnRegistryRecipe() {
    auto& registry = modapi::CustomRecipeRegistry::getInstance();

    registry.unregisterRecipe("minecraft:mace", true);
}
} // namespace cb