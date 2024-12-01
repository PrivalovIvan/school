package domain.room;

import domain.room.components.FieldAssigner;
import domain.room.interfaces.RoomComponents;

public class RoomComponentsImpl implements RoomComponents {
    FieldAssigner fieldAssigner = new FieldAssigner();

    @Override
    public char[][] assignFieldGame(RoomManager roomManager) {
        return fieldAssigner.assignFieldGame(roomManager);
    }
}
