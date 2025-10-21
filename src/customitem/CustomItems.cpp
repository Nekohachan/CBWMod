/**
 * 自动生成的物品类文件
 * 生成时间: 2025-10-14 20:18:34
 * 源配置: item.json
 * 请勿手动修改此文件，所有更改应在配置文件中进行
 */

#include "config/Config.h"
#include "mc/world/actor/RenderParams.h"
#include <mc/deps/shared_types/legacy/item/UseAnimation.h>
#include <mc/world/item/Item.h>
#include <mc/world/item/ItemStackBase.h>
#include <mc/world/item/VanillaItemNames.h>
#include <mc/world/level/block/Block.h>
#include <modapi/item/CustomItemRegistry.h>
#include <modapi/item/base/ICustomArmorItem.h>
#include <modapi/item/base/ICustomItem.h>
#include <modapi/item/base/ICustomToolItem.h>
#include <modapi/item/types/DamageChance.h>
#include <modapi/item/types/ItemIcon.h>
#include <modapi/item/types/RepairItems.h>
#include <modapi/item/types/mc/HumanoidArmorItem.h>

using namespace cb;
using namespace modapi;

// 类前置声明
class WoodenSword;
class WoodenAxe;
class WoodenPickaxe;
class WoodenShovel;
class WoodenHoe;
class StoneSword;
class StoneAxe;
class StonePickaxe;
class StoneShovel;
class StoneHoe;
class IronSword;
class IronAxe;
class IronPickaxe;
class IronShovel;
class IronHoe;
class GoldenSword;
class GoldenAxe;
class GoldenPickaxe;
class GoldenShovel;
class GoldenHoe;
class DiamondSword;
class DiamondAxe;
class DiamondPickaxe;
class DiamondShovel;
class DiamondHoe;
class NetheriteSword;
class NetheriteAxe;
class NetheritePickaxe;
class NetheriteShovel;
class NetheriteHoe;
class LeatherHelmet;
class LeatherChestplate;
class LeatherLeggings;
class LeatherBoots;
class GoldenHelmet;
class GoldenChestplate;
class GoldenLeggings;
class GoldenBoots;
class ChainmailHelmet;
class ChainmailChestplate;
class ChainmailLeggings;
class ChainmailBoots;
class IronHelmet;
class IronChestplate;
class IronLeggings;
class IronBoots;
class DiamondHelmet;
class DiamondChestplate;
class DiamondLeggings;
class DiamondBoots;
class NetheriteHelmet;
class NetheriteChestplate;
class NetheriteLeggings;
class NetheriteBoots;


