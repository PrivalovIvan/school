package domain.items.armor;

import domain.items.Item;
import domain.items.interfaces.Armor;

//кожаная броня
public class LeatherArmor extends Item implements Armor {
    public LeatherArmor() {
        super("Armor", "LeatherArmor", 0, 0, 1, 0, 0);
    }
}
