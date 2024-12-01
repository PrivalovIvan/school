package domain.items.elixir;

import domain.items.Item;
import domain.items.interfaces.Elixir;

public class StrengthElixir extends Item implements Elixir {
    public StrengthElixir() {
        super("Elixir", "Strength", 0, 0, 0, 5, 0);
    }
}
