package presentation;

import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.terminal.Terminal;
import domain.GameSession;
import domain.Level;
import domain.hero.Hero;
import domain.room.RoomManager;
import lombok.Setter;

import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

public class GameRenderer {
    private final Terminal terminal;
    @Setter
    private RoomManager rooms;
    private FogWar fogWar;
    private int width;
    private int height;
    @Setter
    private Hero hero;
    private final Level level;
    private final Map<Character, TextColor.ANSI> enemyColors = new HashMap<>();
    private final Map<String, StatEntry> stats = new LinkedHashMap<>();

    public GameRenderer(Terminal terminal, Level level) throws IOException {
        this.terminal = terminal;
        this.rooms = level.getRoomManager();
        this.hero = level.getHero();
        terminal.setCursorVisible(false);
        this.level = level;
        enemyColors.put('z', TextColor.ANSI.GREEN);
        enemyColors.put('v', TextColor.ANSI.RED);
        enemyColors.put('g', TextColor.ANSI.WHITE);
        enemyColors.put('O', TextColor.ANSI.YELLOW_BRIGHT);
        enemyColors.put('s', TextColor.ANSI.WHITE);
        loadLevel();
        stats.put("Level:", new StatEntry(0));
        stats.put("Hits:", new StatEntry(11));
        stats.put("(", new StatEntry(18));
        stats.put("Strength:", new StatEntry(25));
        stats.put("Gold:", new StatEntry(36));
        stats.put("Armor:", new StatEntry(48));
        stats.put("Exp:", new StatEntry(60));
    }

    public void loadLevel() {
        level.updateField();
        width = rooms.getField().length;
        height = rooms.getField()[0].length;
        this.fogWar = new FogWar(width, height, rooms);
        rooms.getField()[rooms.getExitX()][rooms.getExitY()] = FieldChars.EXIT;
    }

    public void renderField() throws IOException {
        terminal.clearScreen();
        level.processEnemies();
        fogWar.updateVisibility(hero.getPlayerX(), hero.getPlayerY(), rooms.getField());
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (j == height - 1)
                    terminal.putCharacter('|');
                terminal.setCursorPosition(i, j);
                char displayTile = getVisibleTile(rooms.getField()[i][j], fogWar.getVisibility(i, j));
                if (displayTile == FieldChars.CORRIDOR && fogWar.getVisibility(i, j) == FieldChars.TileVisibility.REMEMBERED) {
                    terminal.setForegroundColor(TextColor.ANSI.CYAN);
                } else {
                    terminal.setForegroundColor(TextColor.ANSI.YELLOW);
                }
                if (i == hero.getPlayerX() && j == hero.getPlayerY()) {
                    terminal.setForegroundColor(TextColor.ANSI.YELLOW_BRIGHT);
                    displayTile = FieldChars.PLAYER;
                }
                if (enemyColors.containsKey(displayTile)) {
                    terminal.setForegroundColor(enemyColors.get(displayTile));
                }
                if (rooms.getField()[i][j] == FieldChars.EXIT) {
                    terminal.setForegroundColor(TextColor.ANSI.BLUE_BRIGHT);
                }
                terminal.putCharacter(displayTile);
            }
        }
        terminal.flush();
    }

    private char getVisibleTile(char originalTile, FieldChars.TileVisibility visibility) {
        return switch (visibility) {
            case REMEMBERED -> {
                if (originalTile == FieldChars.CORRIDOR || fogWar.isWall(originalTile)) {
                    yield originalTile;
                } else {
                    yield FieldChars.DEFAULT;
                }
            }
            case VISIBLE -> originalTile;
            default -> FieldChars.DEFAULT;
        };
    }

    public void renderStats() throws IOException {
        level.getGameSession().getGameData(level.getHero());
        terminal.setForegroundColor(TextColor.ANSI.YELLOW_BRIGHT);
        GameSession gs = level.getGameSession();
        stats.get("Level:").setValue(String.valueOf(level.getLevel()));
        stats.get("Hits:").setValue(String.valueOf(gs.getHits()));
        stats.get("(").setValue(String.valueOf(gs.getMaxHits()));
        stats.get("Strength:").setValue(String.valueOf(gs.getStrength()));
        stats.get("Gold:").setValue(String.valueOf(gs.getGold()));
        stats.get("Armor:").setValue(String.valueOf(gs.getArmor()));
        stats.get("Exp:").setValue(String.valueOf(gs.getExp()));
        int i = 0, currentPosition = 0;
        for (var k : stats.keySet()) {
            StatEntry stat = stats.get(k);
            if (i > 0) {
                int minSpacing = 2;
                currentPosition = Math.max(currentPosition + minSpacing, stat.getBasePosition());
            } else {
                currentPosition = stat.getBasePosition();
            }
            renderStatLabel(currentPosition, 24, k);
            currentPosition += k.length();
            String value = stat.getValue();
            if (k.equals("(")) {
                value += ")";
            }
            if (value != null && !value.isEmpty()) {
                renderStatLabel(currentPosition, 24, value);
                currentPosition += value.length();
            }
            ++i;
        }
        terminal.setForegroundColor(TextColor.ANSI.DEFAULT);
        terminal.flush();
    }

    private void renderStatLabel(int x, int y, String label) throws IOException {
        terminal.setCursorPosition(x, y);
        terminal.putString(label);
    }

}
