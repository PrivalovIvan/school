package domain;

import domain.hero.Hero;
import domain.room.RoomManager;
import lombok.Data;

@Data
public class Level {
    private int level;
    private RoomManager roomManager;
    private Hero hero;
    private Corridor corridor;
    private GameSession gameSession;

    public Level(RoomManager roomManager, Hero hero, Corridor corridor, GameSession gameSession) {
        this.roomManager = roomManager;
        this.hero = hero;
        this.corridor = corridor;
        this.gameSession = gameSession;
    }

    public void updateField() {
        this.level++;
        roomManager.assignField();
        corridor.addCorridorsToField();
    }

    public void processEnemies() {
        RoomManager.getEnemiesOnTheMap().forEach(enemy -> {
            if (enemy.isFighting()) enemy.attack();
            else enemy.move();
        });
        this.roomManager.removeDeadEnemies();
    }

    public void getFinallyScore() {
        hero.setExperience(hero.getExperience() + hero.getBackpack().getGold());
    }
}

