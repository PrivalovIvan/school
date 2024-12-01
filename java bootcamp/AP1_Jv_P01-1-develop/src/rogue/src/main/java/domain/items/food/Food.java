package domain.items.food;

import domain.items.Item;
import domain.items.interfaces.FoodTag;

public class Food extends Item implements FoodTag {
    public Food() {
        super("Food", "Food", 10, 0, 0, 0, 0);
    }
}
