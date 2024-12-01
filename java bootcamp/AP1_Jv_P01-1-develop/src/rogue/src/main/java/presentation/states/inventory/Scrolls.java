package presentation.states.inventory;

import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.terminal.Terminal;
import datalayer.DataLayer;
import domain.Level;
import domain.hero.Hero;
import domain.items.Item;
import domain.items.interfaces.Scroll;
import lombok.AllArgsConstructor;
import presentation.states.ScreenState;

import java.io.IOException;
import java.util.List;

import static presentation.ScreensRendererUtils.printAndSelectItems;
import static presentation.ScreensRendererUtils.terminalSettings;

@AllArgsConstructor
public class Scrolls implements ScreenState {
    private final Terminal terminal;
    private final Level level;

    @Override
    public void render() throws IOException {
        Hero hero = level.getHero();
        List<Item> items = hero.getBackpack().getItemsByType(Scroll.class);
        terminalSettings(terminal, TextColor.ANSI.WHITE);
        terminal.putString("Scrolls (1-9):");
        if (printAndSelectItems(terminal, items, hero)) {
            DataLayer.getInstance().incrementTotalScrolls();
        }
    }
}
