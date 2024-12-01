package domain.room.interfaces;

import domain.room.Room;

import java.util.List;

public interface AssignPoint {
    default int[] assignPoint(List<Room> rooms, int point) {
        Room room = rooms.get(point);
        return new int[]{
                room.getStartX() + rooms.get(point).getRandomX() + rooms.get(point).getWidth() / 2,
                room.getStartY() + rooms.get(point).getRandomY() + rooms.get(point).getHeight() / 2
        };
    }
}
