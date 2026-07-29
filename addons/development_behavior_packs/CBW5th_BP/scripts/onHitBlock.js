import { world } from '@minecraft/server';
import { returnEntity } from './function';

// ########## 挥手 ##########
world.afterEvents.playerSwingStart.subscribe((event) => {
    const player = event.player;
    if (returnEntity(player)) {
        const source = event.swingSource;
        if (source == 'Mine') {
            player.runCommand(`/function combat/hit_block`);
        } else {
            player.runCommand(`/function combat/hit_block_not`);
        }
    }
});
