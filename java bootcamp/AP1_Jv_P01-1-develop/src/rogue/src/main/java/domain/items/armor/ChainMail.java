package domain.items.armor;

import domain.items.Item;
import domain.items.interfaces.Armor;

//кольчуга
public class ChainMail extends Item implements Armor {
    public ChainMail() {
        super("Armor", "ChainMail", 0, 0, 2, 0, 0);
    }
}
