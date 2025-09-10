// CustomItems.cpp
#pragma once
#include "config/Config.h"
#include "config/ConfigManager.h"
#include "gmlib/mod/item/base/ICustomToolItem.h"
#include <nlohmann/json.hpp>
#include <string>


using namespace gmlib::mod;
using json = nlohmann::json;

namespace cb { // 添加命名空间


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
class WoodenSword : public ConfigurableToolItem {
    // 实现...
};

} // namespace cb