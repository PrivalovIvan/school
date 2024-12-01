package domain.enemy.interfaces;

import domain.enemy.Enemy;
import domain.hero.Hero;
import domain.room.RoomManager;

import java.util.List;
import java.util.Random;
import java.util.function.BiPredicate;

@FunctionalInterface
public interface AttackPattern {
    int HIT_PROBABILITY_RANGE = 10;

    void attack(Enemy enemy, RoomManager roomManager);

    default boolean isHit(Enemy enemy, Hero hero, Random rand) {
        return isHit(enemy, hero, rand, HIT_PROBABILITY_RANGE);
    }

    default boolean isHit(Enemy enemy, Hero hero, Random rand, int hitProbabilityRange) {
        int dexterityDifference = Math.max(0, enemy.getDexterity() - hero.getDexterity());
        return dexterityDifference < rand.nextInt(hitProbabilityRange);
    }

    //двигаться на встречу к герою
    default void moveTowardsHero(Enemy enemy, Hero hero, char[][] field, List<Character> passableTerrain) {
        int heroX = hero.getPlayerX(), heroY = hero.getPlayerY();
        int enemyX = enemy.getPosX(), enemyY = enemy.getPosY();

        BiPredicate<Integer, Integer> isPassable = (x, y) -> passableTerrain.contains(field[x][y]);

        if (heroX > enemyX && isPassable.test(enemyX + 1, enemyY) && heroX != enemyX + 1) {
            enemy.setPosX(enemyX + 1);
        } else if (heroX < enemyX && isPassable.test(enemyX - 1, enemyY) && heroX != enemyX - 1) {
            enemy.setPosX(enemyX - 1);
        }

        if (heroY > enemyY && isPassable.test(enemyX, enemyY + 1) && heroY > enemyY + 1) {
            enemy.setPosY(enemyY + 1);
        } else if (heroY < enemyY && isPassable.test(enemyX, enemyY - 1) && heroY > enemyY - 1) {
            enemy.setPosY(enemyY - 1);
        }
    }
}