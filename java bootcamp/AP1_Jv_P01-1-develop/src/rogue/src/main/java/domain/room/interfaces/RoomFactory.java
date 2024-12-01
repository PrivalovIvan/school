package domain.room.interfaces;

import domain.room.Room;

import java.util.Random;

public interface RoomFactory extends RoomDoorAssign {
    default Room createRooms(int item) {
        Random rand = new Random();
        int width = rand.nextInt(4, 11);
        int height = rand.nextInt(4, 7);
        int x = (item % 3) * 26;
        int y = (item / 3) * 7;
        int distanceX = rand.nextInt(26 - width);
        int distanceY = rand.nextInt(7 - height);
        int[][] doors = assignRoom(x, y, width, height, distanceX, distanceY, item);
        return new Room.RoomBuilder()
                .setWidth(width)
                .setHeight(height)
                .setStartX(x)
                .setStartY(y)
                .setRandomDistanceX(distanceX)
                .setRandomDistanceY(distanceY)
                .setDoors(doors)
                .setHasTreasure(rand.nextInt(2) == 1)
                .setCountTreasure(rand.nextInt(1, 4))
                .setHasFood(rand.nextInt(3) == 1)
                .setCountFood(rand.nextInt(1, 3))
//                .setHasEnemy(rand.nextInt(2) == 1)
//                .setCountEnemies(rand.nextInt(4))
                .setHasEnemy(true)
                .setCountEnemies(1)
                .build();
    }
}

