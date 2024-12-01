package domain.hero.interfaces.use;

import domain.hero.Hero;
import domain.items.Item;

public interface HeroStatManager {
    void updateDataHero(Hero hero, Item item, boolean positive);
}
