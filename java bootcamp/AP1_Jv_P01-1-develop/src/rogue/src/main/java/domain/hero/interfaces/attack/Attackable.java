package domain.hero.interfaces.attack;

import domain.Character;


// атака
@FunctionalInterface
public interface Attackable {
    void attack(Character attacker, Character target);
}
