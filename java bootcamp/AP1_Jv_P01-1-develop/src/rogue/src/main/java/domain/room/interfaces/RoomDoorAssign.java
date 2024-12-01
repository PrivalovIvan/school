package domain.room.interfaces;

import java.util.Random;

public interface RoomDoorAssign {
    /**
     * Метод для установки дверей комнаты в зависимости от параметра item
     *
     * @param x         начальная позиция по X
     * @param y         начальная позиция по Y
     * @param width     ширина комнаты
     * @param height    высота комнаты
     * @param distanceX смещение по X
     * @param distanceY смещение по Y
     * @param item      определяет расположение дверей взависимости от местоположения комнаты
     * @return массив координат дверей
     */
    default int[][] assignRoom(int x, int y, int width, int height, int distanceX, int distanceY, int item) {
        Random rand = new Random();
        int[][] doors = new int[4][2];
        if (item > 2 && item < 9)
            doors[0] = new int[]{rand.nextInt(x + distanceX + 1, x + width + distanceX - 1), y + distanceY};
        if (item != 2 && item != 5 && item != 8)
            doors[1] = new int[]{x + distanceX + width - 1, rand.nextInt(y + distanceY + 1, y + distanceY + height - 1)};
        if (item >= 0 && item < 6)
            doors[2] = new int[]{rand.nextInt(x + distanceX + 1, x + width + distanceX - 1), y + distanceY + height - 1};
        if (item != 0 && item != 3 && item != 6)
            doors[3] = new int[]{x + distanceX, rand.nextInt(y + distanceY + 1, y + distanceY + height - 1)};
        return doors;
    }
}


