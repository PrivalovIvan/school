package presentation.states.inventory;

import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.terminal.Terminal;
import domain.Level;
import domain.hero.Hero;
import domain.items.Item;
import lombok.AllArgsConstructor;
import presentation.ScreensRendererUtils;
import presentation.states.ScreenState;

import java.io.IOException;
import java.util.List;

import static presentation.ScreensRendererUtils.printItems;
import static presentation.ScreensRendererUtils.selectItem;

@AllArgsConstructor
public class Armor implements ScreenState {
    private final Terminal terminal;
    private final Level level;

    @Override
    public void render() throws IOException {
        Hero hero = level.getHero();
        List<Item> items = hero.getBackpack().getItemsByType(domain.items.interfaces.Armor.class);
        ScreensRendererUtils.terminalSettings(terminal, TextColor.ANSI.WHITE);
        terminal.putString("Armors (1-9):");
        printItems(terminal, items);
        int n = items.size();
        Character ch = selectItem(terminal, n);
        if (ch != null && ch != '0') {
            int index = (ch - '0') - 1;
            Item it = items.get(index);
            if (hero.getArmor() == null) {
                hero.useItem(it);
            } else {
                hero.discardItem(it, level);
                hero.equipItem(it);
            }
            hero.getBackpack().remove(it);
        }
    }
}
