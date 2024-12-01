package domain.enemy.components.movement;

import domain.enemy.Enemy;
import domain.enemy.interfaces.MovementPattern;
import domain.room.RoomManager;
import lombok.Data;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

import static domain.enemy.components.movement.ZombieMovement.isHeroNearby;

@Data
public class SnakeMagicianMovement implements MovementPattern {
    @Override
    public void move(Enemy enemy, RoomManager roomManager) {
        Random rand = new Random();
        char[][] field = roomManager.getField();
        int[][] direction = {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
        List<Character> way = new ArrayList<>(Arrays.asList('.', '#', '+'));
        int hostValue = enemy.getHostility();
        int[][] hostility = {{hostValue, 0}, {-hostValue, 0}, {0, hostValue}, {0, -hostValue}};

        if (!enemy.isFighting()) enemy.setFighting(isHeroNearby(enemy, hostility, roomManager.getHero()));

        if (!enemy.isFighting())
            for (int i = 0; i < direction.length; i++) {
                int step = rand.nextInt(direction.length);
                while (step == enemy.getPrevStep()) step = rand.nextInt(direction.length);
                enemy.setPrevStep(step);
                int newX = direction[step][0] + enemy.getPosX();
                int newY = direction[step][1] + enemy.getPosY();
                if (newX > 0 && newY > 0 && way.contains(field[newX][newY])) {
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
