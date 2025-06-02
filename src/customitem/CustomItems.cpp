#include "include.h"

namespace cb {


// 覆写原版物品
using namespace gmlib::mod;

// 木剑
class WoodenSword : public ICustomToolItem {
public:
    // 键名
    WoodenSword() : ICustomToolItem(VanillaItemNames::WoodenSword()) {};
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
    // 是否为剑
    bool isSword() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 2; }
    // 判断是否为可破坏方块
    bool canDestroySpecial(Block const& block) const override {
        if (block.hasTag("minecraft:is_sword_item_destructible")) {
            return true;
        };
        return false;
    }
    // 挖掘效果为工具
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }
    // 手持动作
    bool isHandEquipped() const override { return true; }
    // 是否为燃料
    bool isFuel() const override { return true; }
    // 单个该物品可烧制多少物品
    float getFurnaceBurnInterval() const override { return 1; }
};

// 木斧
class WoodenAxe : public ICustomToolItem {
public:
    // 键名
    WoodenAxe() : ICustomToolItem(VanillaItemNames::WoodenAxe()) {};
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
    // 是否为斧
    bool isAxe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 2; }
    // 判断是否为可破坏方块
    bool canDestroySpecial(Block const& block) const override {
        if (block.hasTag("minecraft:is_axe_item_destructible")) {
            return true;
        };
        return false;
    }
    // 挖掘效果为工具
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }
    // 手持动作
    bool isHandEquipped() const override { return true; }
    // 是否为燃料
    bool isFuel() const override { return true; }
    // 单个该物品可烧制多少物品
    float getFurnaceBurnInterval() const override { return 1; }
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};

// 木镐
class WoodenPickaxe : public ICustomToolItem {
public:
    // 键名
    WoodenPickaxe() : ICustomToolItem(VanillaItemNames::WoodenPickaxe()) {};
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
    // 是否为镐
    bool isPickaxe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 2; }
    // 判断是否为可破坏方块
    bool canDestroySpecial(Block const& block) const override {
        if (block.hasTag("minecraft:is_pickaxe_item_destructible")) {
            return true;
        };
        return false;
    }
    // 挖掘效果为工具
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }
    // 手持动作
    bool isHandEquipped() const override { return true; }
    // 是否为燃料
    bool isFuel() const override { return true; }
    // 单个该物品可烧制多少物品
    float getFurnaceBurnInterval() const override { return 1; }
};

// 木楸
class WoodenShovel : public ICustomToolItem {
public:
    // 键名
    WoodenShovel() : ICustomToolItem(VanillaItemNames::WoodenShovel()) {};
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
    // 是否为锹
    bool isShovel() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 2; }
    // 判断是否为可破坏方块
    bool canDestroySpecial(Block const& block) const override {
        if (block.hasTag("minecraft:is_shovel_item_destructible")) {
            return true;
        };
        return false;
    }
    // 挖掘效果为工具
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }
    // 手持动作
    bool isHandEquipped() const override { return true; }
    // 是否为燃料
    bool isFuel() const override { return true; }
    // 单个该物品可烧制多少物品
    float getFurnaceBurnInterval() const override { return 1; }
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};

// 木锄
class WoodenHoe : public ICustomToolItem {
public:
    // 键名
    WoodenHoe() : ICustomToolItem(VanillaItemNames::WoodenHoe()) {};
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
    // 是否为锄
    bool isHoe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 2; }
    // 判断是否为可破坏方块
    bool canDestroySpecial(Block const& block) const override {
        if (block.hasTag("minecraft:is_hoe_item_destructible")) {
            return true;
        };
        return false;
    }
    // 挖掘效果为工具
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }
    // 手持动作
    bool isHandEquipped() const override { return true; }
    // 是否为燃料
    bool isFuel() const override { return true; }
    // 单个该物品可烧制多少物品
    float getFurnaceBurnInterval() const override { return 1; }
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};

GMLIB_REGISTER_ITEM(WoodenSword);
GMLIB_REGISTER_ITEM(WoodenAxe);
GMLIB_REGISTER_ITEM(WoodenPickaxe);
GMLIB_REGISTER_ITEM(WoodenShovel);
GMLIB_REGISTER_ITEM(WoodenHoe);


} // namespace cb
