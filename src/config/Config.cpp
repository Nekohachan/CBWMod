#include "Config.h"
#include "Entry.h"
#include <filesystem>
#include <fstream>
#include <ll/api/Config.h>

using json = nlohmann::json;

namespace cb {

#define logger cb::Entry::getInstance().getSelf().getLogger()

// 自定义创造背包配置
CreativeInventory CreativeInventory::config;

bool CreativeInventory::Config() {
    auto& mSelf = cb::Entry::getInstance().getSelf();
    auto  path  = mSelf.getConfigDir() / "creative_inventory.json";
    return ll::config::loadConfig(config, path);
}

// 安全读取配置文件的通用辅助（可选，但这里直接实现到各函数中）

// 获取方块战利品数据
const json& getBlockLootData() {
    static json data      = json::object();
    static auto lastWrite = std::filesystem::file_time_type::min();
    auto        path      = cb::Entry::getInstance().getSelf().getConfigDir() / "block_loot.json";

    // 文件不存在则直接返回已有数据（首次为空对象）
    if (!std::filesystem::exists(path)) {
        return data;
    }

    // 检查文件大小，防止恶意/过大文件导致 bad_alloc
    try {
        auto size = std::filesystem::file_size(path);
        if (size > 5 * 1024 * 1024) { // 限制 5 MB
            logger.warn("block_loot.json 文件过大 ({} MB)，跳过解析", size / 1024 / 1024);
            return data;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        logger.error("获取 block_loot.json 文件大小失败: {}", e.what());
        return data;
    }

    std::error_code ec;
    auto            currentWrite = std::filesystem::last_write_time(path, ec);
    if (ec) {
        logger.error("获取 block_loot.json 修改时间失败: {}", ec.message());
        return data;
    }

    if (currentWrite != lastWrite) {
        std::ifstream file(path);
        if (!file.is_open()) {
            logger.error("无法打开 block_loot.json");
            return data;
        }
        try {
            data      = json::parse(file);
            lastWrite = currentWrite;
        } catch (const json::parse_error& e) {
            logger.error("解析 block_loot.json 失败: {}", e.what());
            // 保留旧数据
        } catch (const std::bad_alloc& e) {
            logger.error("解析 block_loot.json 内存不足: {}", e.what());
            // 保留旧数据
        } catch (const std::exception& e) {
            logger.error("解析 block_loot.json 发生异常: {}", e.what());
        }
    }
    return data;
}

// 获取镐子等级数据
const json& getPickaxeLevelData() {
    static json data      = json::object();
    static auto lastWrite = std::filesystem::file_time_type::min();
    auto        path      = cb::Entry::getInstance().getSelf().getConfigDir() / "pickaxe_level.json";

    if (!std::filesystem::exists(path)) {
        return data;
    }

    try {
        auto size = std::filesystem::file_size(path);
        if (size > 5 * 1024 * 1024) {
            logger.warn("pickaxe_level.json 文件过大 ({} MB)，跳过解析", size / 1024 / 1024);
            return data;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        logger.error("获取 pickaxe_level.json 文件大小失败: {}", e.what());
        return data;
    }

    std::error_code ec;
    auto            currentWrite = std::filesystem::last_write_time(path, ec);
    if (ec) {
        logger.error("获取 pickaxe_level.json 修改时间失败: {}", ec.message());
        return data;
    }

    if (currentWrite != lastWrite) {
        std::ifstream file(path);
        if (!file.is_open()) {
            logger.error("无法打开 pickaxe_level.json");
            return data;
        }
        try {
            data      = json::parse(file);
            lastWrite = currentWrite;
        } catch (const json::parse_error& e) {
            logger.error("解析 pickaxe_level.json 失败: {}", e.what());
        } catch (const std::bad_alloc& e) {
            logger.error("解析 pickaxe_level.json 内存不足: {}", e.what());
        } catch (const std::exception& e) {
            logger.error("解析 pickaxe_level.json 发生异常: {}", e.what());
        }
    }
    return data;
}

// 获取玩家属性
const json& getPlayerAttrData() {
    static json data      = json::object();
    static auto lastWrite = std::filesystem::file_time_type::min();
    auto        path      = cb::Entry::getInstance().getSelf().getDataDir() / "player_attr.json";

    if (!std::filesystem::exists(path)) {
        return data;
    }

    try {
        auto size = std::filesystem::file_size(path);
        if (size > 5 * 1024 * 1024) {
            logger.warn("player_attr.json 文件过大 ({} MB)，跳过解析", size / 1024 / 1024);
            return data;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        logger.error("获取 player_attr.json 文件大小失败: {}", e.what());
        return data;
    }

    std::error_code ec;
    auto            currentWrite = std::filesystem::last_write_time(path, ec);
    if (ec) {
        logger.error("获取 player_attr.json 修改时间失败: {}", ec.message());
        return data;
    }

    if (currentWrite != lastWrite) {
        std::ifstream file(path);
        if (!file.is_open()) {
            logger.error("无法打开 player_attr.json");
            return data;
        }
        try {
            data      = json::parse(file);
            lastWrite = currentWrite;
        } catch (const json::parse_error& e) {
            logger.error("解析 player_attr.json 失败: {}", e.what());
        } catch (const std::bad_alloc& e) {
            logger.error("解析 player_attr.json 内存不足: {}", e.what());
        } catch (const std::exception& e) {
            logger.error("解析 player_attr.json 发生异常: {}", e.what());
        }
    }
    return data;
}

// 获取物品属性
const json& getItemAttrData() {
    static json data      = json::object();
    static auto lastWrite = std::filesystem::file_time_type::min();
    auto        path      = cb::Entry::getInstance().getSelf().getConfigDir() / "item_attr.json";

    if (!std::filesystem::exists(path)) {
        return data;
    }

    try {
        auto size = std::filesystem::file_size(path);
        if (size > 5 * 1024 * 1024) {
            logger.warn("item_attr.json 文件过大 ({} MB)，跳过解析", size / 1024 / 1024);
            return data;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        logger.error("获取 item_attr.json 文件大小失败: {}", e.what());
        return data;
    }

    std::error_code ec;
    auto            currentWrite = std::filesystem::last_write_time(path, ec);
    if (ec) {
        logger.error("获取 item_attr.json 修改时间失败: {}", ec.message());
        return data;
    }

    if (currentWrite != lastWrite) {
        std::ifstream file(path);
        if (!file.is_open()) {
            logger.error("无法打开 item_attr.json");
            return data;
        }
        try {
            data      = json::parse(file);
            lastWrite = currentWrite;
        } catch (const json::parse_error& e) {
            logger.error("解析 item_attr.json 失败: {}", e.what());
        } catch (const std::bad_alloc& e) {
            logger.error("解析 item_attr.json 内存不足: {}", e.what());
        } catch (const std::exception& e) {
            logger.error("解析 item_attr.json 发生异常: {}", e.what());
        }
    }
    return data;
}

// 获取怪物等级
const json& getEntityLevelData() {
    static json data      = json::object();
    static auto lastWrite = std::filesystem::file_time_type::min();
    auto        path      = cb::Entry::getInstance().getSelf().getConfigDir() / "entity_level.json";

    if (!std::filesystem::exists(path)) {
        return data;
    }

    try {
        auto size = std::filesystem::file_size(path);
        if (size > 5 * 1024 * 1024) {
            logger.warn("entity_level.json 文件过大 ({} MB)，跳过解析", size / 1024 / 1024);
            return data;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        logger.error("获取 entity_level.json 文件大小失败: {}", e.what());
        return data;
    }

    std::error_code ec;
    auto            currentWrite = std::filesystem::last_write_time(path, ec);
    if (ec) {
        logger.error("获取 entity_level.json 修改时间失败: {}", ec.message());
        return data;
    }

    if (currentWrite != lastWrite) {
        std::ifstream file(path);
        if (!file.is_open()) {
            logger.error("无法打开 entity_level.json");
            return data;
        }
        try {
            data      = json::parse(file);
            lastWrite = currentWrite;
        } catch (const json::parse_error& e) {
            logger.error("解析 entity_level.json 失败: {}", e.what());
        } catch (const std::bad_alloc& e) {
            logger.error("解析 entity_level.json 内存不足: {}", e.what());
        } catch (const std::exception& e) {
            logger.error("解析 entity_level.json 发生异常: {}", e.what());
        }
    }
    return data;
}

// 获取物品属性
const json& getEntityCritResistanceData() {
    static json data      = json::object();
    static auto lastWrite = std::filesystem::file_time_type::min();
    auto        path      = cb::Entry::getInstance().getSelf().getConfigDir() / "entity_crit_res.json";

    if (!std::filesystem::exists(path)) {
        return data;
    }

    try {
        auto size = std::filesystem::file_size(path);
        if (size > 5 * 1024 * 1024) {
            logger.warn("entity_crit_res.json 文件过大 ({} MB)，跳过解析", size / 1024 / 1024);
            return data;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        logger.error("获取 entity_crit_res.json 文件大小失败: {}", e.what());
        return data;
    }

    std::error_code ec;
    auto            currentWrite = std::filesystem::last_write_time(path, ec);
    if (ec) {
        logger.error("获取 entity_crit_res.json 修改时间失败: {}", ec.message());
        return data;
    }

    if (currentWrite != lastWrite) {
        std::ifstream file(path);
        if (!file.is_open()) {
            logger.error("无法打开 entity_crit_res.json");
            return data;
        }
        try {
            data      = json::parse(file);
            lastWrite = currentWrite;
        } catch (const json::parse_error& e) {
            logger.error("解析 entity_crit_res.json 失败: {}", e.what());
        } catch (const std::bad_alloc& e) {
            logger.error("解析 entity_crit_res.json 内存不足: {}", e.what());
        } catch (const std::exception& e) {
            logger.error("解析 entity_crit_res.json 发生异常: {}", e.what());
        }
    }
    return data;
}

// 获取BossBar数据
const json& getBossBarData() {
    static json data      = json::object();
    static auto lastWrite = std::filesystem::file_time_type::min();
    auto        path      = cb::Entry::getInstance().getSelf().getDataDir() / "bossbar_data.json";

    if (!std::filesystem::exists(path)) {
        return data;
    }

    try {
        auto size = std::filesystem::file_size(path);
        if (size > 5 * 1024 * 1024) {
            logger.warn("bossbar_data.json 文件过大 ({} MB)，跳过解析", size / 1024 / 1024);
            return data;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        logger.error("获取 bossbar_data.json 文件大小失败: {}", e.what());
        return data;
    }

    std::error_code ec;
    auto            currentWrite = std::filesystem::last_write_time(path, ec);
    if (ec) {
        logger.error("获取 bossbar_data.json 修改时间失败: {}", ec.message());
        return data;
    }

    if (currentWrite != lastWrite) {
        std::ifstream file(path);
        if (!file.is_open()) {
            logger.error("无法打开 bossbar_data.json");
            return data;
        }
        try {
            data      = json::parse(file);
            lastWrite = currentWrite;
        } catch (const json::parse_error& e) {
            logger.error("解析 bossbar_data.json 失败: {}", e.what());
        } catch (const std::bad_alloc& e) {
            logger.error("解析 bossbar_data.json 内存不足: {}", e.what());
        } catch (const std::exception& e) {
            logger.error("解析 bossbar_data.json 发生异常: {}", e.what());
        }
    }
    return data;
}


// 获取游玩数据
const json& getPlayData() {
    static json data      = json::object();
    static auto lastWrite = std::filesystem::file_time_type::min();
    auto        path      = cb::Entry::getInstance().getSelf().getDataDir() / "play_data.json";

    if (!std::filesystem::exists(path)) {
        return data;
    }

    try {
        auto size = std::filesystem::file_size(path);
        if (size > 5 * 1024 * 1024) {
            logger.warn("play_data.json 文件过大 ({} MB)，跳过解析", size / 1024 / 1024);
            return data;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        logger.error("获取 play_data.json 文件大小失败: {}", e.what());
        return data;
    }

    std::error_code ec;
    auto            currentWrite = std::filesystem::last_write_time(path, ec);
    if (ec) {
        logger.error("获取 play_data.json 修改时间失败: {}", ec.message());
        return data;
    }

    if (currentWrite != lastWrite) {
        std::ifstream file(path);
        if (!file.is_open()) {
            logger.error("无法打开 play_data.json");
            return data;
        }
        try {
            data      = json::parse(file);
            lastWrite = currentWrite;
        } catch (const json::parse_error& e) {
            logger.error("解析 play_data.json 失败: {}", e.what());
        } catch (const std::bad_alloc& e) {
            logger.error("解析 play_data.json 内存不足: {}", e.what());
        } catch (const std::exception& e) {
            logger.error("解析 play_data.json 发生异常: {}", e.what());
        }
    }
    return data;
}

} // namespace cb