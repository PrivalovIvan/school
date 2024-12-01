package presentation.commands.move;

import datalayer.DataLayer;
import domain.Level;
import domain.hero.Hero;
import domain.room.RoomManager;
import lombok.AllArgsConstructor;
import presentation.FieldChars;
import presentation.commands.Command;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

@AllArgsConstructor
public abstract class Move implements Command {
    private final Level level;

    protected final Set<Character> walls = new HashSet<>(Arrays.asList(
            FieldChars.WALL_HORIZONTAL,
            FieldChars.WALL_VERTICAL,
            FieldChars.WALL_CORNER_BOTTOM_LEFT,
            FieldChars.WALL_CORNER_BOTTOM_RIGHT,
            FieldChars.WALL_CORNER_TOP_LEFT,
            FieldChars.WALL_CORNER_TOP_RIGHT));
    protected final Set<Character> enemies = new HashSet<>(Arrays.asList(
            'z',
            'v',
            'g',
            'O',
            's'
    ));

    @Override
    public void execute() {
        Hero hero = level.getHero();
        RoomManager rooms = level.getRoomManager();
        int playerY = hero.getPlayerY(), playerX = hero.getPlayerX();
        char[][] field = rooms.getField();

        Point nextPosition = getNextPosition(playerX, playerY);
        int nextX = nextPosition.getX();
        int nextY = nextPosition.getY();
        char nextStep = field[nextX][nextY];
        if (walls.contains(nextStep)) {
            return;
        }

        if (enemies.contains(nextStep)) {
            RoomManager.getEnemiesOnTheMap().stream()
                    .filter(e -> e.getPosX() == nextX && e.getPosY() == nextY)
                    .findFirst()
                    .ifPresent(hero::attack);
            return;
        }

        if (isValidMove(nextX, nextY, field) && nextStep != 0) {
            DataLayer.getInstance().incrementCells();
            updatePlayerPosition(hero, nextX, nextY);
        }
    }

    protected abstract Point getNextPosition(int currentX, int currentY);

    protected abstract boolean isValidMove(int nextX, int nextY, char[][] field);

    protected abstract void updatePlayerPosition(Hero hero, int nextX, int nextY);
}
