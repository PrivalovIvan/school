package domain.hero.components;

import domain.hero.Hero;
import domain.hero.interfaces.use.HeroStatManager;
import domain.items.Item;

public class HeroStatManagerImpl implements HeroStatManager {
    @Override
    public void updateDataHero(Hero hero, Item item, boolean positive) {
        updateHealthHero(hero, item, positive);
        updateStatsHero(hero, item, positive);
    }

    private void updateHealthHero(Hero hero, Item item, boolean positive) {
        int multiply = positive ? 1 : -1;
        if (hero.getHealth() + item.getHealthBoost() > hero.getMaxHealth()) {
            hero.setHealth(hero.getMaxHealth());
        } else {
            hero.setHealth(hero.getHealth() + item.getHealthBoost() * multiply);
        }
    }

    private void updateStatsHero(Hero hero, Item item, boolean positive) {
        int multiply = positive ? 1 : -1;
        hero.setMaxHealth(hero.getMaxHealth() + item.getMaxHealthBoost() * multiply);
        hero.setDexterity(hero.getDexterity() + item.getDexterityBoost() * multiply);
        hero.setStrength(hero.getStrength() + item.getStrengthBoost() * multiply);
    }
}
