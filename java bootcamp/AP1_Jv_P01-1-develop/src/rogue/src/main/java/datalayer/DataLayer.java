package datalayer;

import com.fasterxml.jackson.databind.ObjectMapper;
import domain.GameSession;
import domain.Level;
import domain.hero.Hero;
import lombok.Getter;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class DataLayer {
    private static DataLayer instance;
    private static final String SAVE_FILE = "game_progress.json";
    private final ObjectMapper objectMapper;
    @Getter
    private GameProgress gameProgress;

    private DataLayer() {
        this.objectMapper = new ObjectMapper();
        loadProgress();
    }

    public static DataLayer getInstance() {
        if (instance == null) {
            instance = new DataLayer();
        }
        return instance;
    }

    private void loadProgress() {
        File file = new File(SAVE_FILE);
        if (file.exists()) {
            try {
                gameProgress = objectMapper.readValue(file, GameProgress.class);
            } catch (IOException e) {
                System.err.println("Error while loading progress: " + e.getMessage());
                gameProgress = new GameProgress();
            }
        } else {
            gameProgress = new GameProgress();
        }
    }

    public void saveProgress() {
        try {
            objectMapper.writeValue(new File(SAVE_FILE), gameProgress);
        } catch (IOException e) {
            System.err.println("Error while saving progress: " + e.getMessage());
        }
    }

    public void onNextLevel(Level level) {
        level.getFinallyScore();
        level.getGameSession().getGameData(level.getHero());
        gameProgress.getCurrentGameState().setScore(level.getGameSession().getExp());
        gameProgress.setBackPack(level.getHero().getBackpack());
        gameProgress.setArmor(level.getHero().getArmor());
        gameProgress.setWeapon(level.getHero().getWeapon());
        gameProgress.setGameSession(level.getGameSession());
        gameProgress.setStatusEffects(level.getHero().getStatusEffectManager().getStatusEffects());
        saveProgress();
    }

    public void winLose() {
        gameProgress.getGameStats().add(getCurrentGameState());
        gameProgress.reset();
        saveProgress();
    }

    public Data getCurrentGameState() {
        return gameProgress.getCurrentGameState();
    }

    public List<Data> getSortedGameStats() {
        List<Data> sortedStats = new ArrayList<>(gameProgress.getGameStats());
        sortedStats.sort((a, b) -> b.getScore() - a.getScore());
        return sortedStats;
    }

    public void setHero(Level level) {
        Hero hero = level.getHero();
        if (gameProgress.getArmor() != null)
            hero.useItem(gameProgress.getArmor());
        if (gameProgress.getWeapon() != null)
            hero.useItem(gameProgress.getWeapon());
        if (gameProgress.getBackPack() != null)
            hero.setBackpack(gameProgress.getBackPack());
        if (gameProgress.getGameSession() != null) {
            GameSession gs = gameProgress.getGameSession();
            hero.setMaxHealth(gs.getMaxHits());
            hero.setHealth(gs.getHits());
            hero.setStrength(gs.getStrength());
            hero.setDexterity(gs.getArmor());
            hero.setExperience(gs.getExp());
            level.setGameSession(gs);
        }
        if (gameProgress.getStatusEffects() != null)
            hero.getStatusEffectManager().setStatusEffects(gameProgress.getStatusEffects());
        level.setLevel(gameProgress.getCurrentGameState().getLevel());
    }

    public void incrementTotalTreasure() {
        gameProgress.getCurrentGameState().setTotalTreasure(gameProgress.getCurrentGameState().getTotalTreasure() + 1);
    }

    public void incrementLevel() {
        gameProgress.getCurrentGameState().setLevel(gameProgress.getCurrentGameState().getLevel() + 1);
    }

    public void incrementEnemyDefeated() {
        gameProgress.getCurrentGameState().setEnemyDefeated(gameProgress.getCurrentGameState().getEnemyDefeated() + 1);
    }

    public void incrementFood() {
        gameProgress.getCurrentGameState().setTotalFood(gameProgress.getCurrentGameState().getTotalFood() + 1);
    }

    public void incrementTotalElixir() {
        gameProgress.getCurrentGameState().setTotalElixir(gameProgress.getCurrentGameState().getTotalElixir() + 1);
    }

    public void incrementTotalScrolls() {
        gameProgress.getCurrentGameState().setTotalScrolls(gameProgress.getCurrentGameState().getTotalScrolls() + 1);
    }

    public void incrementTotalHits() {
        gameProgress.getCurrentGameState().setTotalHits(gameProgress.getCurrentGameState().getTotalHits() + 1);
    }

    public void incrementTotalMissed() {
        gameProgress.getCurrentGameState().setTotalMissed(gameProgress.getCurrentGameState().getTotalMissed() + 1);
    }

    public void incrementCells() {
        gameProgress.getCurrentGameState().setTotalCells(gameProgress.getCurrentGameState().getTotalCells() + 1);
    }

}
