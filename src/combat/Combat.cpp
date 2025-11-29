#include "config/Config.h"
#include <iomanip>
#include <iostream>
#include <sstream>

// 事件监听
// #include "ila/event/minecraft/world/actor/player/PlayerChangeSlotEvent.h"
#include "ll/api/event/EventBus.h"
#include "ll/api/event/entity/ActorHurtEvent.h"
#include "ll/api/event/player/PlayerPickUpItemEvent.h"
#include "ll/api/service/Bedrock.h"
#include "mc/world/actor/Actor.h"
#include "mc/world/actor/ActorDamageSource.h"
#include "mc/world/actor/ActorType.h"
#include "mc/world/actor/item/ItemActor.h"
#include "mc/world/level/Level.h"
#include <string>


namespace cb {

// 初始化描述
ItemStack initialize_lore(ItemStack& item) {
    cb::Attributes::Config();
    auto config = cb::Attributes::config;
    auto lore   = item.getCustomLore();
    if (lore.empty()) {
        if (config.slot == "mainhand") {
            lore.emplace_back("\n§r§7在主手时 ：");
        }
        if (config.slot == "offhand") {
            lore.emplace_back("\n§r§7在副手时 ：");
        }
        if (config.slot == "head") {
            lore.emplace_back("\n§r§7戴在头上时 ：");
        }
        if (config.slot == "chest") {
            lore.emplace_back("\n§r§7穿在身上时 ：");
        }
        if (config.slot == "legs") {
            lore.emplace_back("\n§r§7穿在腿上时 ：");
        }
        if (config.slot == "feet") {
            lore.emplace_back("\n§r§7穿在脚上时 ：");
        }
        if (config.attack_damage != 0) {
            std::stringstream str;
            str << "\n§r§2" << config.attack_damage << " 攻击伤害" << std::endl;
            lore.emplace_back(str.str());
        }
        if (config.attack_speed != 0) {
            std::stringstream str;
            str << "\n§r§2" << config.attack_speed << " 攻击速度" << std::endl;
            lore.emplace_back(str.str());
        }
        if (config.sweep_range != 0) {
            std::stringstream str;
            str << "\n§r§2" << config.sweep_range << " 横扫范围" << std::endl;
            lore.emplace_back(str.str());
        }
        if (config.sweep_damage != 0) {
            std::stringstream str;
            str << "\n§r§2" << config.sweep_damage * 100 << "% 横扫倍率" << std::endl;
            lore.emplace_back(str.str());
        }
    }
    item.setCustomLore(lore);
    return item;
}

// 刷新描述
ItemStack refresh_lore(ItemStack& item) {
    item      = initialize_lore(item);
    auto lore = item.getCustomLore();
    item.setCustomLore(lore);
    return item;
}

auto player_pickup_item = ll::event::EventBus::getInstance().emplaceListener<ll::event::player::PlayerPickUpItemEvent>(
    [](ll::event::player::PlayerPickUpItemEvent& event) {
        auto item                = event.itemActor().item();
        event.itemActor().item() = initialize_lore(item);
    },
    ll::event::EventPriority::Normal // 优先级
);


auto mob_onhurt = ll::event::EventBus::getInstance().emplaceListener<ll::event::entity::ActorHurtEvent>(
    [](ll::event::entity::ActorHurtEvent& event) {
        // event.cancel(); // 取消事件
        // 获取level实例
        auto level = ll::service::getLevel();
        if (!level) {
            return;
        }

        // 伤害源
        auto& damage_source = event.source();
        // 如果伤害来源是实体
        if (damage_source.isEntitySource()) {
            // 获取造成伤害的实体
            auto attacker_uniqueID = damage_source.getDamagingEntityUniqueID();
            // 如果造成伤害的为玩家
            float damage;
            if (damage_source.getDamagingEntityType() == ActorType::Player) {
                auto attacker = level->getPlayer(attacker_uniqueID);
            } else {
                auto attacker = level->getMob(attacker_uniqueID);
            }


            // 获取受到伤害的实体
            auto target_uniqueID = damage_source.getEntityUniqueID();
            // 如果受到伤害的为玩家
            if (damage_source.getEntityType() == ActorType::Player) {
                auto target = level->getPlayer(target_uniqueID);
            } else {
                auto target = level->getMob(target_uniqueID);
            }
        }
    },
    ll::event::EventPriority::High // 优先级
);


} // namespace cb