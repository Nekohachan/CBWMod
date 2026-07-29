#pragma once
#include "mc/world/attribute/BaseAttributeMap.h"

namespace cb {
class AttributeHelper {
    static void setDirty(BaseAttributeMap& map, AttributeInstance const* attribute);

public:
    static bool setCurrentValue(BaseAttributeMap& map, Attribute const& attribute, float value);
    static bool setMaxValue(BaseAttributeMap& map, Attribute const& attribute, float value);
    static bool setDefaultValue(BaseAttributeMap& map, Attribute const& attribute, float value);
};
} // namespace cb
