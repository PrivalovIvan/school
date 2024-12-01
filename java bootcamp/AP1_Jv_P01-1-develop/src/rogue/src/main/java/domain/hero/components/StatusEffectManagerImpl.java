package domain.hero.components;

import domain.enemy.components.attack.StatusEffect;
import domain.hero.interfaces.attack.StatusEffectManager;
import lombok.Data;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

@Data
public class StatusEffectManagerImpl implements StatusEffectManager {
    private Map<StatusEffect, Integer> statusEffects = new HashMap<>();

    @Override
    public void applyStatusEffect(StatusEffect effect, int duration) {
//        statusEffects.put(effect, duration);
        statusEffects.merge(effect, duration, Integer::sum);
    }

    @Override
    public void updateStatusEffects() {
        Iterator<Map.Entry<StatusEffect, Integer>> iterator = statusEffects.entrySet().iterator();
        while (iterator.hasNext()) {
            Map.Entry<StatusEffect, Integer> entry = iterator.next();
            if (entry.getValue() > 1) {
                statusEffects.put(entry.getKey(), entry.getValue() - 1);
            } else {
                iterator.remove();
            }
        }
    }

    @Override
    public boolean hasStatusEffect(StatusEffect effect) {
        return statusEffects.containsKey(effect);
    }
}
