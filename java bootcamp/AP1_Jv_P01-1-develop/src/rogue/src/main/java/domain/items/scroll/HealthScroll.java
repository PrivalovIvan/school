package domain.items.scroll;

import domain.items.Item;
import domain.items.interfaces.Scroll;

public class HealthScroll extends Item implements Scroll {
    public HealthScroll() {
        super("Scroll", "Health", 0, 10, 0, 0, 0);
    }
}
