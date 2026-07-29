#include "config/Config.h"
#include "ll/api/event/EventBus.h"
#include "ll/api/event/player/PlayerDestroyBlockEvent.h"
#include "mc/world/actor/Actor.h"
#include "mc/world/actor/item/ItemActor.h"
#include "mc/world/item/Item.h"
#include "mc/world/item/ItemStack.h"
#include "mc/world/item/enchanting/EnchantUtils.h"
#include "mc/world/level/BlockSource.h"
#include "mc/world/level/GameType.h"
#include "mc/world/level/block/Block.h"
#include "mc/world/level/dimension/Dimension.h"
#include <nlohmann/json.hpp>
#include <random>
#include <string>

using json = nlohmann::json;

namespace cb {

#define logger cb::Entry::getInstance().getSelf().getLogger()

/**
 * 在玩家附近生成指定数量的物品掉落物，自动处理堆叠限制，并模拟随机跳动效果
 *
 * @param player     玩家指针
 * @param pos        生成位置的方块坐标
 * @param item_type  物品的 ID
 * @param item_count 要生成的总数量
 */
void spawnDropItem(Player* player, const BlockPos& pos, const std::string& item_type, int item_count) {
    if (!player || item_count <= 0) return;

    auto& region = player->getDimensionBlockSource();

    // 获取原型（用于最大堆叠数）
    ItemInstance prototype(item_type, 1, 0);
    if (prototype.isNull()) {
        // logger.info("[掉落生成] 无效物品类型: {}", item_type);
        return;
    }
    int maxStackSize = prototype.getMaxStackSize();

    // int totalSpawned = 0, totalFailed = 0;

    while (item_count > 0) {
        int stackSize  = std::min(item_count, maxStackSize);
        item_count    -= stackSize;

        // 创建本次要生成的 ItemInstance
        ItemInstance stack(item_type, stackSize, 0);

        // 使用 popResource 生成掉落物
        auto* itemActor = region.getBlock(pos).popResource(region, pos, stack);
        if (!itemActor) {
            // totalFailed++;
            // logger.info("[掉落生成] popResource 失败，数量 = {}", stackSize);
            continue;
        }

        // totalSpawned++;
    }

    // logger.info("[掉落生成] 完成。成功 {} 堆，失败 {} 堆。", totalSpawned, totalFailed);
}

// 获取时运附魔的加成
int getFortuneBonus(const ItemStack& item) {
    if (EnchantUtils::hasEnchant(Enchant::Type::Fortune, item)) {
        auto                               level = EnchantUtils::getEnchantLevel(Enchant::Type::Fortune, item);
        std::random_device                 rd;
        std::mt19937                       gen(rd());
        std::uniform_int_distribution<int> intDist(0, level);
        int                                randomInt = intDist(gen);
        // logger.info("[掉落生成] 时运加成数量: {}", randomInt);
        return randomInt;
    }
    return 0;
};

// 判断是否拥有精准采集
bool testSilkTouch(const ItemStack& item) {
    if (EnchantUtils::hasEnchant(Enchant::Type::SilkTouch, item)) {
        return true;
    }
    return false;
};

// 当玩家破坏方块
auto OnPlayerDestroyedBlock = ll::event::EventBus::getInstance().emplaceListener<ll::event::PlayerDestroyBlockEvent>(
    [](ll::event::PlayerDestroyBlockEvent& event) {
        // 获取玩家
        auto& player = event.self();
        if (player.getPlayerGameType() == GameType::Creative) return;
        // 获取坐标
        auto& pos = event.pos();
        // 从维度获取方块源
        auto& block_source = player.getDimensionBlockSource();
        // 获取方块
        auto& block = block_source.getBlock(pos);
        // 获取方块ID
        auto& block_type = block.getTypeName();
        // 如果方块战利品数据中包括该方块
        if (getBlockLootData().contains(block_type)) {
            // 获取方块战利品数据
            auto block_data = getBlockLootData()[block_type];
            // 获取玩家主手物品
            const auto& main_hand_item = player.getCarriedItem();
            // 获取需求的工具
            std::string need_tool = block_data["need_tool"];
            // logger.info("[掉落生成] need_tool为: {}", need_tool);
            // 如果工具需求不为无且主手无物品
            if (need_tool != "none" && main_hand_item.isNull()) return;
            if (need_tool != "none") {
                if (need_tool == "sword" && !main_hand_item.getItem()->hasTag("minecraft:is_sword")) return;
                if (need_tool == "axe" && !main_hand_item.getItem()->hasTag("minecraft:is_axe")) return;
                if (need_tool == "pickaxe" && !main_hand_item.getItem()->hasTag("minecraft:is_pickaxe")) return;
                if (need_tool == "shovel" && !main_hand_item.getItem()->hasTag("minecraft:is_shovel")) return;
                if (need_tool == "hoe" && !main_hand_item.getItem()->hasTag("minecraft:is_hoe")) return;
            }
            if (need_tool == "pickaxe") {
                int pickaxe_level = getPickaxeLevelData()[main_hand_item.getTypeName()]["level"];
                int dig_level     = block_data["pickaxe_level"];
                // logger.info("[掉落生成] pickaxe_level为: {}", pickaxe_level);
                // logger.info("[掉落生成] dig_level为: {}", dig_level);
                if (pickaxe_level < dig_level) return;
            }
            std::string drop_item  = block_data["drop_item"];
            int         drop_count = block_data["drop_count"];
            if (!main_hand_item.isNull()) {
                if (block_data.value("can_fortune", false)) {
                    drop_count += getFortuneBonus(main_hand_item);
                }
                if (block_data.value("can_silk_touch", true) && testSilkTouch(main_hand_item)) {
                    drop_item  = block_type;
                    drop_count = 1;
                }
            }
            // logger.info("[掉落生成] 掉落物ID: {}", drop_item);
            // logger.info("[掉落生成] 掉落物数量: {}", drop_count);
            spawnDropItem(&player, pos, drop_item, drop_count);
        }
    }
);
}; // namespace cb