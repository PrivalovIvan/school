package presentation;

import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.input.KeyType;
import com.googlecode.lanterna.terminal.Terminal;
import datalayer.DataLayer;
import domain.Corridor;
import domain.GameSession;
import domain.Level;
import domain.hero.Hero;
import domain.hero.components.*;
import domain.items.Item;
import domain.items.MapItems;
import domain.items.food.Food;
import domain.room.Room;
import domain.room.RoomComponentsImpl;
import domain.room.RoomManager;
import domain.room.components.EnemyFactory;
import domain.room.components.ItemFactory;
import presentation.commands.*;
import presentation.commands.move.MoveDown;
import presentation.commands.move.MoveLeft;
import presentation.commands.move.MoveRight;
import presentation.commands.move.MoveUp;
import presentation.itemsHandler.InventoryObserver;
import presentation.itemsHandler.ItemsPickupTask;
import presentation.states.GameContext;
import presentation.states.LoseScreen;
import presentation.states.WinScreen;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class EventsHandler {
    private final Terminal terminal;
    private RoomManager rooms;
    private Hero hero;
    private final Map<Character, Command> commands = new HashMap<>();
    private final ItemsPickupTask itemsPickupTask;
    private final GameContext gameContext;
    private final GameRenderer gameRenderer;
    private final Level level;
    private final DataLayer dataLayer;

    public EventsHandler(Terminal terminal, Level level, GameContext gameContext, GameRenderer gameRenderer) {
        this.terminal = terminal;
        this.rooms = level.getRoomManager();
        this.hero = level.getHero();
        this.level = level;
        this.itemsPickupTask = new ItemsPickupTask(level);
        this.gameContext = gameContext;
        this.gameRenderer = gameRenderer;
        this.dataLayer = DataLayer.getInstance();
        itemsPickupTask.addObserver(new InventoryObserver());
        commands.put('w', new MoveUp(level));
        commands.put('s', new MoveDown(level));
        commands.put('a', new MoveLeft(level));
        commands.put('d', new MoveRight(level));
        commands.put('h', new Weapons(terminal, gameContext, level));
        commands.put('j', new Healths(terminal, gameContext, level));
        commands.put('k', new Elixirs(terminal, gameContext, level));
        commands.put('e', new Scrolls(terminal, gameContext, level));
        commands.put('r', new Armors(terminal, gameContext, level));
        commands.put('i', new OpenStats(terminal, gameContext));
    }

    public void handleButton() throws IOException {
        terminal.flush();
        KeyStroke keyStroke = terminal.readInput();
        if (keyStroke.getKeyType() == KeyType.Escape) {
            terminal.close();
            return;
        }
        if (hero.isSleeping()) {
            hero.updateStatusEffects();
            return;
        }
        if (keyStroke.getKeyType() == KeyType.Character) {
            Character ch = keyStroke.getCharacter();
            Command command = commands.get(ch);
            if (command != null) {
                command.execute();
            }
        }
    }

    public void handleEvent() throws IOException {
        if (rooms.getField()[hero.getPlayerX()][hero.getPlayerY()] == 'T')
            itemsPickupTask.execute(generateTreasure());
        if (rooms.getField()[hero.getPlayerX()][hero.getPlayerY()] == 'W')
            itemsPickupTask.execute(findItemInMapList(new int[]{hero.getPlayerX(), hero.getPlayerY()}));
        if (rooms.getField()[hero.getPlayerX()][hero.getPlayerY()] == 'F')
            itemsPickupTask.execute(new Food());
        if (hero.getPlayerY() == rooms.getExitY() && hero.getPlayerX() == rooms.getExitX()) {
            dataLayer.incrementLevel();
            dataLayer.onNextLevel(level);
            gameRenderer.loadLevel();
        }
        if (!hero.isAlive()) {
            gameContext.setCurrentState(new LoseScreen(terminal));
            onWinOrLose();
        }
        if (level.getLevel() == 22) {
            gameContext.setCurrentState(new WinScreen(terminal));
            onWinOrLose();
        }
    }

    private void onWinOrLose() {
        dataLayer.winLose();
        level.getHero().shutdownPotionManager();
        level.setGameSession(new GameSession());
        level.getGameSession().setCurrentLevel(level);
        level.setHero(new Hero(new CombatHandlerImpl(), new PotionManager(), new ObjectManager(), new StatusEffectManagerImpl(), new HeroStatManagerImpl()));
        level.setRoomManager(new RoomManager(new RoomComponentsImpl(), level.getHero(), new EnemyFactory(), new ItemFactory()));
        level.setCorridor(new Corridor(level.getRoomManager()));
        level.setLevel(0);
        gameRenderer.setHero(level.getHero());
        gameRenderer.setRooms(level.getRoomManager());
        gameRenderer.loadLevel();
        hero = level.getHero();
        rooms = level.getRoomManager();
    }

    private static Item findItemInMapList(int[] coords) {
        for (MapItems mapItem : Item.getListItemsOfTheMap()) {
            if (arraysEqual(mapItem.getCoordsOfItem(), coords)) {
                return mapItem.getItem();
            }
        }
        return null;
    }

    private static boolean arraysEqual(int[] a, int[] b) {
        for (int i = 0; i < a.length; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    private Item generateTreasure() {
        Random rand = new Random();
        for (Room room : rooms.getRooms()) {
            if (room.getTreasureXY().stream()
                    .anyMatch(coords -> coords[0] == hero.getPlayerX()
                            && coords[1] == hero.getPlayerY())) {
                dataLayer.incrementTotalTreasure();
                return rooms.getTreasures().get(rand.nextInt(rooms.getTreasures().size()));
            }
        }
        return null;
    }

}
