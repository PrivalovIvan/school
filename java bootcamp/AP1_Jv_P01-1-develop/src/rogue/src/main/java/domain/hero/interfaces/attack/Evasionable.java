package domain.hero.interfaces.attack;


import domain.Character;

//уклонение
public interface Evasionable {
    boolean evasion(Character attacker, Character target);
}
