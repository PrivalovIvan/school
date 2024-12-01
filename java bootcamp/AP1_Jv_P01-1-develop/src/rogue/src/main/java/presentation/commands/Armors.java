package presentation.commands;

import com.googlecode.lanterna.terminal.Terminal;
import domain.Level;
import lombok.AllArgsConstructor;
import presentation.states.GameContext;
import presentation.states.inventory.Armor;

@AllArgsConstructor
public class Armors implements Command {
    private final Terminal terminal;
    private final GameContext gameContext;
    private final Level level;

    @Override
    public void execute() {
        gameContext.setCurrentState(new Armor(terminal, level));
    }
}
