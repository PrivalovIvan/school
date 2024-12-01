package domain.room.components;

import domain.enemy.Enemy;
import domain.enemy.list.*;
import domain.room.RoomManager;
import lombok.Data;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

@Data
public class EnemyFactory {

    public List<Enemy> initEnemies(RoomManager roomManager) {
        return new ArrayList<>(Arrays.asList(new Zombie(roomManager), new Vampire(roomManager), new Ghost(roomManager),
                new Ogre(roomManager), new SnakeMagician(roomManager)));
    }

}
