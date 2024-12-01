package domain.hero.interfaces.use;

import domain.hero.Hero;
import domain.items.Item;

public interface UseObject {
    void use(Item item, Hero hero);
}
