#include "config/Config.h"
#include "gmlib/mod/item/types/RepairItems.h"
#include "include.h"
#include "mc/world/item/VanillaItemNames.h"

namespace cb {


// 覆写原版物品
using namespace gmlib::mod;

// 木质工具 -------------------------------------------------------------------------------------------------

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
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Wooden, RepairAmount)};
        return repairitems;
    }
    //  物品标签
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
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Wooden, RepairAmount)};
        return repairitems;
    }
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
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Wooden, RepairAmount)};
        return repairitems;
    }
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
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Wooden, RepairAmount)};
        return repairitems;
    }
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
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Wooden, RepairAmount)};
        return repairitems;
    }
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

// 石质工具 -------------------------------------------------------------------------------------------------

// 石剑
class StoneSword : public ICustomToolItem {
public:
    // 键名
    StoneSword() : ICustomToolItem(VanillaItemNames::StoneSword()) {};
    // 贴图
    ItemIcon getIcon() const override { return "stone_sword"; }
    // 名字
    std::string getDisplayName() const override { return "item.stone_sword.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 在创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }
    // 耐久
    short getItemDurability() const override { return 131; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }
    //  物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_sword", "minecraft:is_tool", "minecraft:stone_tier"};
    }
    // 是否为剑
    bool isSword() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 4; }
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
};

// 石斧
class StoneAxe : public ICustomToolItem {
public:
    // 键名
    StoneAxe() : ICustomToolItem(VanillaItemNames::StoneAxe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "stone_axe"; }
    // 名字
    std::string getDisplayName() const override { return "item.stone_axe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 131; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_axe", "minecraft:is_tool", "minecraft:stone_tier"};
    }
    // 是否为斧
    bool isAxe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 4; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};

// 石镐
class StonePickaxe : public ICustomToolItem {
public:
    // 键名
    StonePickaxe() : ICustomToolItem(VanillaItemNames::StonePickaxe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "stone_pickaxe"; }
    // 名字
    std::string getDisplayName() const override { return "item.stone_pickaxe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 131; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:stone_tier"};
    }
    // 是否为镐
    bool isPickaxe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 4; }
    // 判断是否为可破坏方块
    bool canDestroySpecial(Block const& block) const override {
        if (block.hasTag("minecraft:is_pickaxe_item_destructible")
            || block.hasTag("minecraft:stone_tier_destructible")) {
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
};

// 石楸
class StoneShovel : public ICustomToolItem {
public:
    // 键名
    StoneShovel() : ICustomToolItem(VanillaItemNames::StoneShovel()) {};
    // 贴图
    ItemIcon getIcon() const override { return "stone_shovel"; }
    // 名字
    std::string getDisplayName() const override { return "item.stone_shovel.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 131; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_shovel", "minecraft:is_tool", "minecraft:stone_tier"};
    }
    // 是否为锹
    bool isShovel() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 4; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};

// 石锄
class StoneHoe : public ICustomToolItem {
public:
    // 键名
    StoneHoe() : ICustomToolItem(VanillaItemNames::StoneHoe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "stone_hoe"; }
    // 名字
    std::string getDisplayName() const override { return "item.stone_hoe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 131; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_hoe", "minecraft:is_tool", "minecraft:stone_tier"};
    }
    // 是否为锄
    bool isHoe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 4; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};

// 铁质工具 -------------------------------------------------------------------------------------------------

// 铁剑
class IronSword : public ICustomToolItem {
public:
    // 键名
    IronSword() : ICustomToolItem(VanillaItemNames::IronSword()) {};
    // 贴图
    ItemIcon getIcon() const override { return "iron_sword"; }
    // 名字
    std::string getDisplayName() const override { return "item.iron_sword.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 在创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }
    // 耐久
    short getItemDurability() const override { return 250; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }
    //  物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_sword", "minecraft:is_tool", "minecraft:iron_tier"};
    }
    // 是否为剑
    bool isSword() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 6; }
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
};

// 铁斧
class IronAxe : public ICustomToolItem {
public:
    // 键名
    IronAxe() : ICustomToolItem(VanillaItemNames::IronAxe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "iron_axe"; }
    // 名字
    std::string getDisplayName() const override { return "item.iron_axe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 250; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_axe", "minecraft:is_tool", "minecraft:iron_tier"};
    }
    // 是否为斧
    bool isAxe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 6; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};

