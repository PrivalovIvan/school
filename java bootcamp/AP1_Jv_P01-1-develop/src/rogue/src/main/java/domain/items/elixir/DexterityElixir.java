package domain.items.elixir;

import domain.items.Item;
import domain.items.interfaces.Elixir;

public class DexterityElixir extends Item implements Elixir {
    public DexterityElixir() {
        super("Elixir", "Dexterity", 0, 0, 5, 0, 0);
    }
}

