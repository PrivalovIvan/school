package domain.items.weapon;

import domain.items.Item;
import domain.items.interfaces.Weapon;

//кинжал
public class Dagger extends Item implements Weapon {
    public Dagger() {
        super("Weapon", "Dagger", 0, 0, 0, 2, 0);
    }
}
