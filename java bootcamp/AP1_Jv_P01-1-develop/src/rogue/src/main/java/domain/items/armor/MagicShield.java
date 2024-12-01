package domain.items.armor;

import domain.items.Item;
import domain.items.interfaces.Armor;

//магический щит
public class MagicShield extends Item implements Armor {
    public MagicShield() {
        super("Armor", "MagicShield", 0, 0, 3, 0, 0);
    }
}
