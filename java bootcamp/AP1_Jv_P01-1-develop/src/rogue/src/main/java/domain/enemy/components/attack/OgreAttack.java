package domain.enemy.components.attack;

import domain.enemy.Enemy;
import domain.enemy.interfaces.AttackPattern;
import domain.hero.Hero;
import domain.room.RoomManager;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class OgreAttack implements AttackPattern {

    @Override
    public void attack(Enemy enemy, RoomManager roomManager) {
        Random rand = new Random();
        char[][] field = roomManager.getField();
        List<Character> way = new ArrayList<>(Arrays.asList('.', '#', '+'));

        if (enemy.isFighting() && enemy.getCounterHits() % 2 == 0) {
            Hero hero = roomManager.getHero();
            field[enemy.getPosX()][enemy.getPosY()] = enemy.getPrevChar();
            moveTowardsHero(enemy, hero, field, way);
            attackIfNearby(enemy, hero, rand);
            enemy.setPrevChar(field[enemy.getPosX()][enemy.getPosY()]);
            field[enemy.getPosX()][enemy.getPosY()] = enemy.getEnemySymbol();
        }
        enemy.setCounterHits(enemy.getCounterHits() + 1);
    }

    private void attackIfNearby(Enemy enemy, Hero hero, Random rand) {
        int[][] direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int[] coords : direction) {
            if (enemy.getPosX() + coords[0] == hero.getPlayerX() && enemy.getPosY() + coords[1] == hero.getPlayerY()) {
                if (isHit(enemy, hero, rand)) {
                    hero.setHealth(hero.getHealth() - enemy.getStrength());
                }
                break;
            }
        }
    }
}
