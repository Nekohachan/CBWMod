import { system, world } from '@minecraft/server';

// 检测玩家药水效果
system.runInterval(() => {
    world.getAllPlayers().forEach((player) => {
        // [急迫]
        setPlayerMobEffectData(player, 'haste', 'haste');
        // [疲劳]
        setPlayerMobEffectData(player, 'mining_fatigue', 'fatigue');
    });
});

function setPlayerMobEffectData(player, effect, name) {
    const buff = player.getEffect(effect);
    const prop = `cb:${name}`;
    if (buff) {
        const amp = buff.amplifier + 1;
        if (amp != player.getProperty(prop)) {
            player.setProperty(prop, amp);
        }
    } else if (player.getProperty(prop) != 0) {
        player.setProperty(prop, 0);
    }
}
