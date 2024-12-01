package presentation.states.inventory;

import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.terminal.Terminal;
import datalayer.DataLayer;
import domain.Level;
import domain.hero.Hero;
import domain.items.Item;
import lombok.AllArgsConstructor;
import presentation.states.ScreenState;

import java.io.IOException;
import java.util.List;

import static presentation.ScreensRendererUtils.*;

@AllArgsConstructor
public class Elixir implements ScreenState {
    private final Terminal terminal;
    private final Level level;

    @Override
    public void render() throws IOException {
        Hero hero = level.getHero();
        List<Item> items = hero.getBackpack().getItemsByType(domain.items.interfaces.Elixir.class);
        terminalSettings(terminal, TextColor.ANSI.WHITE);
        terminal.putString("Elixirs (1-9):");
        printItems(terminal, items);
        int n = items.size();
        Character ch = selectItem(terminal, n);
        if (ch != null && ch != '0') {
            int index = (ch - '0') - 1;
            Item item = items.get(index);
            hero.useElixir((domain.items.interfaces.Elixir) item);
            hero.getBackpack().remove(item);
            DataLayer.getInstance().incrementTotalElixir();
        }
    }
}
