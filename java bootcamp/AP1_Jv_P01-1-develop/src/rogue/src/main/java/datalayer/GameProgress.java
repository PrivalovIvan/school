package datalayer;

import domain.BackPack;
import domain.GameSession;
import domain.enemy.components.attack.StatusEffect;
import domain.items.Item;
import lombok.Getter;
import lombok.Setter;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

@Getter
@Setter
public class GameProgress {
    private Data currentGameState;
    private BackPack backPack;
    private Item armor;
    private Item weapon;
    private GameSession gameSession;
    private Map<StatusEffect, Integer> statusEffects;
    private List<Data> gameStats;

    public GameProgress() {
        this.gameStats = new ArrayList<>();
        this.currentGameState = new Data();
    }

    public void reset() {
        this.currentGameState = new Data();
        this.backPack = null;
        this.armor = null;
        this.weapon = null;
        this.gameSession = null;
        this.statusEffects = null;
    }
}
