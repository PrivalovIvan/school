package presentation.commands.move;

import domain.Level;
import domain.hero.Hero;

public class MoveUp extends Move {
    public MoveUp(Level level) {
        super(level);
    }

    @Override
    protected Point getNextPosition(int currentX, int currentY) {
        return new Point(currentX, currentY - 1);
    }

    @Override
    protected boolean isValidMove(int nextX, int nextY, char[][] field) {
        return nextY > 0;
    }

    @Override
    protected void updatePlayerPosition(Hero hero, int nextX, int nextY) {
        hero.setPlayerY(nextY);
    }
}