// 生成的物品类定义
class WoodenSword : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    WoodenSword() : ICustomToolItem(VanillaItemNames::WoodenSword()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("wooden_sword"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.wooden_sword.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }

    // 耐久度
    short getItemDurability() const override { return 59; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Wooden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_sword", "minecraft:is_tool", "minecraft:wooden_tier"};
        return tags;
    }

    // 工具类型判断
    bool isSword() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 2; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_sword_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }

    // 燃料相关
    bool  isFuel() const override { return true; }
    float getFurnaceBurnInterval() const override { return 1; }
};
class WoodenAxe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    WoodenAxe() : ICustomToolItem(VanillaItemNames::WoodenAxe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("wooden_axe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.wooden_axe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 59; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Wooden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_axe", "minecraft:is_tool", "minecraft:wooden_tier"};
        return tags;
    }

    // 工具类型判断
    bool isAxe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 2; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_axe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class WoodenPickaxe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    WoodenPickaxe() : ICustomToolItem(VanillaItemNames::WoodenPickaxe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("wooden_pickaxe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.wooden_pickaxe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 59; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Wooden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:wooden_tier"};
        return tags;
    }

    // 工具类型判断
    bool isPickaxe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 2; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // AND 条件
        if (block.hasTag("minecraft:is_pickaxe_item_destructible") && block.hasTag("!minecraft:stone_tier_destructible")
            && block.hasTag("!minecraft:iron_tier_destructible")
            && block.hasTag("!minecraft:diamond_tier_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class WoodenShovel : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    WoodenShovel() : ICustomToolItem(VanillaItemNames::WoodenShovel()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("wooden_shovel"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.wooden_shovel.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 59; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Wooden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_shovel", "minecraft:is_tool", "minecraft:wooden_tier"};
        return tags;
    }

    // 工具类型判断
    bool isShovel() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 2; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_shovel_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class WoodenHoe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    WoodenHoe() : ICustomToolItem(VanillaItemNames::WoodenHoe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("wooden_hoe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.wooden_hoe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 59; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Wooden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_hoe", "minecraft:is_tool", "minecraft:wooden_tier"};
        return tags;
    }

    // 工具类型判断
    bool isHoe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 2; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_hoe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class StoneSword : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    StoneSword() : ICustomToolItem(VanillaItemNames::StoneSword()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("stone_sword"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.stone_sword.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }

    // 耐久度
    short getItemDurability() const override { return 131; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_sword", "minecraft:is_tool", "minecraft:stone_tier"};
        return tags;
    }

    // 工具类型判断
    bool isSword() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 4; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_sword_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }
};
class StoneAxe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    StoneAxe() : ICustomToolItem(VanillaItemNames::StoneAxe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("stone_axe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.stone_axe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 131; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_axe", "minecraft:is_tool", "minecraft:stone_tier"};
        return tags;
    }

    // 工具类型判断
    bool isAxe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 4; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_axe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class StonePickaxe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    StonePickaxe() : ICustomToolItem(VanillaItemNames::StonePickaxe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("stone_pickaxe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.stone_pickaxe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 131; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:stone_tier"};
        return tags;
    }

    // 工具类型判断
    bool isPickaxe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 4; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // AND 条件
        if (block.hasTag("minecraft:is_pickaxe_item_destructible || minecraft:stone_tier_destructible")
            && block.hasTag("!minecraft:iron_tier_destructible")
            && block.hasTag("!minecraft:diamond_tier_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class StoneShovel : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    StoneShovel() : ICustomToolItem(VanillaItemNames::StoneShovel()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("stone_shovel"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.stone_shovel.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 131; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_shovel", "minecraft:is_tool", "minecraft:stone_tier"};
        return tags;
    }

    // 工具类型判断
    bool isShovel() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 4; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_shovel_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class StoneHoe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    StoneHoe() : ICustomToolItem(VanillaItemNames::StoneHoe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("stone_hoe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.stone_hoe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 131; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Stone, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_hoe", "minecraft:is_tool", "minecraft:stone_tier"};
        return tags;
    }

    // 工具类型判断
    bool isHoe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 4; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_hoe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class IronSword : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    IronSword() : ICustomToolItem(VanillaItemNames::IronSword()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("iron_sword"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.iron_sword.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }

    // 耐久度
    short getItemDurability() const override { return 250; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_sword", "minecraft:is_tool", "minecraft:iron_tier"};
        return tags;
    }

    // 工具类型判断
    bool isSword() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 6; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_sword_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }
};
class IronAxe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    IronAxe() : ICustomToolItem(VanillaItemNames::IronAxe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("iron_axe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.iron_axe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 250; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_axe", "minecraft:is_tool", "minecraft:iron_tier"};
        return tags;
    }

    // 工具类型判断
    bool isAxe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 6; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_axe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class IronPickaxe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    IronPickaxe() : ICustomToolItem(VanillaItemNames::IronPickaxe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("iron_pickaxe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.iron_pickaxe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 250; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:iron_tier"};
        return tags;
    }

    // 工具类型判断
    bool isPickaxe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 6; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // AND 条件
        if (block.hasTag("minecraft:is_pickaxe_item_destructible || minecraft:stone_tier_destructible || "
                         "minecraft:iron_tier_destructible")
            && block.hasTag("!minecraft:diamond_tier_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class IronShovel : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    IronShovel() : ICustomToolItem(VanillaItemNames::IronShovel()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("iron_shovel"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.iron_shovel.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 250; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_shovel", "minecraft:is_tool", "minecraft:iron_tier"};
        return tags;
    }

    // 工具类型判断
    bool isShovel() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 6; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_shovel_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class IronHoe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    IronHoe() : ICustomToolItem(VanillaItemNames::IronHoe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("iron_hoe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.iron_hoe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 250; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Iron, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_hoe", "minecraft:is_tool", "minecraft:iron_tier"};
        return tags;
    }

    // 工具类型判断
    bool isHoe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 6; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_hoe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class GoldenSword : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    GoldenSword() : ICustomToolItem(VanillaItemNames::GoldenSword()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("golden_sword"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.golden_sword.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }

    // 耐久度
    short getItemDurability() const override { return 32; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_sword", "minecraft:is_tool", "minecraft:golden_tier"};
        return tags;
    }

    // 工具类型判断
    bool isSword() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 12; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_sword_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }
};
class GoldenAxe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    GoldenAxe() : ICustomToolItem(VanillaItemNames::GoldenAxe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("golden_axe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.golden_axe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 32; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_axe", "minecraft:is_tool", "minecraft:golden_tier"};
        return tags;
    }

    // 工具类型判断
    bool isAxe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 12; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_axe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class GoldenPickaxe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    GoldenPickaxe() : ICustomToolItem(VanillaItemNames::GoldenPickaxe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("golden_pickaxe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.golden_pickaxe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 32; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:golden_tier"};
        return tags;
    }

    // 工具类型判断
    bool isPickaxe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 12; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // AND 条件
        if (block.hasTag("minecraft:is_pickaxe_item_destructible") && block.hasTag("!minecraft:stone_tier_destructible")
            && block.hasTag("!minecraft:iron_tier_destructible")
            && block.hasTag("!minecraft:diamond_tier_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class GoldenShovel : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    GoldenShovel() : ICustomToolItem(VanillaItemNames::GoldenShovel()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("golden_shovel"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.golden_shovel.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 32; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_shovel", "minecraft:is_tool", "minecraft:golden_tier"};
        return tags;
    }

    // 工具类型判断
    bool isShovel() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 12; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_shovel_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class GoldenHoe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    GoldenHoe() : ICustomToolItem(VanillaItemNames::GoldenHoe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("golden_hoe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.golden_hoe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 32; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Golden, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_hoe", "minecraft:is_tool", "minecraft:golden_tier"};
        return tags;
    }

    // 工具类型判断
    bool isHoe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 12; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_hoe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };
};
class DiamondSword : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    DiamondSword() : ICustomToolItem(VanillaItemNames::DiamondSword()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("diamond_sword"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.diamond_sword.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }

    // 耐久度
    short getItemDurability() const override { return 1561; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_sword", "minecraft:is_tool", "minecraft:diamond_tier"};
        return tags;
    }

    // 工具类型判断
    bool isSword() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 8; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_sword_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 锻造台合成支持
    bool isSmithingTransformable() const override { return true; }
};
class DiamondAxe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    DiamondAxe() : ICustomToolItem(VanillaItemNames::DiamondAxe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("diamond_axe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.diamond_axe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 1561; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_axe", "minecraft:is_tool", "minecraft:diamond_tier"};
        return tags;
    }

    // 工具类型判断
    bool isAxe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 8; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_axe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };


    // 锻造台合成支持
    bool isSmithingTransformable() const override { return true; }
};
class DiamondPickaxe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    DiamondPickaxe() : ICustomToolItem(VanillaItemNames::DiamondPickaxe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("diamond_pickaxe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.diamond_pickaxe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 1561; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:diamond_tier"};
        return tags;
    }

    // 工具类型判断
    bool isPickaxe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 8; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // OR 条件
        if (block.hasTag("minecraft:is_pickaxe_item_destructible") || block.hasTag("minecraft:stone_tier_destructible")
            || block.hasTag("minecraft:iron_tier_destructible")
            || block.hasTag("minecraft:diamond_tier_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };


    // 锻造台合成支持
    bool isSmithingTransformable() const override { return true; }
};
class DiamondShovel : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    DiamondShovel() : ICustomToolItem(VanillaItemNames::DiamondShovel()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("diamond_shovel"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.diamond_shovel.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 1561; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_shovel", "minecraft:is_tool", "minecraft:diamond_tier"};
        return tags;
    }

    // 工具类型判断
    bool isShovel() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 8; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_shovel_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };


    // 锻造台合成支持
    bool isSmithingTransformable() const override { return true; }
};
class DiamondHoe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    DiamondHoe() : ICustomToolItem(VanillaItemNames::DiamondHoe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("diamond_hoe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.diamond_hoe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 1561; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Diamond, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_hoe", "minecraft:is_tool", "minecraft:diamond_tier"};
        return tags;
    }

    // 工具类型判断
    bool isHoe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 8; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_hoe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };


    // 锻造台合成支持
    bool isSmithingTransformable() const override { return true; }
};
class NetheriteSword : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    NetheriteSword() : ICustomToolItem(VanillaItemNames::NetheriteSword()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("netherite_sword"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.netherite_sword.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }

    // 耐久度
    short getItemDurability() const override { return 2031; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_sword", "minecraft:is_tool", "minecraft:netherite_tier"};
        return tags;
    }

    // 工具类型判断
    bool isSword() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 9; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_sword_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 防火属性
    bool isFireResistant() const override { return true; }
};
class NetheriteAxe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    NetheriteAxe() : ICustomToolItem(VanillaItemNames::NetheriteAxe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("netherite_axe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.netherite_axe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 2031; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_axe", "minecraft:is_tool", "minecraft:netherite_tier"};
        return tags;
    }

    // 工具类型判断
    bool isAxe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 9; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_axe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };

    // 防火属性
    bool isFireResistant() const override { return true; }
};
class NetheritePickaxe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    NetheritePickaxe() : ICustomToolItem(VanillaItemNames::NetheritePickaxe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("netherite_pickaxe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.netherite_pickaxe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 2031; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_pickaxe", "minecraft:is_tool", "minecraft:netherite_tier"};
        return tags;
    }

    // 工具类型判断
    bool isPickaxe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 9; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // OR 条件
        if (block.hasTag("minecraft:is_pickaxe_item_destructible") || block.hasTag("minecraft:stone_tier_destructible")
            || block.hasTag("minecraft:iron_tier_destructible")
            || block.hasTag("minecraft:diamond_tier_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };

    // 防火属性
    bool isFireResistant() const override { return true; }
};
class NetheriteShovel : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    NetheriteShovel() : ICustomToolItem(VanillaItemNames::NetheriteShovel()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("netherite_shovel"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.netherite_shovel.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 2031; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_shovel", "minecraft:is_tool", "minecraft:netherite_tier"};
        return tags;
    }

    // 工具类型判断
    bool isShovel() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 9; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_shovel_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };

    // 防火属性
    bool isFireResistant() const override { return true; }
};
class NetheriteHoe : public ICustomToolItem {
public:
    // 构造函数 - 使用原版物品名称
    NetheriteHoe() : ICustomToolItem(VanillaItemNames::NetheriteHoe()) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("netherite_hoe"); }

    // 显示名称 (本地化键)
    std::string getDisplayName() const override { return "item.netherite_hoe.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }


    // 耐久度
    short getItemDurability() const override { return 2031; }

    // 修复材料
    std::vector<RepairItems> getRepairItems() const override {
        RepairItemsList          config;
        auto                     RepairAmount = static_cast<float>(getItemDurability()) / 4;
        std::vector<RepairItems> repairitems  = {RepairItems(config.Netherite, RepairAmount)};
        return repairitems;
    }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_hoe", "minecraft:is_tool", "minecraft:netherite_tier"};
        return tags;
    }

    // 工具类型判断
    bool isHoe() const override { return true; }

    // 是否为挖掘工具
    bool isDiggerItem() const override { return true; }

    // 挖掘速度
    float getMiningSpeed() const override { return 9; }

    // 可破坏的方块判断
    bool canDestroySpecial(Block const& block) const override {
        // 简单条件判断
        if (block.hasTag("minecraft:is_hoe_item_destructible")) {
            return true;
        }
        return false;
    }

    // 挖掘效果类型
    Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const override {
        return Interactions::Mining::MineBlockItemEffectType::DiggerItem;
    }

    // 手持动作
    bool isHandEquipped() const override { return true; }


    // 使用事件 (耐久消耗)
    void executeEvent(ItemStackBase& item, std::string const&, RenderParams& rp) const override {
        auto ac = rp.getActorTarget(::SharedTypes::Legacy::FilterSubject::Holder);
        item.hurtAndBreak(1, ac);
    };

    // 防火属性
    bool isFireResistant() const override { return true; }
};
class LeatherHelmet : public ICustomArmorItem {
public:
    // 构造函数
    LeatherHelmet() : ICustomArmorItem(VanillaItemNames::LeatherHelmet(), HumanoidArmorItem::Tier::Leather) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("leather_helmet"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.leather_helmet.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 55; }

