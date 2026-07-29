#include "BossBar.h"
#include "Combat.h"
#include "config/Config.h"
#include "gmlib/mc/world/Level.h"
#include "gmlib/mc/world/actor/Player.h"
#include <format>
#include <string>

using json = nlohmann::json;

namespace cb {

// 获取BossBar文本（增强防御）
std::string GetBossBarTitle(gmlib::GMPlayer& player) {
    // 1. 获取 level，判空
    auto level = gmlib::GMLevel::getInstance();
    if (!level) {
        return "";
    }

    // 2. 获取玩家名称（非空检查由调用方保证）
    auto player_name = player.getRealName();
    if (player_name.empty()) {
        return "";
    }

    // 3. 使用 value() 安全读取 JSON 数据
    json player_attr         = getPlayerAttrData().value(player_name, defaultAttr);
    json player_block_attr   = getBlockAttr().value(player_name, defaultBlockAttr);
    json player_bossbar_data = getBossBarData().value(player_name, defaultBossBarData);
    json player_play_data    = getPlayData().value(player_name, defaultPlayData);

    // 主开关
    if (!player_bossbar_data.value("main_switch", false)) {
        return "";
    }

    // 当前时间
    time_t t = time(nullptr);
    tm     ts{};
    localtime_s(&ts, &t);
    char buf[24] = {0};
    strftime(buf, 24, "%Y-%m-%d %H:%M:%S", &ts);
    std::string time_str(buf);

    // 游玩时长（分）
    int play_time = player_play_data.value("play_time", 0);

    // 延迟
    auto ping       = player.getAvgPing();
    auto ping_color = (ping >= 100) ? "§c" : (ping >= 50 ? "§e" : "§a");

    // TPS
    auto tps       = level->getServerCurrentTps();
    auto tps_color = (tps / 20.0 < 0.5) ? "§c" : (tps / 20.0 < 0.85 ? "§e" : "§a");

    // 格挡值（安全读取）
    double max_block_value = player_block_attr.value("max_block_value", 0.0);
    double block_value = player_block_attr.value("block_value", -66666.6);

    // 组装文本（用 value() 判断开关）
    std::vector<std::string> parts;
    if (player_bossbar_data.value("time", false)) {
        parts.push_back(std::format("§g当前时间:§2{}", time_str));
    }
    if (player_bossbar_data.value("play_time", false)) {
        parts.push_back(std::format("§g游玩时长§g:§2{}§7(分)", play_time));
    }
    if (player_bossbar_data.value("ping", false)) {
        parts.push_back(std::format("§g延迟:{}{}ms", ping_color, ping));
    }
    if (player_bossbar_data.value("tps", false)) {
        parts.push_back(std::format("§gTPS:{}{}", tps_color, tps));
    }
    if (player_bossbar_data.value("block_value", false)) {
        parts.push_back(std::format("§b格挡值:{:.2f}/{:.2f}", block_value, max_block_value));
    }

    // 拼接标题
    std::string title;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) title += " §i|| ";
        title += parts[i];
    }
    return title;
}

// BossBar 循环（增强防御）
void BossBarLoop(Player& player) {
    // 1. 验证玩家有效
    if (!player.isAlive() || !player.isPlayerInitialized()) {
        return;
    }

    // 2. 安全转型（若 GMLIB 的 GMPlayer 为派生类）
    auto* gmPlayer = static_cast<gmlib::GMPlayer*>(&player);
    if (!gmPlayer) {
        return;
    }

    // 3. 获取标题
    auto title = GetBossBarTitle(*gmPlayer);

    // 4. 更新或移除 BossBar
    if (title.empty()) {
        gmPlayer->removeClientBossbar(1000);
    } else {
        gmPlayer->setClientBossbar(1000, title, 0.0f); // percent = 0 表示不显示进度
        gmPlayer->updateClientBossbarName(1000, title);
    }
}

} // namespace cb