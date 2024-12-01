package domain.enemy.components.movement;

import domain.enemy.Enemy;
import domain.enemy.interfaces.MovementPattern;
import domain.room.RoomManager;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

import static domain.enemy.components.movement.ZombieMovement.isHeroNearby;

public class GhostMovement implements MovementPattern {
    @Override
    public void move(Enemy enemy, RoomManager roomManager) {
        Random rand = new Random();
        int[][] direction = {{0, 2}, {0, -2}, {2, 0}, {-2, 0}};
        char[][] field = roomManager.getField();
        List<Character> way = new ArrayList<>(Arrays.asList('.', '#', '+'));
        int hostValue = enemy.getHostility();
        int[][] hostility = {{hostValue, 0}, {-hostValue, 0}, {0, hostValue}, {0, -hostValue}};

        if (!enemy.isFighting()) enemy.setFighting(isHeroNearby(enemy, hostility, roomManager.getHero()));

        if (!enemy.isFighting())
            for (int i = 0; i < direction.length; i++) {
                int step = rand.nextInt(direction.length);
                enemy.setVisible(rand.nextInt(2) == 1);
                int newX = direction[step][0] + enemy.getPosX();
                int newY = direction[step][1] + enemy.getPosY();
                if (newX >= 0 && newX < field.length && newY >= 0 && newY < field[0].length) {
                    if (way.contains(field[newX][newY]) &&
                            roomManager.getHero().getPlayerX() != enemy.getPosX() &&
                            roomManager.getHero().getPlayerY() != enemy.getPosY()) {

                        field[enemy.getPosX()][enemy.getPosY()] = enemy.getPrevChar();
                        enemy.setPrevChar(field[newX][newY]);
                        if (enemy.isVisible()) field[newX][newY] = enemy.getEnemySymbol();
                        enemy.setPosX(newX);
                        enemy.setPosY(newY);
                        break;
                    }
                }
            }
    }
}
