#include "CustomRecipe.h"
#include <modapi/recipe/CustomRecipeRegistry.h>

using namespace cb;
using namespace modapi;

namespace cb {

// 总是解锁
auto alwaysUnlocked = ICustomRecipe::UnlockingRequirement(RecipeUnlockingContext::AlwaysUnlocked);
// 材料类型为物品
auto ingredientTypeItem = RecipeIngredientType::Item;
// 材料类型为标签
auto ingredientTypeTag = RecipeIngredientType::Tag;

// 原版配方更改
void vanilaRecipe(CustomRecipeRegistry&);
// 方体配方
void CBWRecipe(CustomRecipeRegistry&);


void RegistryRecipe() {
    auto& registry = modapi::CustomRecipeRegistry::getInstance();
    // 注册配方
    vanilaRecipe(registry);
    CBWRecipe(registry);

    // 卸载配方
    registry.unregisterRecipe("minecraft:enchanting_table", true);
    registry.unregisterRecipe("minecraft:shield_from_crimson_planks", true);
    registry.unregisterRecipe("minecraft:shield_from_mangrove_planks", true);
    registry.unregisterRecipe("minecraft:shield_from_warped_planks", true);
    registry.unregisterRecipe("minecraft:shield", true);
    registry.unregisterRecipe("minecraft:furnace_iron", true);
    registry.unregisterRecipe("minecraft:furnace_iron_ore", true);
    registry.unregisterRecipe("minecraft:furnace_deepslate_iron_ore", true);
    registry.unregisterRecipe("minecraft:brew_water_nether_wart", true);
    registry.unregisterRecipe("minecraft:brew_awkward_ghast_tear", true);
}


// 原版配方更改
void vanilaRecipe(CustomRecipeRegistry& registry) {
    // 重锤
    registry.registerShapedRecipe(
        "minecraft:mace",
        {
            "  A",
            " B ",
            "C  "
    },
        {{"A", ICustomRecipe::Ingredient("minecraft:heavy_core")},
         {"B", ICustomRecipe::Ingredient("minecraft:stick")},
         {"C", ICustomRecipe::Ingredient("minecraft:wind_charge")}},
        ItemInstance("minecraft:mace", 1, 0),
        alwaysUnlocked,
        {"crafting_table"}
    );
    // 风弹
    registry.registerShapelessRecipe(
        "minecraft:wind_charge",
        {ICustomRecipe::Ingredient("cb:star_soil")},
        ItemInstance("minecraft:wind_charge", 4, 0),
        alwaysUnlocked,
        {"cb:magic_table"}
    );
    // 金苹果
    registry.registerShapedRecipe(
        "minecraft:golden_apple",
        {
            "ABA",
            "BCB",
            "DBD"
    },
        {{"A", ICustomRecipe::Ingredient("cb:star_soil")},
         {"B", ICustomRecipe::Ingredient("minecraft:gold_nugget")},
         {"C", ICustomRecipe::Ingredient("minecraft:apple")},
         {"D", ICustomRecipe::Ingredient("minecraft:glowstone_dust")}},
        ItemInstance("minecraft:golden_apple", 1, 0),
        alwaysUnlocked,
        {"cb:alchemy_table"}
    );
    // 闪烁的西瓜片
    registry.registerShapedRecipe(
        "minecraft:glistering_melon_slice",
        {
            "ABA",
            "BCB",
            "DBD"
    },
        {{"A", ICustomRecipe::Ingredient("cb:star_soil")},
         {"B", ICustomRecipe::Ingredient("minecraft:gold_nugget")},
         {"C", ICustomRecipe::Ingredient("minecraft:melon_block")},
         {"D", ICustomRecipe::Ingredient("minecraft:glowstone_dust")}},
        ItemInstance("minecraft:glistering_melon_slice", 4, 0),
        alwaysUnlocked,
        {"cb:alchemy_table"}
    );
    // 金胡萝卜
    registry.registerShapedRecipe(
        "minecraft:golden_carrot",
        {
            "ABA",
            "BCB",
            "DBD"
    },
        {{"A", ICustomRecipe::Ingredient("cb:star_soil")},
         {"B", ICustomRecipe::Ingredient("minecraft:gold_nugget")},
         {"C", ICustomRecipe::Ingredient("minecraft:carrots")},
         {"D", ICustomRecipe::Ingredient("minecraft:glowstone_dust")}},
        ItemInstance("minecraft:golden_carrot", 1, 0),
        alwaysUnlocked,
        {"cb:alchemy_table"}
    );
    // 粗铁烧生铁锭
    registry.registerFurnaceRecipe(
        ICustomRecipe::Ingredient("minecraft:raw_iron"),
        ItemInstance("cb:pig_iron_ingot", 1, 0),
        {"furnace", "blast_furnace"}
    );
    // 铁矿烧生铁锭
    registry.registerFurnaceRecipe(
        ICustomRecipe::Ingredient("minecraft:iron_ore"),
        ItemInstance("cb:pig_iron_ingot", 1, 0),
        {"furnace", "blast_furnace"}
    );
    // 深层铁矿烧生铁锭
    registry.registerFurnaceRecipe(
        ICustomRecipe::Ingredient("minecraft:deepslate_iron_ore"),
        ItemInstance("cb:pig_iron_ingot", 1, 0),
        {"furnace", "blast_furnace"}
    );
    // 生铁锭烧铁锭
    registry.registerFurnaceRecipe(
        ICustomRecipe::Ingredient("cb:pig_iron_ingot"),
        ItemInstance("minecraft:iron_ingot", 1, 0),
        {"blast_furnace"}
    );
    // 星壤和水瓶酿造粗制的药水
    registry.registerBrewingRecipe(
        ICustomRecipe::Ingredient("minecraft:potion", 1, 0),
        ICustomRecipe::Ingredient("cb:star_soil"),
        ICustomRecipe::Ingredient("minecraft:potion", 1, 4)
    );
    // 金苹果和粗制的药水酿造再生药水
    registry.registerBrewingRecipe(
        ICustomRecipe::Ingredient("minecraft:potion", 1, 4),
        ICustomRecipe::Ingredient("cb:star_soil"),
        ICustomRecipe::Ingredient("minecraft:potion", 1, 28)
    );
};

// 方体配方
void CBWRecipe(CustomRecipeRegistry& registry) {
    // 铁炉
    registry.registerShapedRecipe(
        "cb:iron_furnace",
        {
            "AAA",
            "A A",
            "AAA"
    },
        {{"A", ICustomRecipe::Ingredient("minecraft:iron_block")}},
        ItemInstance("cb:iron_furnace", 1, 0),
        alwaysUnlocked,
        {"crafting_table"}
    );
    // 锂锭
    registry.registerShapelessRecipe(
        "cb:lithium_ingot",
        {
            ICustomRecipe::Ingredient("cb:lithium_ore", ingredientTypeTag, 2),
            ICustomRecipe::Ingredient("cb:limestone", ingredientTypeItem, 1),
            ICustomRecipe::Ingredient("minecraft:coals", ingredientTypeTag, 2),
        },
        ItemInstance("cb:lithium_ingot", 1, 0),
        alwaysUnlocked,
        {"cb:iron_furnace"}
    );
    // 钒锭
    registry.registerShapelessRecipe(
        "cb:vanadium_ingot",
        {
            ICustomRecipe::Ingredient("cb:vanadium_ore", ingredientTypeTag, 2),
            ICustomRecipe::Ingredient("minecraft:coals", ingredientTypeTag, 2),
        },
        ItemInstance("cb:vanadium_ingot", 1, 0),
        alwaysUnlocked,
        {"cb:iron_furnace"}
    );
    // 铬锭
    registry.registerShapelessRecipe(
        "cb:chromium_ingot",
        {
            ICustomRecipe::Ingredient("cb:chromium_ore", ingredientTypeTag, 2),
            ICustomRecipe::Ingredient("minecraft:sand", ingredientTypeTag, 2),
            ICustomRecipe::Ingredient("minecraft:coals", ingredientTypeTag, 4),
        },
        ItemInstance("cb:chromium_ingot", 1, 0),
        alwaysUnlocked,
        {"cb:steel_furnace"}
    );
    // 锰锭
    registry.registerShapelessRecipe(
        "cb:manganese_ingot",
        {
            ICustomRecipe::Ingredient("cb:manganese_ore", ingredientTypeTag, 2),
            ICustomRecipe::Ingredient("minecraft:coals", ingredientTypeTag, 2),
        },
        ItemInstance("cb:manganese_ingot", 1, 0),
        alwaysUnlocked,
        {"cb:steel_furnace"}
    );
    // 铝锭来自粗铜
    registry.registerShapelessRecipe(
        "cb:aluminium_ingot_from_raw_copper",
        {
            ICustomRecipe::Ingredient("minecraft:raw_copper", ingredientTypeItem, 1),
            ICustomRecipe::Ingredient("minecraft:glowstone_dust", ingredientTypeItem, 1),
            ICustomRecipe::Ingredient("minecraft:amethyst_shard", ingredientTypeItem, 1),
        },
        ItemInstance("cb:aluminium_ingot", 1, 0),
        alwaysUnlocked,
        {"cb:alchemy_table"}
    );
    // 铝锭来自铜矿
    registry.registerShapelessRecipe(
        "cb:aluminium_ingot_from_copper_ore",
        {
            ICustomRecipe::Ingredient("minecraft:copper_ore", ingredientTypeItem, 1),
            ICustomRecipe::Ingredient("minecraft:glowstone_dust", ingredientTypeItem, 1),
            ICustomRecipe::Ingredient("minecraft:amethyst_shard", ingredientTypeItem, 1),
        },
        ItemInstance("cb:aluminium_ingot", 1, 0),
        alwaysUnlocked,
        {"cb:alchemy_table"}
    );
    // 铝锭来自深层铜矿
    registry.registerShapelessRecipe(
        "cb:aluminium_ingot_from_deepslate_copper_ore",
        {
            ICustomRecipe::Ingredient("minecraft:deepslate_copper_ore", ingredientTypeItem, 1),
            ICustomRecipe::Ingredient("minecraft:glowstone_dust", ingredientTypeItem, 1),
            ICustomRecipe::Ingredient("minecraft:amethyst_shard", ingredientTypeItem, 1),
        },
        ItemInstance("cb:aluminium_ingot", 1, 0),
        alwaysUnlocked,
        {"cb:alchemy_table"}
    );
    // 钛锭
    registry.registerShapelessRecipe(
        "cb:vanadium_ingot",
        {
            ICustomRecipe::Ingredient("cb:titanium_ore", ingredientTypeTag, 2),
            ICustomRecipe::Ingredient("minecraft:compound", 1, 0),
            ICustomRecipe::Ingredient("minecraft:coals", ingredientTypeTag, 2),
        },
        ItemInstance("cb:vanadium_ingot", 1, 0),
        alwaysUnlocked,
        {"cb:iron_furnace"}
    );
};

} // namespace cb