// 铁镐
class IronPickaxe : public ICustomToolItem {
public:
    // 键名
    IronPickaxe() : ICustomToolItem(VanillaItemNames::IronPickaxe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "iron_pickaxe"; }
    // 名字
    std::string getDisplayName() const override { return "item.iron_pickaxe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 250; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:iron_tier"};
    }
    // 是否为镐
    bool isPickaxe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 6; }
    // 判断是否为可破坏方块
    bool canDestroySpecial(Block const& block) const override {
        if (block.hasTag("minecraft:is_pickaxe_item_destructible") || block.hasTag("minecraft:stone_tier_destructible")
            || block.hasTag("minecraft:iron_tier_destructible")) {
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
};

// 铁楸
class IronShovel : public ICustomToolItem {
public:
    // 键名
    IronShovel() : ICustomToolItem(VanillaItemNames::IronShovel()) {};
    // 贴图
    ItemIcon getIcon() const override { return "iron_shovel"; }
    // 名字
    std::string getDisplayName() const override { return "item.iron_shovel.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 250; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_shovel", "minecraft:is_tool", "minecraft:iron_tier"};
    }
    // 是否为锹
    bool isShovel() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 6; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};

// 铁锄
class IronHoe : public ICustomToolItem {
public:
    // 键名
    IronHoe() : ICustomToolItem(VanillaItemNames::IronHoe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "iron_hoe"; }
    // 名字
    std::string getDisplayName() const override { return "item.iron_hoe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 250; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_hoe", "minecraft:is_tool", "minecraft:iron_tier"};
    }
    // 是否为锄
    bool isHoe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 6; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};

// 金质工具 -------------------------------------------------------------------------------------------------

// 金剑
class GoldenSword : public ICustomToolItem {
public:
    // 键名
    GoldenSword() : ICustomToolItem(VanillaItemNames::GoldenSword()) {};
    // 贴图
    ItemIcon getIcon() const override { return "golden_sword"; }
    // 名字
    std::string getDisplayName() const override { return "item.golden_sword.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 在创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }
    // 耐久
    short getItemDurability() const override { return 32; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }
    //  物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_sword", "minecraft:is_tool", "minecraft:golden_tier"};
    }
    // 是否为剑
    bool isSword() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 12; }
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
};

// 金斧
class GoldenAxe : public ICustomToolItem {
public:
    // 键名
    GoldenAxe() : ICustomToolItem(VanillaItemNames::GoldenAxe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "golden_axe"; }
    // 名字
    std::string getDisplayName() const override { return "item.golden_axe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 32; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_axe", "minecraft:is_tool", "minecraft:golden_tier"};
    }
    // 是否为斧
    bool isAxe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 12; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};

// 金镐
class GoldenPickaxe : public ICustomToolItem {
public:
    // 键名
    GoldenPickaxe() : ICustomToolItem(VanillaItemNames::GoldenPickaxe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "golden_pickaxe"; }
    // 名字
    std::string getDisplayName() const override { return "item.golden_pickaxe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 32; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:golden_tier"};
    }
    // 是否为镐
    bool isPickaxe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 12; }
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
};

// 金楸
class GoldenShovel : public ICustomToolItem {
public:
    // 键名
    GoldenShovel() : ICustomToolItem(VanillaItemNames::GoldenShovel()) {};
    // 贴图
    ItemIcon getIcon() const override { return "golden_shovel"; }
    // 名字
    std::string getDisplayName() const override { return "item.golden_shovel.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 32; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_shovel", "minecraft:is_tool", "minecraft:golden_tier"};
    }
    // 是否为锹
    bool isShovel() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 12; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};

// 金锄
class GoldenHoe : public ICustomToolItem {
public:
    // 键名
    GoldenHoe() : ICustomToolItem(VanillaItemNames::GoldenHoe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "golden_hoe"; }
    // 名字
    std::string getDisplayName() const override { return "item.golden_hoe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 32; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_hoe", "minecraft:is_tool", "minecraft:golden_tier"};
    }
    // 是否为锄
    bool isHoe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 12; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};

// 钻石质工具 -------------------------------------------------------------------------------------------------

