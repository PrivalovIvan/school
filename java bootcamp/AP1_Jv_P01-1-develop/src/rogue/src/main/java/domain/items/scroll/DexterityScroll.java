package domain.items.scroll;

import domain.items.Item;
import domain.items.interfaces.Scroll;

//ловкость
public class DexterityScroll extends Item implements Scroll {
    public DexterityScroll() {
        super("Scroll", "Dexterity", 0, 0, 5, 0, 0);
    }
}