    // 修复材料
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
    // 构造函数
    LeatherChestplate() : ICustomArmorItem(VanillaItemNames::LeatherChestplate(), HumanoidArmorItem::Tier::Leather) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("leather_chestplate"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.leather_chestplate.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 80; }

    // 修复材料
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
    // 构造函数
    LeatherLeggings() : ICustomArmorItem(VanillaItemNames::LeatherLeggings(), HumanoidArmorItem::Tier::Leather) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("leather_leggings"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.leather_leggings.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 75; }

    // 修复材料
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
    // 构造函数
    LeatherBoots() : ICustomArmorItem(VanillaItemNames::LeatherBoots(), HumanoidArmorItem::Tier::Leather) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("leather_boots"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.leather_boots.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 65; }

    // 修复材料
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
    // 构造函数
    GoldenHelmet() : ICustomArmorItem(VanillaItemNames::GoldenHelmet(), HumanoidArmorItem::Tier::Gold) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("golden_helmet"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.golden_helmet.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 77; }

    // 修复材料
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
    // 构造函数
    GoldenChestplate() : ICustomArmorItem(VanillaItemNames::GoldenChestplate(), HumanoidArmorItem::Tier::Gold) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("golden_chestplate"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.golden_chestplate.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 112; }

    // 修复材料
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
    // 构造函数
    GoldenLeggings() : ICustomArmorItem(VanillaItemNames::GoldenLeggings(), HumanoidArmorItem::Tier::Gold) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("golden_leggings"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.golden_leggings.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 105; }

