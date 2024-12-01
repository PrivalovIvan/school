package domain;

import com.fasterxml.jackson.annotation.JsonIgnore;
import domain.hero.Hero;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
public class GameSession {
    @JsonIgnore
    private Level currentLevel;
    private int hits; //здоровье
    private int maxHits; //макс. здоровье
    private int strength; //сила
    private int gold; //золото
    private int armor; //броня
    private int exp; //опыт

    public void getGameData(Hero hero) {
        this.hits = hero.getHealth();
        this.maxHits = hero.getMaxHealth();
        this.strength = hero.getStrength();
        this.gold = hero.getBackpack().getGold();
        this.armor = hero.getDexterity();
        this.exp = hero.getExperience();
    }
}