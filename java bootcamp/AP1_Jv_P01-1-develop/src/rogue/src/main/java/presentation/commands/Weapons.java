package presentation.commands;

import com.googlecode.lanterna.terminal.Terminal;
import domain.Level;
import lombok.AllArgsConstructor;
import presentation.states.GameContext;
import presentation.states.inventory.Weapon;

@AllArgsConstructor
public class Weapons implements Command {
    private final Terminal terminal;
    private final GameContext gameContext;
    private final Level level;

    @Override
    public void execute() {
        gameContext.setCurrentState(new Weapon(terminal, level));
    }
}
