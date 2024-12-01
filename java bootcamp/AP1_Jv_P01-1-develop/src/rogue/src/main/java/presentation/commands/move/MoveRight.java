package presentation.commands.move;

import domain.Level;
import domain.hero.Hero;

public class MoveRight extends Move {
    public MoveRight(Level level) {
        super(level);
    }

    @Override
    protected Point getNextPosition(int currentX, int currentY) {
        return new Point(currentX + 1, currentY);
    }

    @Override
    protected boolean isValidMove(int nextX, int nextY, char[][] field) {
        return nextX < field.length - 1;
    }

    @Override
    protected void updatePlayerPosition(Hero hero, int nextX, int nextY) {
        hero.setPlayerX(nextX);
    }
}
