package presentation.itemsHandler;

import domain.Level;
import domain.items.Item;

public interface Observer {
    void update(Level level, Item item);
}
