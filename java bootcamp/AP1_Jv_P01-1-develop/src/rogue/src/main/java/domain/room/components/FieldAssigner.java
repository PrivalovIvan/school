package domain.room.components;

import domain.enemy.Enemy;
import domain.room.Room;
import domain.room.RoomManager;
import domain.room.interfaces.AssignFieldGame;

import java.util.Arrays;
import java.util.Random;

public class FieldAssigner implements AssignFieldGame {
    @Override
    public char[][] assignFieldGame(RoomManager roomManager) {
        char[][] field = new char[80][24];
        int roomCounter = 0;
        for (Room r : roomManager.getRooms()) {
            for (int x = r.getStartX() + r.getRandomX(); x < r.getStartX() + r.getWidth() + r.getRandomX(); x++) {
                for (int y = r.getStartY() + r.getRandomY(); y < r.getHeight() + r.getStartY() + r.getRandomY(); y++) {
                    assignTile(field, r, x, y, roomCounter, roomManager);
                }
            }
            roomCounter++;
        }
        return field;
    }

    private void assignTile(char[][] field, Room r, int x, int y, int roomCounter, RoomManager roomManager) {
        if (roomManager.getStartRoom() != roomCounter && r.isHasEnemy() &&
                r.getEnemiesXY().stream().anyMatch(coords -> coords[0] == x && coords[1] == y)) {
            Enemy e = roomManager.getEnemies().get(new Random().nextInt(roomManager.getEnemies().size())).clone();
            field[x][y] = e.getEnemySymbol();
            e.setPosX(x);
            e.setPosY(y);
            RoomManager.addEnemyInTheMap(e);
        }

        if (r.isHasFood() && r.getFoodXY().stream().anyMatch(coords -> coords[0] == x && coords[1] == y)) {
            field[x][y] = 'F';
            return;
        }

        if (r.isHasTreasure() && r.getTreasureXY().stream().anyMatch(coords -> coords[0] == x && coords[1] == y)) {
            field[x][y] = 'T';
            return;
        }

        if (Arrays.stream(r.getDoors()).anyMatch(door -> door[0] == x && door[1] == y)) {
            field[x][y] = '+';
            return;
        }

        if (x == r.getWidth() + r.getStartX() - 1 + r.getRandomX() && y == r.getStartY() + r.getRandomY()) {
            field[x][y] = '┐';
        } else if (x == r.getStartX() + r.getRandomX() && y == r.getStartY() + r.getRandomY()) {
            field[x][y] = '┌';
        } else if (x == r.getStartX() + r.getRandomX() && y == r.getHeight() + r.getStartY() - 1 + r.getRandomY()) {
            field[x][y] = '└';
        } else if (x == r.getWidth() + r.getStartX() - 1 + r.getRandomX() && y == r.getHeight() + r.getStartY() - 1 + r.getRandomY()) {
            field[x][y] = '┘';
        } else if (x == r.getStartX() + r.getRandomX() || x == r.getWidth() + r.getStartX() - 1 + r.getRandomX()) {
            field[x][y] = '│';
        } else if (y == r.getStartY() + r.getRandomY() || y == r.getHeight() + r.getStartY() - 1 + r.getRandomY()) {
            field[x][y] = '─';
        } else {
            field[x][y] = '.';
        }
    }
}