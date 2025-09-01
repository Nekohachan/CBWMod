// ConfigManager.h
#pragma once

#include "config/Config.h"
#include <string>
#include <unordered_map>


namespace cb {

class ConfigManager {
private:
    json                                         config;
    std::unordered_map<std::string, json>        toolConfigs;
    std::unordered_map<std::string, json>        armorConfigs;
    std::unordered_map<std::string, std::string> repairMaterials;

    // 私有构造函数，单例模式
    ConfigManager() = default;

public:
    // 删除拷贝构造函数和赋值运算符
    ConfigManager(const ConfigManager&)            = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

    static ConfigManager& getInstance() {
        static ConfigManager instance;
        return instance;
    }

    bool        loadConfig(const std::string& configPath);
    const json& getToolConfig(const std::string& toolName) const;
    const json& getArmorConfig(const std::string& armorName) const;
    std::string getRepairMaterial(const std::string& materialKey) const;
};

} // namespace cb