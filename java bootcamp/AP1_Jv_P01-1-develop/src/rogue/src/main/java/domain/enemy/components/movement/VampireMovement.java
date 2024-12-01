package domain.enemy.components.movement;

import domain.enemy.Enemy;
import domain.enemy.interfaces.MovementPattern;
import domain.room.RoomManager;

import static domain.enemy.components.movement.ZombieMovement.moveEnemyTypeZombieAndVampire;

public class VampireMovement implements MovementPattern {

    @Override
    public void move(Enemy enemy, RoomManager roomManager) {
        int[][] direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
        moveEnemyTypeZombieAndVampire(enemy, roomManager, direction);
    }


}
