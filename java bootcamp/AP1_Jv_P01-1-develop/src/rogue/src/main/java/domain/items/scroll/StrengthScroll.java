package domain.items.scroll;

import domain.items.Item;
import domain.items.interfaces.Scroll;

public class StrengthScroll extends Item implements Scroll {
    public StrengthScroll() {
        super("Scroll", "Strength", 0, 0, 0, 5, 0);
    }
}
