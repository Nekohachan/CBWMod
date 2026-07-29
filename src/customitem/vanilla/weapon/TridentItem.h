#pragma once
#include "mc/_HeaderOutputPredefine.h"
#include "mc/world/item/Item.h"

class Actor;
class BlockSource;
class Container;
class ItemStack;
class ItemStackBase;
class Level;
class Mob;
class Player;
class Vec3;

class TridentItem : public ::Item {
public:
    TridentItem() : Item("minecraft:trident", 0) {}

    virtual void releaseUsing(::ItemStack& item, ::Player* player, int durationLeft) const;

    virtual bool dispense(::BlockSource& region, ::Container& container, int slot, ::Vec3 const& pos, uchar face) const;

    virtual int getEnchantSlot() const;

    virtual int getEnchantValue() const;

    virtual ::ItemStack& use(::ItemStack& instance, ::Player& player) const;

    virtual bool isThrowable() const;

    virtual void hurtActor(::ItemStack& item, ::Actor& actor, ::Mob& attacker) const;

    virtual short getMaxDamage() const;

    virtual int getAttackDamage() const;

    virtual bool canDestroyInCreative() const;

public:
    MCAPI ::Actor* _setupProjectile(::Actor* trident, ::ItemStack item, bool creative) const;

public:
    MCAPI static int const& CHARGE_THRESHOLD_TIME();

    MCAPI static int const& THROW_THRESHOLD_TIME();
};
