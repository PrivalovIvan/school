package domain.enemy.interfaces;

import domain.enemy.Enemy;
import domain.room.RoomManager;

public interface MovementPattern {
    void move(Enemy enemy, RoomManager roomManager);
}
