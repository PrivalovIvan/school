package domain.room.interfaces;

import domain.room.Room;

import java.util.List;
import java.util.Random;

public interface RoomAssign {
    default int[] assignRoomStartAndEnd(List<Room> rooms) {
        Random rand = new Random();
        int startRoom = rand.nextInt(rooms.size());
        int endRoom;
        do {
            endRoom = rand.nextInt(rooms.size());
        } while (startRoom == endRoom);
        return new int[]{startRoom, endRoom};
    }
}