    // 修复材料
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
    // 构造函数
    GoldenBoots() : ICustomArmorItem(VanillaItemNames::GoldenBoots(), HumanoidArmorItem::Tier::Gold) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("golden_boots"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.golden_boots.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 91; }

    // 修复材料
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
    // 构造函数
    ChainmailHelmet() : ICustomArmorItem(VanillaItemNames::ChainmailHelmet(), HumanoidArmorItem::Tier::Iron) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("chainmail_helmet"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.chainmail_helmet.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 165; }

    // 修复材料
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
    // 构造函数
    ChainmailChestplate() : ICustomArmorItem(VanillaItemNames::ChainmailChestplate(), HumanoidArmorItem::Tier::Iron) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("chainmail_chestplate"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.chainmail_chestplate.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 240; }

    // 修复材料
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
    // 构造函数
    ChainmailLeggings() : ICustomArmorItem(VanillaItemNames::ChainmailLeggings(), HumanoidArmorItem::Tier::Iron) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("chainmail_leggings"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.chainmail_leggings.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 225; }

    // 修复材料
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
    // 构造函数
    ChainmailBoots() : ICustomArmorItem(VanillaItemNames::ChainmailBoots(), HumanoidArmorItem::Tier::Iron) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("chainmail_boots"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.chainmail_boots.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 195; }

