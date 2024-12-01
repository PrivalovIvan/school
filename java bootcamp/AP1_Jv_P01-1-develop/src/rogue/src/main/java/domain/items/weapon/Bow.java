package domain.items.weapon;

import domain.items.Item;
import domain.items.interfaces.Weapon;

public class Bow extends Item implements Weapon {
    public Bow() {
        super("Weapon", "Bow", 0, 0, 0, 4, 0);
    }
}
