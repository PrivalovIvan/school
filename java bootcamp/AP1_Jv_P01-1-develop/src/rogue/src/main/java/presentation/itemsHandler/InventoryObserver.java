package presentation.itemsHandler;

import domain.Level;
import domain.hero.Hero;
import domain.items.Item;

public class InventoryObserver implements Observer {
    @Override
    public void update(Level level, Item item) {
        Hero hero = level.getHero();
        level.getRoomManager().getField()[hero.getPlayerX()][hero.getPlayerY()] = '.';
    }
}
