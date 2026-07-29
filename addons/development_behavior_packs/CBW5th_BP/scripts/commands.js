import { system, world } from '@minecraft/server';

system.afterEvents.scriptEventReceive.subscribe((event) => {
    if (event.id == 'cb:player_set_attack_cold') {
        const player = event.sourceEntity;
        if (!player) return; // 确保玩家存在

        const parts = event.message.split(' ');
        const value = parseInt(parts[0]);
        if (isNaN(value)) {
            console.warn(`无效的冷却值: ${parts[0]}`);
            return;
        }
        // 可选：限制范围 0~1000
        player.setProperty(
            'cb:attack_cold',
            Math.min(1000, Math.max(0, value))
        );
    }
    if (event.id == 'cb:mace_effect') {
        const attacker = event.sourceEntity;
        if (!attacker) return; // 确保攻击者存在

        const parts = event.message.split(' ');
        const fallDistance = parseFloat(parts[0]);
        if (isNaN(fallDistance)) {
            console.warn(`无效的摔落高度: ${parts[0]}`);
            return;
        }

        attacker.dimension
            .getEntities({ tags: ['cb.mace_hurter'] })
            .forEach((target) => {
                const soundLoc = target.location;
                const HeavySound = fallDistance > 5.5;
                const blockBelow1 = target.dimension.getBlock({
                    x: target.location.x,
                    y: target.location.y - 1,
                    z: target.location.z,
                });
                const blockBelow2 = target.dimension.getBlock({
                    x: target.location.x,
                    y: target.location.y - 2,
                    z: target.location.z,
                });
                const isNearGround =
                    (blockBelow1 &&
                        !blockBelow1.isAir &&
                        !blockBelow1.isLiquid) ||
                    (blockBelow2 &&
                        !blockBelow2.isAir &&
                        !blockBelow2.isLiquid);
                const SmashParticlesLevel = fallDistance > 1.5;

                if (
                    !attacker.isOnGround &&
                    !target.isOnGround &&
                    !isNearGround
                ) {
                    attacker.dimension.playSound('mace.smash_air', soundLoc, {
                        volume: 1.8,
                    });
                } else {
                    attacker.dimension.playSound(
                        HeavySound
                            ? 'mace.heavy_smash_ground'
                            : 'mace.smash_ground',
                        soundLoc,
                        { volume: 1.8 }
                    );
                }

                if (SmashParticlesLevel) {
                    attacker.dimension.spawnEntity('cb:mace_slam', soundLoc);
                }

                target.removeTag('cb.mace_hurter');
            });
    }
});
