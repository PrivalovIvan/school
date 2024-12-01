package domain.room.interfaces;

import domain.room.Room;

import java.util.List;
import java.util.Random;

public interface AssignTreasuresAndFoodAndEnemies {
    default void assignTreasuresAndFoodAndEnemies(List<Room> rooms) {
        Random rand = new Random();
        for (Room room : rooms) {
            int x1 = room.getRandomX() + room.getStartX() + 1, y1 = room.getRandomY() + room.getStartY() + 1;
            int x2 = room.getRandomX() + room.getStartX() + room.getWidth() - 1, y2 = room.getRandomY() + room.getStartY() + room.getHeight() - 1;
            if (room.isHasTreasure())
                for (int i = 0; i < room.getCountTreasure(); i++) {
                    room.getTreasureXY().add(new int[]{rand.nextInt(x1, x2), rand.nextInt(y1, y2)});
                }
            if (room.isHasFood())
                for (int i = 0; i < room.getCountFood(); i++) {
                    room.getFoodXY().add(new int[]{rand.nextInt(x1, x2), rand.nextInt(y1, y2)});
                }
            if (room.isHasEnemy())
                for (int i = 0; i < room.getCountEnemies(); i++) {
                    room.getEnemiesXY().add(new int[]{rand.nextInt(x1, x2), rand.nextInt(y1, y2)});
                }
        }
    }
}
