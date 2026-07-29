// ########## 【返回实体】 ##########
export function returnEntity(entity, typeId) {
    return entity?.isValid && (!typeId || entity.typeId == typeId);
}
export function returnEntityMatches(entity, filter) {
    return entity?.isValid && entity.matches(filter);
}

// ########## 【物品】 ##########
export function getEquipment(entity, slot) {
    return entity.getComponent('equippable')?.getEquipment(slot);
}
export function getAllEquipment(player) {
    const equip = player.getComponent('equippable');
    if (equip) {
        return {
            hand: equip.getEquipment('Mainhand'),
            offhand: equip.getEquipment('Offhand'),
            head: equip.getEquipment('Head'),
            chest: equip.getEquipment('Chest'),
            legs: equip.getEquipment('Legs'),
            feet: equip.getEquipment('Feet'),
        };
    }
}