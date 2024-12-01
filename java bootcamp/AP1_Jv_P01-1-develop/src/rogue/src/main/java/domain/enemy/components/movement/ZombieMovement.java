package domain.enemy.components.movement;

import domain.enemy.Enemy;
import domain.enemy.interfaces.MovementPattern;
import domain.hero.Hero;
import domain.room.RoomManager;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class ZombieMovement implements MovementPattern {

    @Override
    public void move(Enemy enemy, RoomManager roomManager) {
        int[][] direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        moveEnemyTypeZombieAndVampire(enemy, roomManager, direction);
    }

    static void moveEnemyTypeZombieAndVampire(Enemy enemy, RoomManager roomManager, int[][] direction) {
        Random rand = new Random();
        char[][] field = roomManager.getField();
        List<Character> way = new ArrayList<>(Arrays.asList('.', '#', '+'));
        int hostValue = enemy.getHostility();
        int[][] hostility = {{hostValue, 0}, {-hostValue, 0}, {0, hostValue}, {0, -hostValue}};

        if (!enemy.isFighting()) enemy.setFighting(isHeroNearby(enemy, hostility, roomManager.getHero()));

        if (!enemy.isFighting())
            for (int i = 0; i < direction.length; i++) {
                int step = rand.nextInt(direction.length);
                int newX = direction[step][0] + enemy.getPosX();
                int newY = direction[step][1] + enemy.getPosY();
                if (newX >= 0 && newX < field.length && newY >= 0 && newY < field[0].length) {
                    if (way.contains(field[newX][newY]) &&
                            roomManager.getHero().getPlayerX() != enemy.getPosX() &&
                            roomManager.getHero().getPlayerY() != enemy.getPosY()) {

                        field[enemy.getPosX()][enemy.getPosY()] = enemy.getPrevChar();
                        enemy.setPrevChar(field[newX][newY]);
                        field[newX][newY] = enemy.getEnemySymbol();
                        enemy.setPosX(newX);
                        enemy.setPosY(newY);
                        break;
                    }
                }
            }
    }

    public static boolean isHeroNearby(Enemy enemy, int[][] hostility, Hero hero) {
        for (int[] dir : hostility) {
            int distanceHeroX = enemy.getPosX() + dir[0];
            int distanceHeroY = enemy.getPosY() + dir[1];
            if (hero.getPlayerX() == distanceHeroX && hero.getPlayerY() == distanceHeroY) {
                return true;
            }
        }
        return false;
    }
//        else {
//            field[enemy.getPosX()][enemy.getPosY()] = enemy.getPrevChar();
//
//            Hero hero = roomManager.getHero();
//            //движение врага к герою по x
//            if (hero.getPlayerX() > enemy.getPosX() + 1 && way.contains(field[enemy.getPosX() + 1][enemy.getPosY()]))
//                enemy.setPosX(enemy.getPosX() + 1);
//            else if (hero.getPlayerX() < enemy.getPosX() - 1 && way.contains(field[enemy.getPosX() - 1][enemy.getPosY()]))
//                enemy.setPosX(enemy.getPosX() - 1);
//
//            //движение врага к герою по y
//            if (hero.getPlayerY() > enemy.getPosY() + 1 && way.contains(field[enemy.getPosX()][enemy.getPosY() + 1]))
//                enemy.setPosY(enemy.getPosY() + 1);
//            else if (hero.getPlayerY() < enemy.getPosY() - 1 && way.contains(field[enemy.getPosX()][enemy.getPosY() - 1]))
//                enemy.setPosY(enemy.getPosY() - 1);
//
//            Arrays.stream(direction).forEach(coords -> {
//                if (enemy.getPosX() + coords[0] == hero.getPlayerX() && enemy.getPosY() + coords[1] == hero.getPlayerY()) {
//                    if (Math.max(0, hero.getDexterity() - enemy.getDexterity()) < rand.nextInt(10)) {
//                        System.out.println("Промах " + enemy.getType() + ": " + counter++);
//                        return;
//                    }
//                    hero.setHealth(hero.getHealth() - enemy.getStrength());
//                }
//            });
//            enemy.setPrevChar(field[enemy.getPosX()][enemy.getPosY()]);
//            field[enemy.getPosX()][enemy.getPosY()] = enemy.getEnemySymbol();
//        }
}
