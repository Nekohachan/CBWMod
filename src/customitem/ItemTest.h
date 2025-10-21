#include "mc/world/item/Item.h"
#include "mc/world/item/TridentItem.h"
#include <modapi/item/CustomItemRegistry.h>

class Actor;
class BlockSource;
class Container;
class ItemStack;
class ItemStackBase;
class Level;
class Mob;
class Player;
class Vec3;

class TItem : public TridentItem {
    //    ::WeakPtr<::Item> trident = modapi::CustomItemRegistry::getInstance().getItem("minecarft:trident");

public:
    /* TridentItem() : Item("minecraft:trident", 0), trident() {}

    virtual void releaseUsing(::ItemStack& item, ::Player* player, int durationLeft) const;

    virtual bool dispense(::BlockSource& region, ::Container& container, int slot, ::Vec3 const& pos, uchar face) const;

    virtual ::ItemStack& use(::ItemStack& instance, ::Player& player) const;

    virtual bool isThrowable() const;

    virtual void hurtActor(::ItemStack& item, ::Actor& actor, ::Mob& attacker) const; */

    //virtual ~TItem() = default;
};
