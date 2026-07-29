#include "config/Config.h"
#include <mc/deps/shared_types/legacy/item/UseAnimation.h>
#include <mc/world/effect/MobEffect.h>
#include <mc/world/effect/MobEffectInstance.h>
#include <mc/world/item/Item.h>
#include <mc/world/item/ItemStackBase.h>
#include <modapi/effect/enum/MobEffectType.h>
#include <modapi/item/CustomItemRegistry.h>
#include <modapi/item/base/ICustomFoodItem.h>
#include <modapi/item/base/ICustomItem.h>
#include <modapi/item/types/ItemIcon.h>



using namespace cb;
using namespace modapi;

// 闪烁的西瓜片
class GlisteringMelonSlice;

class GlisteringMelonSlice : public ICustomFoodItem {
public:
    // 构造函数
    GlisteringMelonSlice() : ICustomFoodItem("minecraft:glistering_melon_slice") {};

    // 贴图图标
    ItemIcon getIcon() const override { return ItemIcon("melon_speckled"); }

    // 显示名称
    std::string getDisplayName() const override { return "item.speckled_melon.name"; }

    // 所属创造背包栏位
    SharedTypes::CreativeItemCategory getCreativeCategory() const override {
        return SharedTypes::CreativeItemCategory::Nature;
    }

    // 所属创造背包分组
    std::string getCreativeGroup() const override { return "minecraft:itemGroup.name.crop"; }

    // 最大堆叠数量
    uint8_t getItemMaxStackSize() const override { return 64; }

    // 物品标签
    std::vector<std::string> getItemTags() const override {
        std::vector<std::string> tags = {"minecraft:is_food"};
        return tags;
    }

    // 恢复饱食度
    int getNutrition() const override { return 2; }

    // 恢复饱和度
    float getSaturation() const override { return 9.6; }

    // 满饱食度是否能吃
    bool canAlwaysEat() const override { return true; }

    // 使用时间
    int getUseDuration() const override { return 32; };

    // 给予Buff
    std::vector<::MobEffectInstance> getEffects() const override {
        std::vector<MobEffectInstance> buff;
        buff.push_back(ICustomFoodItem::createEffect(MobEffectType::Regeneration, 160, 1));
        return buff;
    }
};

// 物品注册
MODAPI_REGISTER_ITEM(GlisteringMelonSlice);