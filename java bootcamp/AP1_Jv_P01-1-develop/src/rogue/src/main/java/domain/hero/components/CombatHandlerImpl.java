package domain.hero.components;

import datalayer.DataLayer;
import domain.Character;
import domain.enemy.list.Vampire;
import domain.hero.interfaces.attack.CombatHandler;

import java.util.Random;

public class CombatHandlerImpl implements CombatHandler {
    private static final int HIT_PROBABILITY_RANGE = 10;

    @Override
    public void combat(Character attacker, Character target) {
        if (!evasion(attacker, target)) {
            DataLayer.getInstance().incrementTotalMissed();
            return;
        }
        DataLayer.getInstance().incrementTotalHits();
        attack(attacker, target);
    }

    @Override
    public void attack(Character attacker, Character target) {
        if (target instanceof Vampire && ((Vampire) target).getFirstHitForVampire() == 0) {
            ((Vampire) target).setFirstHitForVampire(1);
            return;
        }
        target.setHealth(target.getHealth() - attacker.getStrength());
    }

    @Override
    public boolean evasion(Character attacker, Character target) {
        Random rand = new Random();
        int dexterityDifference = Math.max(0, attacker.getDexterity() - target.getDexterity());
        return dexterityDifference < rand.nextInt(HIT_PROBABILITY_RANGE);
    }
}
