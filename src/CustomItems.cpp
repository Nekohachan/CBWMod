#include "CustomItems.h"
#include "Config.h"
#include <gmlib/mod/item/CustomCreativeItemRegistry.h>
#include <gmlib/mod/item/CustomItemRegistry.h>
#include <gmlib/mod/item/base/ICustomArmorItem.h>
#include <gmlib/mod/item/base/ICustomItem.h>
#include <mc/deps/core/string/HashedString.h>
#include <mc/world/item/Item.h>
#include <mc/world/item/ItemStackBase.h>
#include <mc/world/item/VanillaItemNames.h>
#include <mc/world/item/VanillaItemTags.h>
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
        auto config = cb::ToolDiggableBlock::config;
        for (std::string& block_name : config.sword) {
            auto bl = Block::tryGetFromRegistry(block_name);
            canDestroySpecial(bl);
        }
    };
    //  手持动作
    bool isHandEquipped() const override { return true; }
    // 是否为燃料
    bool isFuel() const override { return true; }
    // 单个该物品可烧制多少物品
    float getFurnaceBurnInterval() const override { return 1; }
};

GMLIB_REGISTER_ITEM(WoodenSword);


} // namespace cb
