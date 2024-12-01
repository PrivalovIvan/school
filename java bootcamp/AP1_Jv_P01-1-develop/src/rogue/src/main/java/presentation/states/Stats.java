package presentation.states;

import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.input.KeyType;
import com.googlecode.lanterna.terminal.Terminal;
import datalayer.Data;
import datalayer.DataLayer;
import lombok.AllArgsConstructor;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@AllArgsConstructor
public class Stats implements ScreenState {
    private final Terminal terminal;

    @Override
    public void render() throws IOException {
        boolean running = true;
        int height = terminal.getTerminalSize().getRows();
        int width = terminal.getTerminalSize().getColumns();
        int scrollPosition = 0;
        List<String> lines = getLines(width);
        while (running) {
            terminal.clearScreen();
            for (int i = 0; i < height - 1 && (i + scrollPosition) < lines.size(); i++) {
                terminal.setCursorPosition(0, i);
                String line = lines.get(i + scrollPosition);
                if (line.length() > width) {
                    line = line.substring(0, width);
                }
                terminal.putString(line);
            }
            terminal.setCursorPosition(0, height - 1);
            terminal.putString("Use ↑↓ to scroll, ESC to exit");
            terminal.flush();
            KeyStroke keyStroke = terminal.readInput();

            if (keyStroke.getKeyType() == KeyType.Escape) {
                running = false;
            } else if (keyStroke.getKeyType() == KeyType.ArrowUp && scrollPosition > 0) {
                scrollPosition--;
            } else if (keyStroke.getKeyType() == KeyType.ArrowDown &&
                    scrollPosition < Math.max(0, lines.size() - height + 1)) {
                scrollPosition++;
            }
        }
    }

    private List<String> getLines(int width) {
        List<Data> data = DataLayer.getInstance().getSortedGameStats();
        List<String> lines = new ArrayList<>();
        String separator = "-".repeat(width);
        for (Data item : data) {
            lines.add("Score: " + item.getScore());
            lines.add("Total Treasure: " + item.getTotalTreasure());
            lines.add("Level: " + item.getLevel());
            lines.add("Enemy Hits: " + item.getEnemyDefeated());
            lines.add("Total Elixir: " + item.getTotalElixir());
            lines.add("Total Scrolls: " + item.getTotalScrolls());
            lines.add("Total Hits: " + item.getTotalHits());
            lines.add("Total Missed: " + item.getTotalMissed());
            lines.add("Total cells: " + item.getTotalCells());
            lines.add("Total food: " + item.getTotalFood());
            lines.add(separator);
        }
        return lines;
    }
}
