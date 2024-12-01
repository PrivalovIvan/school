package domain.hero.interfaces.attack;

import domain.Character;

public interface CombatHandler extends Attackable, Evasionable {
    void combat(Character attacker, Character target);
}
