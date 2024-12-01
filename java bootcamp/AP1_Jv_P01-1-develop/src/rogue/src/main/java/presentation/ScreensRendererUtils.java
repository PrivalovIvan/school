package presentation;

import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.input.KeyType;
import com.googlecode.lanterna.terminal.Terminal;
import domain.hero.Hero;
import domain.items.Item;

import java.io.IOException;
import java.util.List;

public class ScreensRendererUtils {

    public static void terminalSettings(Terminal terminal, TextColor.ANSI color) throws IOException {
        terminal.clearScreen();
        terminal.setCursorPosition(0, 0);
        terminal.setForegroundColor(color);
        terminal.flush();
    }

    public static Character selectItem(Terminal terminal, int n) throws IOException {
        KeyStroke k;
        do {
            terminal.flush();
            k = terminal.readInput();
        } while (k.getKeyType() != KeyType.Escape && (k.getCharacter() < '1' || k.getCharacter() > ('0' + n)));
        return k.getCharacter();
    }

    public static void outText(Terminal terminal, String text, TextColor.ANSI color) throws IOException {
        terminalSettings(terminal, color);
        terminal.putString(text);
        do {
            terminal.flush();
        } while (terminal.readInput().getCharacter() != null && terminal.readInput().getCharacter() != ' ');
    }

    public static void printItems(Terminal terminal, List<?> items) throws IOException {
        int y = 2, n = 1;
        for (var e : items) {
            Item i = (Item) e;
            terminal.setCursorPosition(0, y++);
            terminal.putString((n++) + ". " + i.getSubType() +
                    " cost: " + i.getCost() +
                    " strength: " + i.getStrengthBoost() +
                    " health: " + i.getHealthBoost() +
                    " dexterity: " + i.getDexterityBoost()
            );
        }
    }

    public static boolean printAndSelectItems(Terminal terminal, List<?> items, Hero hero) throws IOException {
        printItems(terminal, items);
        int n = items.size();
        Character ch = selectItem(terminal, n);
        if (ch != null && ch != '0') {
            int index = (ch - '0') - 1;
            Item it = (Item) items.get(index);
            hero.applyItemEffect(it, true);
            hero.getBackpack().remove(it);
            return true;
        }
        return false;
    }
}
