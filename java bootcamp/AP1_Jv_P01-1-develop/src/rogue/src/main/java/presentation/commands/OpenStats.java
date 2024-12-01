package presentation.commands;

import com.googlecode.lanterna.terminal.Terminal;
import lombok.AllArgsConstructor;
import presentation.states.GameContext;
import presentation.states.Stats;

@AllArgsConstructor
public class OpenStats implements Command {
    private final Terminal terminal;
    private final GameContext gameContext;

    @Override
    public void execute() {
        gameContext.setCurrentState(new Stats(terminal));
    }
}