// 钻石剑
class DiamondSword : public ICustomToolItem {
public:
    // 键名
    DiamondSword() : ICustomToolItem(VanillaItemNames::DiamondSword()) {};
    // 贴图
    ItemIcon getIcon() const override { return "diamond_sword"; }
    // 名字
    std::string getDisplayName() const override { return "item.diamond_sword.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 在创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }
    // 耐久
    short getItemDurability() const override { return 1561; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }
    //  物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_sword", "minecraft:is_tool", "minecraft:diamond_tier"};
    }
    // 是否为剑
    bool isSword() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 8; }
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
    // 可作为锻造台原件
    bool isSmithingTransformable() const override { return true; }
};

// 钻石斧
class DiamondAxe : public ICustomToolItem {
public:
    // 键名
    DiamondAxe() : ICustomToolItem(VanillaItemNames::DiamondAxe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "diamond_axe"; }
    // 名字
    std::string getDisplayName() const override { return "item.diamond_axe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 1561; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_axe", "minecraft:is_tool", "minecraft:diamond_tier"};
    }
    // 是否为斧
    bool isAxe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 8; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
    // 可作为锻造台原件
    bool isSmithingTransformable() const override { return true; }
};

// 钻石镐
class DiamondPickaxe : public ICustomToolItem {
public:
    // 键名
    DiamondPickaxe() : ICustomToolItem(VanillaItemNames::DiamondPickaxe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "diamond_pickaxe"; }
    // 名字
    std::string getDisplayName() const override { return "item.diamond_pickaxe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 1561; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:diamond_tier"};
    }
    // 是否为镐
    bool isPickaxe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 8; }
    // 判断是否为可破坏方块
    bool canDestroySpecial(Block const& block) const override {
        if (block.hasTag("minecraft:is_pickaxe_item_destructible") || block.hasTag("minecraft:stone_tier_destructible")
            || block.hasTag("minecraft:iron_tier_destructible")
            || block.hasTag("minecraft:diamond_tier_destructible")) {
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
    // 可作为锻造台原件
    bool isSmithingTransformable() const override { return true; }
};

// 钻石楸
class DiamondShovel : public ICustomToolItem {
public:
    // 键名
    DiamondShovel() : ICustomToolItem(VanillaItemNames::DiamondShovel()) {};
    // 贴图
    ItemIcon getIcon() const override { return "diamond_shovel"; }
    // 名字
    std::string getDisplayName() const override { return "item.diamond_shovel.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 1561; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_shovel", "minecraft:is_tool", "minecraft:diamond_tier"};
    }
    // 是否为锹
    bool isShovel() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 8; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
    // 可作为锻造台原件
    bool isSmithingTransformable() const override { return true; }
};

// 钻石锄
class DiamondHoe : public ICustomToolItem {
public:
    // 键名
    DiamondHoe() : ICustomToolItem(VanillaItemNames::DiamondHoe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "diamond_hoe"; }
    // 名字
    std::string getDisplayName() const override { return "item.diamond_hoe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 1561; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_hoe", "minecraft:is_tool", "minecraft:diamond_tier"};
    }
    // 是否为锄
    bool isHoe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 8; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
    // 可作为锻造台原件
    bool isSmithingTransformable() const override { return true; }
};

// 下界合金质工具 -------------------------------------------------------------------------------------------------

// 下界合金剑
class NetheriteSword : public ICustomToolItem {
public:
    // 键名
    NetheriteSword() : ICustomToolItem(VanillaItemNames::NetheriteSword()) {};
    // 贴图
    ItemIcon getIcon() const override { return "netherite_sword"; }
    // 名字
    std::string getDisplayName() const override { return "item.netherite_sword.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 在创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }
    // 耐久
    short getItemDurability() const override { return 1561; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }
    //  物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_sword", "minecraft:is_tool", "minecraft:netherite_tier"};
    }
    // 是否为剑
    bool isSword() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 8; }
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
    // 是否为不可被烧毁物品
    bool isFireResistant() const override { return true; }
};

// 下界合金斧
class NetheriteAxe : public ICustomToolItem {
public:
    // 键名
    NetheriteAxe() : ICustomToolItem(VanillaItemNames::NetheriteAxe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "netherite_axe"; }
    // 名字
    std::string getDisplayName() const override { return "item.netherite_axe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 1561; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_axe", "minecraft:is_tool", "minecraft:netherite_tier"};
    }
    // 是否为斧
    bool isAxe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 8; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
    // 是否为不可被烧毁物品
    bool isFireResistant() const override { return true; }
};

