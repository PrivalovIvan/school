package domain.room;

import datalayer.DataLayer;
import domain.enemy.Enemy;
import domain.hero.Hero;
import domain.items.Item;
import domain.room.components.EnemyFactory;
import domain.room.components.ItemFactory;
import domain.room.interfaces.RoomComponents;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;


@Data
public class RoomManager {
    private static final int MULTIPLY_ENEMIES_HEALTH = 5;
    private static final int MULTIPLY_ENEMIES_STRENGTH = 2;
    private static final int MULTIPLY_ENEMIES_DEXTERITY = 2;
    private static final int TOTAL_ROOMS = 9;
    private List<Room> rooms = new ArrayList<>();
    private List<Enemy> enemies = new ArrayList<>();
    private List<Item> treasures;

    private char[][] field;
    private int startRoom, endRoom;
    private int exitX, exitY;
    private int level = 1;

    private Hero hero;
    private RoomComponents roomComponents;

    @Getter
    @Setter
    private static List<Enemy> enemiesOnTheMap = new ArrayList<>();


    public RoomManager(RoomComponents roomComponents, Hero hero, EnemyFactory enemiesManager, ItemFactory itemFactory) {
        this.roomComponents = roomComponents;
        this.hero = hero;
        treasures = itemFactory.initTreasures();
        enemies = enemiesManager.initEnemies(this);
    }

    private void createRooms() {
        rooms.clear();
        enemiesOnTheMap.clear();
        for (int i = 0; i < TOTAL_ROOMS; i++) rooms.add(roomComponents.createRooms(i));
        assignStartAndEndRooms();
        identifyPointsExit();
        assignTreasuresAndFoodAndEnemies();
    }

    private void assignStartAndEndRooms() {
        int[] startAndEnd = roomComponents.assignRoomStartAndEnd(rooms);
        this.startRoom = startAndEnd[0];
        this.endRoom = startAndEnd[1];
    }

    public void assignField() {
        createRooms();
        updateEnemies();
        field = roomComponents.assignFieldGame(this);
        this.level++;
    }

    private void identifyPointsExit() {
        hero.setPosition(roomComponents.assignPoint(rooms, startRoom));
        this.exitX = roomComponents.assignPoint(rooms, endRoom)[0];
        this.exitY = roomComponents.assignPoint(rooms, endRoom)[1];
    }

    private void assignTreasuresAndFoodAndEnemies() {
        roomComponents.assignTreasuresAndFoodAndEnemies(rooms);
    }

    public static void addEnemyInTheMap(Enemy enemy) {
        enemiesOnTheMap.add(enemy);
    }

    //увеличение стат перед каждым уровнем
    public void updateEnemies() {
        enemies.forEach(this::updateEnemiesStats);
    }

    private void updateEnemiesStats(Enemy enemy) {
        int levelMultiplier = this.level - 1;
        enemy.setHealth(enemy.getHealth() + levelMultiplier * MULTIPLY_ENEMIES_HEALTH);
        enemy.setStrength(enemy.getStrength() + levelMultiplier * MULTIPLY_ENEMIES_STRENGTH);
        enemy.setDexterity(enemy.getDexterity() + levelMultiplier * MULTIPLY_ENEMIES_DEXTERITY);
    }

    public void removeDeadEnemies() {
        setEnemiesOnTheMap(
                getEnemiesOnTheMap().stream()
                        .filter(this::isEnemyAlive)
                        .collect(Collectors.toList())
        );
    }

    private boolean isEnemyAlive(Enemy enemy) {
        if (enemy.getHealth() <= 0) {
            field[enemy.getPosX()][enemy.getPosY()] = enemy.getPrevChar();
            hero.setExperience(hero.getExperience() + enemy.getExperience());
            DataLayer.getInstance().incrementEnemyDefeated();
            return false;
        }
        return true;
    }
}

