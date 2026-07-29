#include "config/Config.h"
#include <gmlib/mc/world/Level.h>
#include <mc/world/actor/ActorDefinitionIdentifier.h>
#include <mc/world/actor/RenderParams.h>
#include <mc/world/actor/player/Player.h>
#include <mc/world/actor/projectile/AbstractArrow.h>
#include <mc/world/actor/projectile/Throwable.h>
#include <mc/world/actor/projectile/ThrownTrident.h>
#include <mc/world/item/Item.h>
#include <mc/world/item/ItemStack.h>
#include <mc/world/item/ItemStackBase.h>
#include <mc/world/item/enchanting/Enchant.h>
#include <mc/world/item/enchanting/EnchantUtils.h>
#include <mc/world/level/Spawner.h>
#include <mc/world/level/block/Block.h>
#include <modapi/item/CustomItemRegistry.h>
#include <modapi/item/base/ICustomItem.h>
#include <modapi/item/base/ICustomToolItem.h>
#include <modapi/item/types/DamageChance.h>
#include <modapi/item/types/ItemIcon.h>
#include <modapi/item/types/RepairItems.h>


#include "TridentItem.h"

using namespace cb;
using namespace modapi;

#define logger cb::Entry::getInstance().getSelf().getLogger()

// 三叉戟
class Trident;

class Trident : public ICustomToolItem {
    TridentItem mOriginItem;

public:
    // 构造函数
    Trident() : ICustomToolItem("minecraft:trident"), mOriginItem() { setDescriptionId("trident"); };

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("trident"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.trident.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Equipment;
    }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 1; }

    // 创造模式是否能破坏方块
    bool canDestroyInCreative() const override { return false; }

    // 耐久度
    short getItemDurability() const override { return 250; }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_trident"};
        return tags;
    }

    // 附魔类型
    Enchant::Slot getEnchantmentSlot() const override { return Enchant::Slot::Spear; }

    // 附魔能力
    int getEnchantValue() const override { return 1; }

    // 手持动作
    bool isHandEquipped() const override { return true; }

    // 新增投掷相关
    int getUseDuration() const override { return 72000; }
    
    bool isThrowable() const override { return true; }

    ItemStack& use(::ItemStack& item, ::Player& player) const override {
        // 开始蓄力（委托原版或手动）
        player.startUsingItem(item, getUseDuration());
        return item;
    }

    void releaseUsing(::ItemStack& item, ::Player* player, int durationLeft) const override {
        int useTime = getUseDuration() - durationLeft;
        if (useTime < TridentItem::THROW_THRESHOLD_TIME()) return;

        auto level = gmlib::GMLevel::getInstance();
        if (!level) return;

        if (EnchantUtils::hasEnchant(Enchant::Type::Riptide, item)) {
            if (player->isInWaterOrRain()) {
                // 获取激流附魔等级
                int riptideLevel = EnchantUtils::getEnchantLevel(Enchant::Type::Riptide, item);
                if (riptideLevel > 0) {
                    // 计算冲刺方向和力量 (力量与等级挂钩)
                    Vec3 lookDir = player->getViewVector(1.0f);
                    // 速度公式可参考原版: 0.75 * (等级 + 1) * 方向向量[reference:5]
                    float speed    = 0.75f * static_cast<float>(riptideLevel + 1);
                    Vec3  velocity = lookDir * speed;
                    // 应用速度，实现冲刺
                    player->setVelocity(velocity);
                    // 播放音效
                    auto pos = player->getFeetPos();
                    if (riptideLevel == 1) {
                        level->executeCommandEx(
                            std::format("playsound item.trident.riptide_1 @a {} {} {} 1 1", pos.x, pos.y, pos.z)
                        );
                    } else if (riptideLevel == 2) {
                        level->executeCommandEx(
                            std::format("playsound item.trident.riptide_2 @a {} {} {} 1 1", pos.x, pos.y, pos.z)
                        );
                    } else if (riptideLevel >= 3) {
                        level->executeCommandEx(
                            std::format("playsound item.trident.riptide_3 @a {} {} {} 1 1", pos.x, pos.y, pos.z)
                        );
                    }
                    // 消耗耐久
                    item.hurtAndBreak(1, player);
                }
            }
            // 阻止常规投掷
            return;
        }


        auto& spawner = level->getSpawner();

        Vec3 spawnPos = player->getEyePos();
        Vec3 lookDir  = player->getViewVector(1.0f);
        // 原版三叉戟速度约 2.5，并受蓄力时间影响（蓄满时略快）
        float speed = 2.5f + (static_cast<float>(useTime) / 72000.0f) * 1.5f;

        auto* trident = spawner.spawnProjectile(
            player->getDimensionBlockSource(),
            ActorDefinitionIdentifier("minecraft:thrown_trident"),
            player,
            spawnPos,
            lookDir * speed
        );

        if (trident) {
            // 设置所有者
            trident->setOwner(player->getOrCreateUniqueID());

            // 消耗耐久
            item.hurtAndBreak(1, player);

            if (!player->isCreative()) {
                // 设置三叉戟的物品
                if (auto* tridentPtr = static_cast<ThrownTrident*>(trident)) {
                    tridentPtr->setTridentItem(item);
                }
                // 清除玩家手上的三叉戟
                item = ItemStack::EMPTY_ITEM();

            } else {
                if (auto* tridentPtr = static_cast<ThrownTrident*>(trident)) {
                    tridentPtr->setTridentItem(item);
                    tridentPtr->setIsCreative(true);
                }
            }

            // 播放音效
            auto pos = player->getFeetPos();
            level->executeCommandEx(std::format("playsound item.trident.throw @a {} {} {} 1 1", pos.x, pos.y, pos.z));
        }
    }

    // 发射器发射逻辑
    bool
    dispense(::BlockSource& region, ::Container& container, int slot, ::Vec3 const& pos, uchar face) const override {
        return mOriginItem.dispense(region, container, slot, pos, face);
    }
};

// 物品注册
MODAPI_REGISTER_ITEM(Trident);