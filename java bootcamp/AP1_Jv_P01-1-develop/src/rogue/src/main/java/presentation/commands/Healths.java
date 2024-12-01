package presentation.commands;

import com.googlecode.lanterna.terminal.Terminal;
import domain.Level;
import lombok.AllArgsConstructor;
import presentation.states.GameContext;

@AllArgsConstructor
public class Healths implements Command {
    private final Terminal terminal;
    private final GameContext gameContext;
    private final Level level;

    @Override
    public void execute() {
        gameContext.setCurrentState(new presentation.states.inventory.Healths(terminal, level));
    }
}
