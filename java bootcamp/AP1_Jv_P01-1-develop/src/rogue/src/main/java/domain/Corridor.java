package domain;

import domain.room.RoomManager;
import lombok.Data;
import presentation.FieldChars;

import java.util.ArrayList;
import java.util.List;

@Data
public class Corridor {
    private RoomManager rooms;
    private List<int[][]> horizontalCorridors;
    private List<int[][]> verticalCorridors;

    public Corridor(RoomManager rooms) {
        this.rooms = rooms;
        this.horizontalCorridors = new ArrayList<>();
        this.verticalCorridors = new ArrayList<>();
    }

    private void findCorridors() {
        horizontalCorridors.clear();
        verticalCorridors.clear();

        horizontalCorridors.add(new int[][]{rooms.getRooms().get(0).getDoors()[1], rooms.getRooms().get(1).getDoors()[3]});
        horizontalCorridors.add(new int[][]{rooms.getRooms().get(1).getDoors()[1], rooms.getRooms().get(2).getDoors()[3]});

        horizontalCorridors.add(new int[][]{rooms.getRooms().get(3).getDoors()[1], rooms.getRooms().get(4).getDoors()[3]});
        horizontalCorridors.add(new int[][]{rooms.getRooms().get(4).getDoors()[1], rooms.getRooms().get(5).getDoors()[3]});

        horizontalCorridors.add(new int[][]{rooms.getRooms().get(6).getDoors()[1], rooms.getRooms().get(7).getDoors()[3]});
        horizontalCorridors.add(new int[][]{rooms.getRooms().get(7).getDoors()[1], rooms.getRooms().get(8).getDoors()[3]});

        verticalCorridors.add(new int[][]{rooms.getRooms().get(0).getDoors()[2], rooms.getRooms().get(3).getDoors()[0]});
        verticalCorridors.add(new int[][]{rooms.getRooms().get(3).getDoors()[2], rooms.getRooms().get(6).getDoors()[0]});

        verticalCorridors.add(new int[][]{rooms.getRooms().get(1).getDoors()[2], rooms.getRooms().get(4).getDoors()[0]});
        verticalCorridors.add(new int[][]{rooms.getRooms().get(4).getDoors()[2], rooms.getRooms().get(7).getDoors()[0]});

        verticalCorridors.add(new int[][]{rooms.getRooms().get(2).getDoors()[2], rooms.getRooms().get(5).getDoors()[0]});
        verticalCorridors.add(new int[][]{rooms.getRooms().get(5).getDoors()[2], rooms.getRooms().get(8).getDoors()[0]});
    }

    private void addVerticalCorridors() {
        for (int[][] c : verticalCorridors) {
            int x1 = c[0][0], y1 = c[0][1] += 1, x2 = c[1][0], y2 = c[1][1];
            if (x1 < x2) {
                x2++;
                y2--;
            } else if (x1 > x2) {
                x2--;
                y2--;
            }
            while (x1 != x2 || y1 != y2) {
                if (y1 < y2) rooms.getField()[x1][y1++] = FieldChars.CORRIDOR;
                if (y1 > y2) rooms.getField()[x1][y1--] = FieldChars.CORRIDOR;
                if (x1 > x2) rooms.getField()[x1--][y1] = FieldChars.CORRIDOR;
                if (x1 < x2) rooms.getField()[x1++][y1] = FieldChars.CORRIDOR;
            }
        }
    }

    private void addHorizontalCorridors() {
        for (int[][] c : horizontalCorridors) {
            int x1 = c[0][0] + 1, y1 = c[0][1], x2 = c[1][0], y2 = c[1][1];
            while (x1 != x2 || y1 != y2) {
                if (y1 > y2) rooms.getField()[x1][y1--] = FieldChars.CORRIDOR;
                if (y1 < y2) rooms.getField()[x1][y1++] = FieldChars.CORRIDOR;
                if (x1 > x2) rooms.getField()[x1--][y1] = FieldChars.CORRIDOR;
                if (x1 < x2) rooms.getField()[x1++][y1] = FieldChars.CORRIDOR;

            }
        }
    }

    public void addCorridorsToField() {
        findCorridors();
        addHorizontalCorridors();
        addVerticalCorridors();
    }
}
