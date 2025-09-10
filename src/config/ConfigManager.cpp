// ConfigManager.cpp
#include "ConfigManager.h"
#include <fstream>
#include <iostream> // 添加用于错误输出

namespace cb {

bool ConfigManager::loadConfig(const std::string& configPath) {
    std::ifstream file(configPath);
    if (!file.is_open()) {
        std::cerr << "Failed to open config file: " << configPath << std::endl;
        return false;
    }

    try {
        file >> config;

        // 清空现有配置
        toolConfigs.clear();
        armorConfigs.clear();
        repairMaterials.clear();

        // 加载工具配置
        if (config.contains("tools")) {
            for (auto& [key, value] : config["tools"].items()) {
                toolConfigs[key] = value;
            }
        }

        // 加载盔甲配置
        if (config.contains("armors")) {
            for (auto& [key, value] : config["armors"].items()) {
                armorConfigs[key] = value;
            }
        }

        // 加载修复材料配置
        if (config.contains("repair_materials")) {
            for (auto& [key, value] : config["repair_materials"].items()) {
                repairMaterials[key] = value.get<std::string>();
            }
        }

        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing config file: " << e.what() << std::endl;
        return false;
    }
}

const json& ConfigManager::getToolConfig(const std::string& toolName) const {
    static json emptyConfig;
    auto        it = toolConfigs.find(toolName);
    return it != toolConfigs.end() ? it->second : emptyConfig;
}

const json& ConfigManager::getArmorConfig(const std::string& armorName) const {
    static json emptyConfig;
    auto        it = armorConfigs.find(armorName);
    return it != armorConfigs.end() ? it->second : emptyConfig;
}

std::string ConfigManager::getRepairMaterial(const std::string& materialKey) const {
    auto it = repairMaterials.find(materialKey);
    return it != repairMaterials.end() ? it->second : "";
}

} // namespace cb