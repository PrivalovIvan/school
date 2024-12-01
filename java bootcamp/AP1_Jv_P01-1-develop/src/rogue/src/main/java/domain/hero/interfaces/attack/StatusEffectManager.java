package domain.hero.interfaces.attack;

import domain.enemy.components.attack.StatusEffect;

import java.util.Map;

public interface StatusEffectManager {
    void updateStatusEffects();

    void applyStatusEffect(StatusEffect effect, int duration);

    boolean hasStatusEffect(StatusEffect effect);

    Map<StatusEffect, Integer> getStatusEffects();
    void setStatusEffects(Map<StatusEffect, Integer> effects);
}
