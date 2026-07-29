#include "config/Config.h"
#include <mc/world/item/Item.h>
#include <mc/world/item/ItemStackBase.h>
#include <modapi/item/CustomItemRegistry.h>
#include <modapi/item/base/ICustomItem.h>
#include <modapi/item/types/ItemIcon.h>


using namespace cb;
using namespace modapi;

// 生铁锭
class PigIronIngot;
// 锂锭
class LithiumIngot;
// 粗锂
class RawLithium;
// 钒锭
class VanadiumIngot;
// 粗钒
class RawVanadium;
// 铬锭
class ChromiumIngot;
// 粗铬
class RawChromium;
// 铬锭
class ManganeseIngot;
// 粗铬
class RawManganese;
// 铝锭
class AluminiumIngot;
// 钛锭
class TitaniumIngot;
// 粗钛
class RawTitanium;

class PigIronIngot : public ICustomItem {
public:
    // 构造函数
    PigIronIngot() : ICustomItem("cb:pig_iron_ingot") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("pig_iron_ingot"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.cb:pig_iron_ingot.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Items;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "cb:itemGroup.material"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 64; }
};

class LithiumIngot : public ICustomItem {
public:
    // 构造函数
    LithiumIngot() : ICustomItem("cb:lithium_ingot") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("lithium_ingot"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.cb:lithium_ingot.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Items;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "cb:itemGroup.material"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 64; }
};

class RawLithium : public ICustomItem {
public:
    // 构造函数
    RawLithium() : ICustomItem("cb:raw_lithium") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("raw_lithium"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.cb:raw_lithium.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Items;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "cb:itemGroup.material"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 64; }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"cb:lithium_ore"};
        return tags;
    }
};

class VanadiumIngot : public ICustomItem {
public:
    // 构造函数
    VanadiumIngot() : ICustomItem("cb:vanadium_ingot") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("vanadium_ingot"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.cb:vanadium_ingot.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Items;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "cb:itemGroup.material"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 64; }
};

class RawVanadium : public ICustomItem {
public:
    // 构造函数
    RawVanadium() : ICustomItem("cb:raw_vanadium") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("raw_vanadium"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.cb:raw_vanadium.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Items;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "cb:itemGroup.material"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 64; }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"cb:vanadium_ore"};
        return tags;
    }
};

class ChromiumIngot : public ICustomItem {
public:
    // 构造函数
    ChromiumIngot() : ICustomItem("cb:chromium_ingot") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("chromium_ingot"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.cb:chromium_ingot.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Items;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "cb:itemGroup.material"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 64; }
};

class RawChromium : public ICustomItem {
public:
    // 构造函数
    RawChromium() : ICustomItem("cb:raw_chromium") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("raw_chromium"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.cb:raw_chromium.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Items;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "cb:itemGroup.material"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 64; }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"cb:chromium_ore"};
        return tags;
    }
};

class ManganeseIngot : public ICustomItem {
public:
    // 构造函数
    ManganeseIngot() : ICustomItem("cb:manganese_ingot") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("manganese_ingot"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.cb:manganese_ingot.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Items;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "cb:itemGroup.material"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 64; }
};

class RawManganese : public ICustomItem {
public:
    // 构造函数
    RawManganese() : ICustomItem("cb:raw_manganese") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("raw_manganese"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.cb:raw_manganese.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Items;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "cb:itemGroup.material"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 64; }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"cb:manganese_ore"};
        return tags;
    }
};

class AluminiumIngot : public ICustomItem {
public:
    // 构造函数
    AluminiumIngot() : ICustomItem("cb:aluminium_ingot") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("aluminium_ingot"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.cb:aluminium_ingot.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Items;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "cb:itemGroup.material"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 64; }
};


class TitaniumIngot : public ICustomItem {
public:
    // 构造函数
    TitaniumIngot() : ICustomItem("cb:titanium_ingot") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("titanium_ingot"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.cb:titanium_ingot.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Items;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "cb:itemGroup.material"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 64; }
};

class RawTitanium : public ICustomItem {
public:
    // 构造函数
    RawTitanium() : ICustomItem("cb:raw_titanium") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("raw_titanium"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.cb:raw_titanium.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Items;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "cb:itemGroup.material"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 64; }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"cb:titanium_ore"};
        return tags;
    }
};

// 物品注册
MODAPI_REGISTER_ITEM(PigIronIngot);
MODAPI_REGISTER_ITEM(LithiumIngot);
MODAPI_REGISTER_ITEM(RawLithium);
MODAPI_REGISTER_ITEM(VanadiumIngot);
MODAPI_REGISTER_ITEM(RawVanadium);
MODAPI_REGISTER_ITEM(ChromiumIngot);
MODAPI_REGISTER_ITEM(RawChromium);
MODAPI_REGISTER_ITEM(ManganeseIngot);
MODAPI_REGISTER_ITEM(RawManganese);
MODAPI_REGISTER_ITEM(AluminiumIngot);
MODAPI_REGISTER_ITEM(TitaniumIngot);
MODAPI_REGISTER_ITEM(RawTitanium);