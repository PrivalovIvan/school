package domain.enemy.components.movement;

import domain.enemy.Enemy;
import domain.enemy.interfaces.MovementPattern;
import domain.room.RoomManager;

import static domain.enemy.components.movement.ZombieMovement.moveEnemyTypeZombieAndVampire;

public class OgreMovement implements MovementPattern {
    @Override
    public void move(Enemy enemy, RoomManager roomManager) {
        int[][] direction = {{0, 2}, {0, -2}, {2, 0}, {-2, 0}};
        moveEnemyTypeZombieAndVampire(enemy, roomManager, direction);
    }
}