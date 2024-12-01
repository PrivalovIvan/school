package domain.items.weapon;

import domain.items.Item;
import domain.items.interfaces.Weapon;

//боевой топор
public class BattleAxe extends Item implements Weapon {
    public BattleAxe() {
        super("Weapon", "BattleAxe", 0, 0, 0, 6, 0);
    }
}
