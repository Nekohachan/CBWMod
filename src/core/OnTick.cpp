#include "Attribute.h"
#include "BossBar.h"
#include "Combat.h"
#include "LoreTest.h"
#include "PlayData.h"
#include "config/Config.h"
#include "ll/api/chrono/GameChrono.h"
#include "ll/api/coro/CoroTask.h"
#include "ll/api/service/Bedrock.h"
#include "ll/api/thread/ServerThreadExecutor.h"
#include "mc/world/actor/player/Player.h"
#include "mc/world/level/Level.h"
#include <nlohmann/json.hpp>


using namespace ll::chrono_literals;
using json = nlohmann::json;

namespace cb {

#define logger cb::Entry::getInstance().getSelf().getLogger()

// 物品描述检测循环
ll::coro::CoroTask<> OnTick(std::atomic<bool>& shouldStop) {
    int LoreTestCount = 0;
    int PlayTimeCount = 0;
    int BossBarCount  = 0;
    int MoblevelCount = 0;
    while (!shouldStop.load()) {
        try {
            // 获取level
            auto level = ll::service::getLevel();
            if (!level) {
                co_await 1_tick;
                continue;
            }
            // 遍历玩家
            level->forEachPlayer([&](Player& player) -> bool {
                // 检查玩家是否有效
                if (!player.isAlive() || !player.isPlayerInitialized()) {
                    return true;
                }
                // 物品描述检测
                if (++LoreTestCount >= 20) {
                    LoreTestCount = 0;
                    LoreTestLoop(player);
                }
                // 修改属性
                ModifiedAttributeLoop(player);
                // 格挡
                BlockLoop(player);
                // 回血
                RegenerationLoop(player);
                // 游玩时间计时
                if (++PlayTimeCount >= 20) {
                    PlayTimeCount = 0;
                    PlayTimeLoop(player);
                }
                // BossBar更新
                if (++BossBarCount >= 6) {
                    BossBarCount = 0;
                    BossBarLoop(player);
                }
                return true;
            });
            // 显血
            HealthDisplayLoop();
            // 自动添加等级
            if (++MoblevelCount >= 20) {
                MoblevelCount = 0;
                MoblevelLoop();
            }
        } catch (const std::bad_alloc& e) {
            logger.error("[OnTick] 内存分配失败: {}", e.what());
        } catch (const std::exception& e) {
            logger.error("[OnTick] 异常: {}", e.what());
        } catch (...) {
            logger.error("[OnTick] 未知异常");
        }
        // 等待 1 个游戏刻
        co_await 1_tick;
    }
}

} // namespace cb