    // 修复材料
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
    // 构造函数
    IronHelmet() : ICustomArmorItem(VanillaItemNames::IronHelmet(), HumanoidArmorItem::Tier::Iron) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("iron_helmet"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.iron_helmet.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 165; }

    // 修复材料
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
    // 构造函数
    IronChestplate() : ICustomArmorItem(VanillaItemNames::IronChestplate(), HumanoidArmorItem::Tier::Iron) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("iron_chestplate"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.iron_chestplate.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 240; }

    // 修复材料
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
    // 构造函数
    IronLeggings() : ICustomArmorItem(VanillaItemNames::IronLeggings(), HumanoidArmorItem::Tier::Iron) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("iron_leggings"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.iron_leggings.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 225; }

    // 修复材料
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
    // 构造函数
    IronBoots() : ICustomArmorItem(VanillaItemNames::IronBoots(), HumanoidArmorItem::Tier::Iron) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("iron_boots"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.iron_boots.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 195; }

    // 修复材料
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
    // 构造函数
    DiamondHelmet() : ICustomArmorItem(VanillaItemNames::DiamondHelmet(), HumanoidArmorItem::Tier::Diamond) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("diamond_helmet"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.diamond_helmet.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 363; }

    // 修复材料
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

    // 锻造台合成支持
    bool isSmithingTransformable() const override { return true; }
};
class DiamondChestplate : public ICustomArmorItem {
public:
    // 构造函数
    DiamondChestplate() : ICustomArmorItem(VanillaItemNames::DiamondChestplate(), HumanoidArmorItem::Tier::Diamond) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("diamond_chestplate"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.diamond_chestplate.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 528; }

