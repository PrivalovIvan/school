package domain.items.armor;

import domain.items.Item;
//латы

public class Armor extends Item implements domain.items.interfaces.Armor {
    public Armor() {
        super("Armor", "Armor", 0, 0, 3, 0, 0);
    }
}