// 下界合金镐
class NetheritePickaxe : public ICustomToolItem {
public:
    // 键名
    NetheritePickaxe() : ICustomToolItem(VanillaItemNames::NetheritePickaxe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "netherite_pickaxe"; }
    // 名字
    std::string getDisplayName() const override { return "item.netherite_pickaxe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 1561; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:netherite_tier"};
    }
    // 是否为镐
    bool isPickaxe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 8; }
    // 判断是否为可破坏方块
    bool canDestroySpecial(Block const& block) const override {
        if (block.hasTag("minecraft:is_pickaxe_item_destructible") || block.hasTag("minecraft:stone_tier_destructible")
            || block.hasTag("minecraft:iron_tier_destructible")
            || block.hasTag("minecraft:diamond_tier_destructible")) {
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
    // 是否为不可被烧毁物品
    bool isFireResistant() const override { return true; }
};

// 下界合金楸
class NetheriteShovel : public ICustomToolItem {
public:
    // 键名
    NetheriteShovel() : ICustomToolItem(VanillaItemNames::NetheriteShovel()) {};
    // 贴图
    ItemIcon getIcon() const override { return "netherite_shovel"; }
    // 名字
    std::string getDisplayName() const override { return "item.netherite_shovel.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 1561; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_shovel", "minecraft:is_tool", "minecraft:netherite_tier"};
    }
    // 是否为锹
    bool isShovel() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 8; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
    // 是否为不可被烧毁物品
    bool isFireResistant() const override { return true; }
};

// 下界合金锄
class NetheriteHoe : public ICustomToolItem {
public:
    // 键名
    NetheriteHoe() : ICustomToolItem(VanillaItemNames::NetheriteHoe()) {};
    // 贴图
    ItemIcon getIcon() const override { return "netherite_hoe"; }
    // 名字
    std::string getDisplayName() const override { return "item.netherite_hoe.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 1561; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }
    // 物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_hoe", "minecraft:is_tool", "minecraft:netherite_tier"};
    }
    // 是否为锄
    bool isHoe() const override { return true; }
    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }
    // 挖掘速度
    float getMiningSpeed() const override { return 8; }
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
    // 执行事件
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
    // 是否为不可被烧毁物品
    bool isFireResistant() const override { return true; }
};

GMLIB_REGISTER_ITEM(WoodenSword);
GMLIB_REGISTER_ITEM(WoodenAxe);
GMLIB_REGISTER_ITEM(WoodenPickaxe);
GMLIB_REGISTER_ITEM(WoodenShovel);
GMLIB_REGISTER_ITEM(WoodenHoe);

GMLIB_REGISTER_ITEM(StoneSword);
GMLIB_REGISTER_ITEM(StoneAxe);
GMLIB_REGISTER_ITEM(StonePickaxe);
GMLIB_REGISTER_ITEM(StoneShovel);
GMLIB_REGISTER_ITEM(StoneHoe);

GMLIB_REGISTER_ITEM(IronSword);
GMLIB_REGISTER_ITEM(IronAxe);
GMLIB_REGISTER_ITEM(IronPickaxe);
GMLIB_REGISTER_ITEM(IronShovel);
GMLIB_REGISTER_ITEM(IronHoe);

GMLIB_REGISTER_ITEM(GoldenSword);
GMLIB_REGISTER_ITEM(GoldenAxe);
GMLIB_REGISTER_ITEM(GoldenPickaxe);
GMLIB_REGISTER_ITEM(GoldenShovel);
GMLIB_REGISTER_ITEM(GoldenHoe);

GMLIB_REGISTER_ITEM(DiamondSword);
GMLIB_REGISTER_ITEM(DiamondAxe);
GMLIB_REGISTER_ITEM(DiamondPickaxe);
GMLIB_REGISTER_ITEM(DiamondShovel);
GMLIB_REGISTER_ITEM(DiamondHoe);

GMLIB_REGISTER_ITEM(NetheriteSword);
GMLIB_REGISTER_ITEM(NetheriteAxe);
GMLIB_REGISTER_ITEM(NetheritePickaxe);
GMLIB_REGISTER_ITEM(NetheriteShovel);
GMLIB_REGISTER_ITEM(NetheriteHoe);

} // namespace cb
