package domain.room.interfaces;

import domain.room.RoomManager;

@FunctionalInterface
public interface AssignFieldGame {
    char[][] assignFieldGame(RoomManager roomManager);
}
