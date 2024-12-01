package presentation.itemsHandler;

import domain.Level;
import domain.items.Item;

import java.util.ArrayList;
import java.util.List;

public class ItemsPickupTask implements Observable {
    private final List<Observer> observers = new ArrayList<>();
    private final Level level;

    public ItemsPickupTask(Level level) {
        this.level = level;
    }

    public void execute(Item item) {
        if (item == null || !level.getHero().pickUpItem(item)) {
            return;
        }
        notifyObservers(item);
    }

    @Override
    public void addObserver(Observer observer) {
        observers.add(observer);
    }

    @Override
    public void removeObserver(Observer observer) {
        observers.remove(observer);
    }

    public void notifyObservers(Item item) {
        observers.forEach(o -> o.update(level, item));
    }
}
