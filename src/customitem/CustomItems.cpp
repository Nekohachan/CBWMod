#pragma once
// 首先包含系统头文件
#include <memory>
#include <string>
#include <vector>

// 然后包含第三方库
#include <nlohmann/json.hpp>

// 最后包含项目头文件
#include "ConfigManager.h"
#include "config/Config.h"
#include "gmlib/mod/item/base/ICustomToolItem.h"
#include "mc/world/item/VanillaItemNames.h"

using namespace gmlib::mod;
using json = nlohmann::json;

// 修改 ICustomToolItem 基类或创建适配器
class ConfigurableToolItem : public ICustomToolItem {
protected:
    std::string configKey;

    const json& getConfig() const { return ConfigManager::getInstance().getToolConfig(configKey); }

    template <typename T>
    T getConfigValue(const std::string& key, T defaultValue) const {
        const auto& config = getConfig();
        if (config.contains(key) && !config[key].is_null()) {
            try {
                return config[key].get<T>();
            } catch (const std::exception& e) {
                // 记录错误或使用默认值
                return defaultValue;
            }
        }
        return defaultValue;
    }

public:
    ConfigurableToolItem(const std::string& name, const std::string& configKey)
    : ICustomToolItem(name),
      configKey(configKey) {}
};


// 具体工具类


class WoodenSword : public ConfigurableToolItem {};