#include "customitem/CustomCI.h"
#include "config/Config.h"
#include "include.h"

namespace cb {

class CreativeItems {

public:
    // 配置文件
    CIConfig GetConfig() {
        cb::CIConfig::TryLoad();
        auto config = cb::CIConfig::config;
        return config;
    };
    // 创造背包注册
    void Registry(CIConfig GetConfig()) const {
        auto  config   = GetConfig();
        auto& registry = gmlib::mod::CustomCreativeItemRegistry::getInstance();
        // 注册物品分组
        for (auto& group : config.extra_groups) {
            registry.registerCreativeGroup(
                group.name,
                ::ItemInstance(group.icon),
                ::CreativeItemCategory((int)group.category)
            );
        }
        // 注册创造背包物品
        for (auto& item : config.creative_items) {
            CompoundTag* nbt = nullptr;
            if (item.nbt) {
                if (auto userdata = ::CompoundTag::fromSnbt(*item.nbt)) {
                    nbt = new ::CompoundTag(*userdata);
                }
            }
            registry.registerCreativeItem(
                ::ItemInstance(item.type, 1, 0, nbt),
                ::CreativeItemCategory((int)item.category),
                item.group
            );
        }
    }
    // 创造背包注销
    void Unregistry(CIConfig GetConfig()) const {
        auto  config   = GetConfig();
        auto& registry = gmlib::mod::CustomCreativeItemRegistry::getInstance();
        // 注销创造背包物品
        for (auto& item : config.creative_items) {
            CompoundTag* nbt = nullptr;
            if (item.nbt) {
                if (auto userdata = ::CompoundTag::fromSnbt(*item.nbt)) {
                    nbt = new ::CompoundTag(*userdata);
                }
            }
            auto itemstack = ::ItemInstance(item.type, 1, 0, nbt);
            auto category  = ::CreativeItemCategory((int)item.category);

            gmlib::mod::CustomCreativeItemRegistry::CreativeItem creative_item =
                {.mItem = itemstack, .mCategory = category, .mGroup = item.group};
            registry.unregisterCreativeItem(creative_item);
        }
    }
    static void Registry();
    static void Unregistry();
};

void RegistryCI() { CreativeItems::Registry(); };

void UnregistryCI() { CreativeItems::Unregistry(); };

} // namespace cb