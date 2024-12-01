package P1;

import com.googlecode.lanterna.TerminalSize;
import com.googlecode.lanterna.terminal.DefaultTerminalFactory;
import com.googlecode.lanterna.terminal.Terminal;
import com.googlecode.lanterna.terminal.swing.SwingTerminalFrame;
import datalayer.DataLayer;
import domain.Corridor;
import domain.GameSession;
import domain.Level;
import domain.hero.Hero;
import domain.hero.components.*;
import domain.room.RoomComponentsImpl;
import domain.room.RoomManager;
import domain.room.components.EnemyFactory;
import domain.room.components.ItemFactory;
import presentation.CustomWindowListener;
import presentation.EventsHandler;
import presentation.GameRenderer;
import presentation.states.GameContext;
import presentation.states.Playing;

import java.io.IOException;
import java.util.Locale;

public class Main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        Hero hero = new Hero(new CombatHandlerImpl(), new PotionManager(), new ObjectManager(), new StatusEffectManagerImpl(), new HeroStatManagerImpl());
        RoomManager roomManager = new RoomManager(new RoomComponentsImpl(), hero, new EnemyFactory(), new ItemFactory());
        Corridor corridor = new Corridor(roomManager);
        GameSession gameSession = new GameSession();
        Level level = new Level(roomManager, hero, corridor, gameSession);
        DataLayer.getInstance().setHero(level);
        TerminalSize terminalSize = new TerminalSize(82, 26);
        Terminal terminal = new DefaultTerminalFactory().setInitialTerminalSize(terminalSize).createTerminal();
        SwingTerminalFrame terminalFrame = (SwingTerminalFrame) terminal;
        terminalFrame.addWindowListener(new CustomWindowListener(level));
        terminalFrame.setTitle("Rogue");
        GameRenderer gameRenderer = new GameRenderer(terminal, level);
        GameContext gameContext = new GameContext(gameRenderer);
        EventsHandler eventsHandler = new EventsHandler(terminal, level, gameContext, gameRenderer);

        while (true) {
            try {
                gameContext.render();
                if (gameContext.getCurrentState() instanceof Playing) {
                    eventsHandler.handleButton();
                    eventsHandler.handleEvent();
                } else {
                    gameContext.setCurrentState(new Playing(gameRenderer));
                }
            } catch (IOException e) {
                System.err.println("Exception: " + e.getMessage());
            }
        }
    }
}
