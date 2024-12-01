package domain.items.weapon;

import domain.items.Item;
import domain.items.interfaces.Weapon;

//меч
public class Sword extends Item implements Weapon {
    public Sword() {
        super("Weapon", "Sword", 0, 0, 0, 8, 0);
    }
}
