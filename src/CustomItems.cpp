#include "CustomItems.h"
#include "Config.h"
#include <gmlib/mod/item/CustomCreativeItemRegistry.h>
#include <gmlib/mod/item/CustomItemRegistry.h>
#include <gmlib/mod/item/base/ICustomArmorItem.h>
#include <gmlib/mod/item/base/ICustomItem.h>
#include <mc/deps/core/string/HashedString.h>
#include <mc/world/actor/player/Player.h>
#include <mc/world/gamemode/InteractionResult.h>
#include <mc/world/item/Item.h>
#include <mc/world/item/ItemStackBase.h>
#include <mc/world/item/VanillaItemNames.h>
#include <mc/world/item/VanillaItemTags.h>
#include <mc/world/level/BlockPos.h>
#include <mc/world/level/BlockSource.h>
#include <mc/world/level/block/Block.h>

namespace cb {

// 创造背包注册
void RegistryCI() {
    cb::CIConfig::TryLoad();
    auto config = cb::CIConfig::config;

    auto& registry = gmlib::mod::CustomCreativeItemRegistry::getInstance();

    // 注册物品分组
    for (auto& group : config.extra_groups) {
        registry
            .registerCreativeGroup(group.name, ::ItemInstance(group.icon), ::CreativeItemCategory((int)group.category));
    }

    // 注册创造背包物品
    for (auto& item : config.creative_items) {
        CompoundTag* nbt = nullptr;
        if (item.nbt) {
            if (auto userdata = ::CompoundTag::fromSnbt(*item.nbt)) {
                nbt = new ::CompoundTag(*userdata);
            }
        }
        registry.registerCreativeItem(
            ::ItemInstance(item.type, 1, 0, nbt),
            ::CreativeItemCategory((int)item.category),
            item.group
        );
    }
}

// 覆写原版物品
using namespace gmlib::mod;

// 木剑
class WoodenSword : public ICustomItem {
public:
    ToolDiggableBlock ToolDiggableBlock;

public:
    // 键名
    WoodenSword() : ICustomItem(VanillaItemNames::WoodenSword()) {};
    // 贴图
    ItemIcon getIcon() const override { return "wooden_sword"; }
    // 名字
    std::string getDisplayName() const override { return "item.wooden_sword.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 在创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }
    // 耐久
    short getItemDurability() const override { return 59; }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_sword", "minecraft:is_tool", "minecraft:wooden_tier"};
    }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 15; }
    // 设置可破坏方块列表
    bool canDestroySpecial(Block const&) const override { return true; }
    void setCanDestroyList() const {
        auto config = ToolDiggableBlock;
        for (std::string& block_name : config.sword) {
            auto bl = Block::tryGetFromRegistry(block_name, -1);
            canDestroySpecial(bl);
        }
    };
    // 手持动作
    bool isHandEquipped() const override { return true; }
    // 是否为燃料
    bool isFuel() const override { return true; }
    // 单个该物品可烧制多少物品
    float getFurnaceBurnInterval() const override { return 1; }
};

// 木斧
class WoodenAxe : public ICustomItem {
public:
    ToolDiggableBlock ToolDiggableBlock;

public:
    // 键名
    WoodenAxe() : ICustomItem(VanillaItemNames::WoodenAxe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "wooden_axe"; }
    // 名字
    std::string getDisplayName() const override { return "item.wooden_axe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 59; }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_axe", "minecraft:is_tool", "minecraft:wooden_tier"};
    }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 2; }
    // 设置可破坏方块列表
    bool canDestroySpecial(Block const&) const override { return true; }
    void setCanDestroyList() const {
        auto config = ToolDiggableBlock;
        for (std::string& block_name : config.axe) {
            auto bl = Block::tryGetFromRegistry(block_name, -1);
            canDestroySpecial(bl);
        }
    };
    // 手持动作
    bool isHandEquipped() const override { return true; }
    // 是否为燃料
    bool isFuel() const override { return true; }
    // 单个该物品可烧制多少物品
    float getFurnaceBurnInterval() const override { return 1; }
};

// 木镐
class WoodenPickaxe : public ICustomItem {
public:
    ToolDiggableBlock ToolDiggableBlock;

public:
    // 键名
    WoodenPickaxe() : ICustomItem(VanillaItemNames::WoodenPickaxe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "wooden_pickaxe"; }
    // 名字
    std::string getDisplayName() const override { return "item.wooden_pickaxe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 59; }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:wooden_tier"};
    }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 2; }
    // 设置可破坏方块列表
    bool canDestroySpecial(Block const&) const override { return true; }
    void setCanDestroyList() const {
        auto config = ToolDiggableBlock;
        for (std::string& block_name : config.pickaxe) {
            auto bl = Block::tryGetFromRegistry(block_name, -1);
            canDestroySpecial(bl);
        }
    };
    // 手持动作
    bool isHandEquipped() const override { return true; }
    // 是否为燃料
    bool isFuel() const override { return true; }
    // 单个该物品可烧制多少物品
    float getFurnaceBurnInterval() const override { return 1; }
};

// 木楸
class WoodenShovel : public ICustomItem {
public:
    ToolDiggableBlock ToolDiggableBlock;

public:
    // 键名
    WoodenShovel() : ICustomItem(VanillaItemNames::WoodenShovel()) {};
    // 贴图
    ItemIcon getIcon() const override { return "wooden_shovel"; }
    // 名字
    std::string getDisplayName() const override { return "item.wooden_shovel.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 59; }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_shovel", "minecraft:is_tool", "minecraft:wooden_tier"};
    }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 2; }
    // 设置可破坏方块列表
    bool canDestroySpecial(Block const&) const override { return true; }
    void setCanDestroyList() const {
        auto config = ToolDiggableBlock;
        for (std::string& block_name : config.shovel) {
            auto bl = Block::tryGetFromRegistry(block_name, -1);
            canDestroySpecial(bl);
        }
    };
    // 手持动作
    bool isHandEquipped() const override { return true; }
    // 是否为燃料
    bool isFuel() const override { return true; }
    // 单个该物品可烧制多少物品
    float getFurnaceBurnInterval() const override { return 1; }
};

// 木锄
class WoodenHoe : public ICustomItem {
public:
    ToolDiggableBlock ToolDiggableBlock;

public:
    // 键名
    WoodenHoe() : ICustomItem(VanillaItemNames::WoodenHoe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "wooden_hoe"; }
    // 名字
    std::string getDisplayName() const override { return "item.wooden_hoe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 59; }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_hoe", "minecraft:is_tool", "minecraft:wooden_tier"};
    }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 2; }
    // 设置可破坏方块列表
    bool canDestroySpecial(Block const&) const override { return true; }
    void setCanDestroyList() const {
        auto config = ToolDiggableBlock;
        for (std::string& block_name : config.hoe) {
            auto bl = Block::tryGetFromRegistry(block_name, -1);
            canDestroySpecial(bl);
        }
    };
    // 手持动作
    bool isHandEquipped() const override { return true; }
    // 是否为燃料
    bool isFuel() const override { return true; }
    // 单个该物品可烧制多少物品
    float getFurnaceBurnInterval() const override { return 1; }
};

GMLIB_REGISTER_ITEM(WoodenSword);
GMLIB_REGISTER_ITEM(WoodenAxe);
GMLIB_REGISTER_ITEM(WoodenPickaxe);
GMLIB_REGISTER_ITEM(WoodenShovel);
GMLIB_REGISTER_ITEM(WoodenHoe);


} // namespace cb
