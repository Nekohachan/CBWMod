#include "PlayData.h"
#include "config/Config.h"
#include "ll/api/event/EventBus.h"
#include "ll/api/event/player/PlayerDisconnectEvent.h"
#include "ll/api/event/player/PlayerJoinEvent.h"
#include <nlohmann/json.hpp>
#include <string>


using json = nlohmann::json;

namespace cb {

// 获取当前时间
std::string getCurrentTime() {
    time_t t = time(nullptr);
    tm     ts{};
    localtime_s(&ts, &t);
    char buf[24] = {0};
    strftime(buf, 24, "%Y-%m-%d %H:%M:%S", &ts);
    auto time = std::string(buf);
    return time;
}

// 当玩家加入游戏时
auto OnPlayerJoin = ll::event::EventBus::getInstance().emplaceListener<ll::event::PlayerJoinEvent>(
    [](ll::event::PlayerJoinEvent& event) {
        // 获取玩家
        auto& player = event.self();
        // 获取玩家名字
        auto player_name = player.getRealName();
        // 获取玩家游玩数据
        auto play_data = getPlayData().value(player_name, defaultPlayData);
        // 保存到文件
        play_data["last_join"] = getCurrentTime();
        modifyPlayData([&](json& data) { data[player_name] = play_data; });
    }
);


// 当玩家断开连接时
auto OnPlayerDisconnect = ll::event::EventBus::getInstance().emplaceListener<ll::event::PlayerDisconnectEvent>(
    [](ll::event::PlayerDisconnectEvent& event) {
        // 获取玩家
        auto& player = event.self();
        // 获取玩家名字
        auto player_name = player.getRealName();
        // 获取玩家游玩数据
        auto play_data = getPlayData().value(player_name, defaultPlayData);
        // 保存到文件
        play_data["last_left"] = getCurrentTime();
        modifyPlayData([&](json& data) { data[player_name] = play_data; });
    }
);

// 玩家游玩计时
void PlayTimeLoop(Player& player) {
    // 获取玩家名字
    auto player_name = player.getRealName();
    // 获取玩家游玩数据
    auto play_data = getPlayData().value(player_name, defaultPlayData);
    // 记录当前游玩时长
    int play_time_second = play_data["play_time_second"];
    int play_time        = play_data["play_time"];
    play_time_second++;
    if (play_time_second >= 60) {
        play_time++;
        play_time_second = 0;
    }
    // 保存到文件
    play_data["last_playing"]     = getCurrentTime();
    play_data["play_time_second"] = play_time_second;
    play_data["play_time"]        = play_time;
    modifyPlayData([&](json& data) { data[player_name] = play_data; });
}

}; // namespace cb