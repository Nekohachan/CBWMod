// 事件监听
#include "ll/api/event/EventBus.h"
#include "ll/api/event/entity/ActorHurtEvent.h"
#include "ll/api/service/Bedrock.h"
#include "mc/deps/shared_types/legacy/actor/ArmorSlot.h"
#include "mc/world/actor/Actor.h"
#include "mc/world/actor/ActorDamageSource.h"
#include "mc/world/actor/ActorType.h"
#include "mc/world/actor/Mob.h"
#include "mc/world/actor/item/ItemActor.h"
#include "mc/world/actor/player/Player.h"
#include "mc/world/effect/MobEffect.h"
#include "mc/world/effect/MobEffectInstance.h"
#include "mc/world/events/PlayerEventListener.h"
#include "mc/world/item/Item.h"
#include "mc/world/item/ItemStack.h"
#include "mc/world/level/Level.h"


namespace cb {

struct attribute {
    // 攻击力
    std::optional<float> attack = 0.0f;
    // 暴击率
    std::optional<float> crit_rate = 0.0f;
    // 暴击伤害
    std::optional<float> critical_damage = 0.0f;
    // 命中率
    std::optional<float> hit_rate = 0.0f;
    // 物理防御力
    std::optional<float> defense = 0.0f;
    // 魔法防御力
    std::optional<float> magic_defense = 0.0f;
    // 百分比减伤
    std::optional<float> percentage_damage_reduction = 0.0f;
    // 固定减伤
    std::optional<float> flat_damage_reduction = 0.0f;
    // 闪避率
    std::optional<float> avoid_rate = 0.0f;
    // 格挡率
    std::optional<float> blocking_rate = 0.0f;
    // 击退抗性
    std::optional<float> knockback_resistance = 0.0f;
    // 移速
    std::optional<float> movement = 0.0f;
    // 水下移速
    std::optional<float> water_movement = 0.0f;
    // 熔岩移速
    std::optional<float> lava_movement = 0.0f;
    // 攻击伤害
    std::optional<float> attack_damage = 0.0f;
    // 攻击速度
    std::optional<float> attack_speed = 0.0f;
    // 横扫范围
    std::optional<float> sweep_range = 0.0f;
    // 横扫倍率
    std::optional<float> sweep_damage = 0.0f;
};

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
            double damage = 6.6;

            if (damage_source.getDamagingEntityType() == ActorType::Player) {
                auto attacker = level->getPlayer(attacker_uniqueID);

                auto helmet = attacker->getArmor(SharedTypes::Legacy::ArmorSlot::Head);
                attacker->sendMessage(std::string_view(helmet.getName()));
                auto chestplate = attacker->getArmor(SharedTypes::Legacy::ArmorSlot::Torso);
                attacker->sendMessage(std::string_view(chestplate.getName()));
                auto leggings = attacker->getArmor(SharedTypes::Legacy::ArmorSlot::Legs);
                attacker->sendMessage(std::string_view(leggings.getName()));
                auto boots = attacker->getArmor(SharedTypes::Legacy::ArmorSlot::Feet);
                attacker->sendMessage(std::string_view(boots.getName()));
                auto handeq     = attacker->getAllHandEquipment();

                /* for (auto& item : equipment) {
                    auto name = item->getName();
                    attacker->sendMessage(std::string_view(name));
                } */
                // 检测力量buff
                if (attacker->hasEffect(*MobEffect::getByName("strength"))) {
                    auto effectLevel = attacker->getEffect(*MobEffect::getByName("strength"))->mAmplifier + 1;

                    double power = pow(1.3, effectLevel);
                    damage       = power * damage + (power - 1.0) / 0.3;
                }

                // 检测虚弱buff
                if (attacker->hasEffect(*MobEffect::getByName("weakness"))) {
                    auto effectLevel = attacker->getEffect(*MobEffect::getByName("weakness"))->mAmplifier + 1;

                    double power = pow(0.8, effectLevel);
                    damage       = power * damage + (power - 1.0) / 0.4;
                }

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
            event.damage() = damage;
        }
    },
    ll::event::EventPriority::Normal // 优先级
);

} // namespace cb