    // 修复材料
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

    // 锻造台合成支持
    bool isSmithingTransformable() const override { return true; }
};
class DiamondLeggings : public ICustomArmorItem {
public:
    // 构造函数
    DiamondLeggings() : ICustomArmorItem(VanillaItemNames::DiamondLeggings(), HumanoidArmorItem::Tier::Diamond) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("diamond_leggings"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.diamond_leggings.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 495; }

    // 修复材料
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

    // 锻造台合成支持
    bool isSmithingTransformable() const override { return true; }
};
class DiamondBoots : public ICustomArmorItem {
public:
    // 构造函数
    DiamondBoots() : ICustomArmorItem(VanillaItemNames::DiamondBoots(), HumanoidArmorItem::Tier::Diamond) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("diamond_boots"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.diamond_boots.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 429; }

    // 修复材料
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

    // 锻造台合成支持
    bool isSmithingTransformable() const override { return true; }
};
class NetheriteHelmet : public ICustomArmorItem {
public:
    // 构造函数
    NetheriteHelmet() : ICustomArmorItem(VanillaItemNames::NetheriteHelmet(), HumanoidArmorItem::Tier::Netherite) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("netherite_helmet"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.netherite_helmet.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 407; }

    // 修复材料
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
};
class NetheriteChestplate : public ICustomArmorItem {
public:
    // 构造函数
    NetheriteChestplate()
    : ICustomArmorItem(VanillaItemNames::NetheriteChestplate(), HumanoidArmorItem::Tier::Netherite) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("netherite_chestplate"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.netherite_chestplate.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 592; }

    // 修复材料
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
};
class NetheriteLeggings : public ICustomArmorItem {
public:
    // 构造函数
    NetheriteLeggings()
    : ICustomArmorItem(VanillaItemNames::NetheriteLeggings(), HumanoidArmorItem::Tier::Netherite) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("netherite_leggings"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.netherite_leggings.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 555; }

    // 修复材料
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
};
class NetheriteBoots : public ICustomArmorItem {
public:
    // 构造函数
    NetheriteBoots() : ICustomArmorItem(VanillaItemNames::NetheriteBoots(), HumanoidArmorItem::Tier::Netherite) {};

    // 贴图图标 - 使用显式构造函数
    ItemIcon getIcon() const override { return ItemIcon("netherite_boots"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.netherite_boots.name"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 耐久度
    short getItemDurability() const override { return 481; }

    // 修复材料
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
};

// 物品注册
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
