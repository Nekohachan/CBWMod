#include "config/Config.h"
#include "gmlib/mod/item/base/ICustomArmorItem.h"
#include "gmlib/mod/item/types/RepairItems.h"
#include "include.h"
#include "mc/world/item/Item.h"
#include "mc/world/item/VanillaItemNames.h"


namespace cb {

// 声明将调用的类

// 原版内容

// 木质工具 -------------------------------------------------------------------------------------------------

// 木剑
class WoodenSword;
// 木斧
class WoodenAxe;
// 木镐
class WoodenPickaxe;
// 木楸
class WoodenShovel;
// 木锄
class WoodenHoe;

// 石质工具 -------------------------------------------------------------------------------------------------

// 石剑
class StoneSword;
// 石斧
class StoneAxe;
// 石镐
class StonePickaxe;
// 石楸
class StoneShovel;
// 石锄
class StoneHoe;

// 铁质工具 -------------------------------------------------------------------------------------------------

// 铁剑
class IronSword;
// 铁斧
class IronAxe;
// 铁镐
class IronPickaxe;
// 铁楸
class IronShovel;
// 铁锄
class IronHoe;

// 金质工具 -------------------------------------------------------------------------------------------------

// 金剑
class GoldenSword;
// 金斧
class GoldenAxe;
// 金镐
class GoldenPickaxe;
// 金楸
class GoldenShovel;
// 金锄
class GoldenHoe;

// 钻石质工具 -------------------------------------------------------------------------------------------------

// 钻石剑
class DiamondSword;
// 钻石斧
class DiamondAxe;
// 钻石镐
class DiamondPickaxe;
// 钻石楸
class DiamondShovel;
// 钻石锄
class DiamondHoe;

// 下界合金质工具 -------------------------------------------------------------------------------------------------

// 下界合金剑
class NetheriteSword;
// 下界合金斧
class NetheriteAxe;
// 下界合金镐
class NetheritePickaxe;
// 下界合金楸
class NetheriteShovel;
// 下界合金锄
class NetheriteHoe;

// 原版武器

// 重锤
class Mace;
// 三叉戟
class Trident;

// 皮革防具 -------------------------------------------------------------------------------------------------

// 皮革帽子
class LeatherHelmet;
// 皮革外套
class LeatherChestplate;
// 皮革裤子
class LeatherLeggings;
// 皮革靴子
class LeatherBoots;

// 金防具 -------------------------------------------------------------------------------------------------

// 金头盔
class GoldenHelmet;
// 金胸甲
class GoldenChestplate;
// 金护腿
class GoldenLeggings;
// 金靴子
class GoldenBoots;

// 锁链防具 -------------------------------------------------------------------------------------------------

// 锁链头盔
class ChainmailHelmet;
// 锁链胸甲
class ChainmailChestplate;
// 锁链护腿
class ChainmailLeggings;
// 锁链靴子
class ChainmailBoots;

// 铁防具 -------------------------------------------------------------------------------------------------

// 铁头盔
class IronHelmet;
// 铁胸甲
class IronChestplate;
// 铁护腿
class IronLeggings;
// 铁靴子
class IronBoots;

// 钻石防具 -------------------------------------------------------------------------------------------------

// 钻石头盔
class DiamondHelmet;
// 钻石胸甲
class DiamondChestplate;
// 钻石护腿
class DiamondLeggings;
// 钻石靴子
class DiamondBoots;

// 下界合金防具 -------------------------------------------------------------------------------------------------

// 下界合金头盔
class NetheriteHelmet;
// 下界合金胸甲
class NetheriteChestplate;
// 下界合金护腿
class NetheriteLeggings;
// 下界合金靴子
class NetheriteBoots;


using namespace gmlib::mod;

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
        if ((block.hasTag("minecraft:is_pickaxe_item_destructible"))
            && !block.hasTag("minecraft:stone_tier_destructible") && !block.hasTag("minecraft:iron_tier_destructible")
            && !block.hasTag("minecraft:diamond_tier_destructible")) {
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
        if ((block.hasTag("minecraft:is_pickaxe_item_destructible") || block.hasTag("minecraft:stone_tier_destructible")
            )
            && !block.hasTag("minecraft:iron_tier_destructible")
            && !block.hasTag("minecraft:diamond_tier_destructible")) {
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
        if ((block.hasTag("minecraft:is_pickaxe_item_destructible") || block.hasTag("minecraft:stone_tier_destructible")
             || block.hasTag("minecraft:iron_tier_destructible"))
            && !block.hasTag("minecraft:diamond_tier_destructible")) {
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
        if ((block.hasTag("minecraft:is_pickaxe_item_destructible"))
            && !block.hasTag("minecraft:stone_tier_destructible") && !block.hasTag("minecraft:iron_tier_destructible")
            && !block.hasTag("minecraft:diamond_tier_destructible")) {
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
        if ((block.hasTag("minecraft:is_pickaxe_item_destructible") || block.hasTag("minecraft:stone_tier_destructible")
             || block.hasTag("minecraft:iron_tier_destructible")
             || block.hasTag("minecraft:diamond_tier_destructible"))) {
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
    short getItemDurability() const override { return 2031; }
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
    float getMiningSpeed() const override { return 9; }
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
    short getItemDurability() const override { return 2031; }
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
    float getMiningSpeed() const override { return 9; }
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
    short getItemDurability() const override { return 2031; }
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
    float getMiningSpeed() const override { return 9; }
    // 判断是否为可破坏方块
    bool canDestroySpecial(Block const& block) const override {
        if ((block.hasTag("minecraft:is_pickaxe_item_destructible") || block.hasTag("minecraft:stone_tier_destructible")
             || block.hasTag("minecraft:iron_tier_destructible")
             || block.hasTag("minecraft:diamond_tier_destructible"))) {
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
    short getItemDurability() const override { return 2031; }
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
    float getMiningSpeed() const override { return 9; }
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
    short getItemDurability() const override { return 2031; }
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
    float getMiningSpeed() const override { return 9; }
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

class Mace : public ICustomToolItem {
public:
    // 键名
    Mace() : ICustomToolItem(VanillaItemNames::Mace()) {};
    // 贴图
    ItemIcon getIcon() const override { return "mace"; }
    // 名字
    std::string getDisplayName() const override { return "item.mace.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 在创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }
    // 耐久
    short getItemDurability() const override { return 500; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Mace, RepairAmount)};
        return repairitems;
    }
    //  物品标签
    std::vector<std::string> getItemTags() const override {
        return std::vector<std::string>{"minecraft:is_sword", "minecraft:diamond_tier"};
    }
    // 是否为剑
    bool isSword() const override { return true; }
    // 手持动作
    bool isHandEquipped() const override { return true; }
};

class Trident : public ICustomToolItem {
public:
    // 键名
    Trident() : ICustomToolItem(VanillaItemNames::Trident()) {};
    // 贴图
    ItemIcon getIcon() const override { return "trident"; }
    // 名字
    std::string getDisplayName() const override { return "item.trident.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 在创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }
    // 耐久
    short getItemDurability() const override { return 250; }
    //  物品标签
    std::vector<std::string> getItemTags() const override { return std::vector<std::string>{"minecraft:is_trident"}; }
    // 手持动作
    bool isHandEquipped() const override { return true; }
    // 使用动画
    SharedTypes::Legacy::UseAnimation getUseAnimation() const override {
        return SharedTypes::Legacy::UseAnimation::Spear;
    };
};

class LeatherHelmet : public ICustomArmorItem {
public:
    // 键名
    LeatherHelmet() : ICustomArmorItem(VanillaItemNames::LeatherHelmet(), HumanoidArmorItem::Tier::Leather) {};
    // 贴图
    ItemIcon getIcon() const override { return "leather_helmet"; }
    // 名字
    std::string getDisplayName() const override { return "item.leather_helmet.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 55; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Leather, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Head; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipLeather;
    }
};

class LeatherChestplate : public ICustomArmorItem {
public:
    // 键名
    LeatherChestplate() : ICustomArmorItem(VanillaItemNames::LeatherChestplate(), HumanoidArmorItem::Tier::Leather) {};
    // 贴图
    ItemIcon getIcon() const override { return "leather_chestplate"; }
    // 名字
    std::string getDisplayName() const override { return "item.leather_chestplate.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 80; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Leather, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Torso; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipLeather;
    }
};

class LeatherLeggings : public ICustomArmorItem {
public:
    // 键名
    LeatherLeggings() : ICustomArmorItem(VanillaItemNames::LeatherLeggings(), HumanoidArmorItem::Tier::Leather) {};
    // 贴图
    ItemIcon getIcon() const override { return "leather_leggings"; }
    // 名字
    std::string getDisplayName() const override { return "item.leather_leggings.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 75; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Leather, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Legs; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipLeather;
    }
};

class LeatherBoots : public ICustomArmorItem {
public:
    // 键名
    LeatherBoots() : ICustomArmorItem(VanillaItemNames::LeatherBoots(), HumanoidArmorItem::Tier::Leather) {};
    // 贴图
    ItemIcon getIcon() const override { return "leather_boots"; }
    // 名字
    std::string getDisplayName() const override { return "item.leather_boots.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 65; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Leather, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Feet; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipLeather;
    }
};

class GoldenHelmet : public ICustomArmorItem {
public:
    // 键名
    GoldenHelmet() : ICustomArmorItem(VanillaItemNames::GoldenHelmet(), HumanoidArmorItem::Tier::Gold) {};
    // 贴图
    ItemIcon getIcon() const override { return "golden_helmet"; }
    // 名字
    std::string getDisplayName() const override { return "item.golden_helmet.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 77; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Head; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipGold;
    }
};

class GoldenChestplate : public ICustomArmorItem {
public:
    // 键名
    GoldenChestplate() : ICustomArmorItem(VanillaItemNames::GoldenChestplate(), HumanoidArmorItem::Tier::Gold) {};
    // 贴图
    ItemIcon getIcon() const override { return "golden_chestplate"; }
    // 名字
    std::string getDisplayName() const override { return "item.golden_chestplate.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 112; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Torso; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipGold;
    }
};

class GoldenLeggings : public ICustomArmorItem {
public:
    // 键名
    GoldenLeggings() : ICustomArmorItem(VanillaItemNames::GoldenLeggings(), HumanoidArmorItem::Tier::Gold) {};
    // 贴图
    ItemIcon getIcon() const override { return "golden_leggings"; }
    // 名字
    std::string getDisplayName() const override { return "item.golden_leggings.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 105; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Legs; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipGold;
    }
};

class GoldenBoots : public ICustomArmorItem {
public:
    // 键名
    GoldenBoots() : ICustomArmorItem(VanillaItemNames::GoldenBoots(), HumanoidArmorItem::Tier::Gold) {};
    // 贴图
    ItemIcon getIcon() const override { return "golden_boots"; }
    // 名字
    std::string getDisplayName() const override { return "item.golden_boots.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 91; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Feet; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipGold;
    }
};

class ChainmailHelmet : public ICustomArmorItem {
public:
    // 键名
    ChainmailHelmet() : ICustomArmorItem(VanillaItemNames::ChainmailHelmet(), HumanoidArmorItem::Tier::Chain) {};
    // 贴图
    ItemIcon getIcon() const override { return "chainmail_helmet"; }
    // 名字
    std::string getDisplayName() const override { return "item.chainmail_helmet.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 165; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Head; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipChain;
    }
};

class ChainmailChestplate : public ICustomArmorItem {
public:
    // 键名
    ChainmailChestplate()
    : ICustomArmorItem(VanillaItemNames::ChainmailChestplate(), HumanoidArmorItem::Tier::Chain) {};
    // 贴图
    ItemIcon getIcon() const override { return "chainmail_chestplate"; }
    // 名字
    std::string getDisplayName() const override { return "item.chainmail_chestplate.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 240; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Torso; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipChain;
    }
};

class ChainmailLeggings : public ICustomArmorItem {
public:
    // 键名
    ChainmailLeggings() : ICustomArmorItem(VanillaItemNames::ChainmailLeggings(), HumanoidArmorItem::Tier::Chain) {};
    // 贴图
    ItemIcon getIcon() const override { return "chainmail_leggings"; }
    // 名字
    std::string getDisplayName() const override { return "item.chainmail_leggings.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 225; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Legs; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipChain;
    }
};

class ChainmailBoots : public ICustomArmorItem {
public:
    // 键名
    ChainmailBoots() : ICustomArmorItem(VanillaItemNames::ChainmailBoots(), HumanoidArmorItem::Tier::Chain) {};
    // 贴图
    ItemIcon getIcon() const override { return "chainmail_boots"; }
    // 名字
    std::string getDisplayName() const override { return "item.chainmail_boots.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 195; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Feet; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipChain;
    }
};

class IronHelmet : public ICustomArmorItem {
public:
    // 键名
    IronHelmet() : ICustomArmorItem(VanillaItemNames::IronHelmet(), HumanoidArmorItem::Tier::Iron) {};
    // 贴图
    ItemIcon getIcon() const override { return "iron_helmet"; }
    // 名字
    std::string getDisplayName() const override { return "item.iron_helmet.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 165; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Head; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipIron;
    }
};

class IronChestplate : public ICustomArmorItem {
public:
    // 键名
    IronChestplate() : ICustomArmorItem(VanillaItemNames::IronChestplate(), HumanoidArmorItem::Tier::Iron) {};
    // 贴图
    ItemIcon getIcon() const override { return "iron_chestplate"; }
    // 名字
    std::string getDisplayName() const override { return "item.iron_chestplate.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 240; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Torso; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipIron;
    }
};

class IronLeggings : public ICustomArmorItem {
public:
    // 键名
    IronLeggings() : ICustomArmorItem(VanillaItemNames::IronLeggings(), HumanoidArmorItem::Tier::Iron) {};
    // 贴图
    ItemIcon getIcon() const override { return "iron_leggings"; }
    // 名字
    std::string getDisplayName() const override { return "item.iron_leggings.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 225; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Legs; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipIron;
    }
};

class IronBoots : public ICustomArmorItem {
public:
    // 键名
    IronBoots() : ICustomArmorItem(VanillaItemNames::IronBoots(), HumanoidArmorItem::Tier::Iron) {};
    // 贴图
    ItemIcon getIcon() const override { return "iron_boots"; }
    // 名字
    std::string getDisplayName() const override { return "item.iron_boots.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 195; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Feet; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipIron;
    }
};

class DiamondHelmet : public ICustomArmorItem {
public:
    // 键名
    DiamondHelmet() : ICustomArmorItem(VanillaItemNames::DiamondHelmet(), HumanoidArmorItem::Tier::Diamond) {};
    // 贴图
    ItemIcon getIcon() const override { return "diamond_helmet"; }
    // 名字
    std::string getDisplayName() const override { return "item.diamond_helmet.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 363; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Head; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipDiamond;
    }
    // 可作为锻造台原件
    bool isSmithingTransformable() const override { return true; }
};

class DiamondChestplate : public ICustomArmorItem {
public:
    // 键名
    DiamondChestplate() : ICustomArmorItem(VanillaItemNames::DiamondChestplate(), HumanoidArmorItem::Tier::Diamond) {};
    // 贴图
    ItemIcon getIcon() const override { return "diamond_chestplate"; }
    // 名字
    std::string getDisplayName() const override { return "item.diamond_chestplate.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 528; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Torso; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipDiamond;
    }
    // 可作为锻造台原件
    bool isSmithingTransformable() const override { return true; }
};

class DiamondLeggings : public ICustomArmorItem {
public:
    // 键名
    DiamondLeggings() : ICustomArmorItem(VanillaItemNames::DiamondLeggings(), HumanoidArmorItem::Tier::Diamond) {};
    // 贴图
    ItemIcon getIcon() const override { return "diamond_leggings"; }
    // 名字
    std::string getDisplayName() const override { return "item.diamond_leggings.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 495; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Legs; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipDiamond;
    }
    // 可作为锻造台原件
    bool isSmithingTransformable() const override { return true; }
};

class DiamondBoots : public ICustomArmorItem {
public:
    // 键名
    DiamondBoots() : ICustomArmorItem(VanillaItemNames::DiamondBoots(), HumanoidArmorItem::Tier::Diamond) {};
    // 贴图
    ItemIcon getIcon() const override { return "diamond_boots"; }
    // 名字
    std::string getDisplayName() const override { return "item.diamond_boots.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 429; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Feet; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipDiamond;
    }
    // 可作为锻造台原件
    bool isSmithingTransformable() const override { return true; }
};


class NetheriteHelmet : public ICustomArmorItem {
public:
    // 键名
    NetheriteHelmet() : ICustomArmorItem(VanillaItemNames::NetheriteHelmet(), HumanoidArmorItem::Tier::Netherite) {};
    // 贴图
    ItemIcon getIcon() const override { return "netherite_helmet"; }
    // 名字
    std::string getDisplayName() const override { return "item.netherite_helmet.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 407; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Head; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipNetherite;
    }
    // 是否为不可被烧毁物品
    bool isFireResistant() const override { return true; }
};

class NetheriteChestplate : public ICustomArmorItem {
public:
    // 键名
    NetheriteChestplate()
    : ICustomArmorItem(VanillaItemNames::NetheriteChestplate(), HumanoidArmorItem::Tier::Netherite) {};
    // 贴图
    ItemIcon getIcon() const override { return "netherite_chestplate"; }
    // 名字
    std::string getDisplayName() const override { return "item.netherite_chestplate.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 592; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Torso; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipNetherite;
    }
    // 是否为不可被烧毁物品
    bool isFireResistant() const override { return true; }
};

class NetheriteLeggings : public ICustomArmorItem {
public:
    // 键名
    NetheriteLeggings()
    : ICustomArmorItem(VanillaItemNames::NetheriteLeggings(), HumanoidArmorItem::Tier::Netherite) {};
    // 贴图
    ItemIcon getIcon() const override { return "netherite_leggings"; }
    // 名字
    std::string getDisplayName() const override { return "item.netherite_leggings.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 555; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Legs; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipNetherite;
    }
    // 是否为不可被烧毁物品
    bool isFireResistant() const override { return true; }
};

class NetheriteBoots : public ICustomArmorItem {
public:
    // 键名
    NetheriteBoots() : ICustomArmorItem(VanillaItemNames::NetheriteBoots(), HumanoidArmorItem::Tier::Netherite) {};
    // 贴图
    ItemIcon getIcon() const override { return "netherite_boots"; }
    // 名字
    std::string getDisplayName() const override { return "item.netherite_boots.name"; }
    // 最大堆叠
    uint8_t getItemMaxStackSize() const override { return 1; }
    // 耐久
    short getItemDurability() const override { return 481; }
    // 修复所需物品
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }
    // 是否为人型实体的盔甲
    bool isHumanoidArmor() const override { return true; };
    // 装备槽位
    SharedTypes::Legacy::ArmorSlot getArmorSlot() const override { return SharedTypes::Legacy::ArmorSlot::Feet; }
    // 装备音效
    SharedTypes::Legacy::LevelSoundEvent getEquipSound() const override {
        return SharedTypes::Legacy::LevelSoundEvent::EquipNetherite;
    }
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

GMLIB_REGISTER_ITEM(Mace);
GMLIB_REGISTER_ITEM(Trident);

GMLIB_REGISTER_ITEM(LeatherHelmet);
GMLIB_REGISTER_ITEM(LeatherChestplate);
GMLIB_REGISTER_ITEM(LeatherLeggings);
GMLIB_REGISTER_ITEM(LeatherBoots);

GMLIB_REGISTER_ITEM(GoldenHelmet);
GMLIB_REGISTER_ITEM(GoldenChestplate);
GMLIB_REGISTER_ITEM(GoldenLeggings);
GMLIB_REGISTER_ITEM(GoldenBoots);

GMLIB_REGISTER_ITEM(ChainmailHelmet);
GMLIB_REGISTER_ITEM(ChainmailChestplate);
GMLIB_REGISTER_ITEM(ChainmailLeggings);
GMLIB_REGISTER_ITEM(ChainmailBoots);

GMLIB_REGISTER_ITEM(IronHelmet);
GMLIB_REGISTER_ITEM(IronChestplate);
GMLIB_REGISTER_ITEM(IronLeggings);
GMLIB_REGISTER_ITEM(IronBoots);

GMLIB_REGISTER_ITEM(DiamondHelmet);
GMLIB_REGISTER_ITEM(DiamondChestplate);
GMLIB_REGISTER_ITEM(DiamondLeggings);
GMLIB_REGISTER_ITEM(DiamondBoots);

GMLIB_REGISTER_ITEM(NetheriteHelmet);
GMLIB_REGISTER_ITEM(NetheriteChestplate);
GMLIB_REGISTER_ITEM(NetheriteLeggings);
GMLIB_REGISTER_ITEM(NetheriteBoots);

} // namespace cb
