package domain.items.elixir;

import domain.items.Item;
import domain.items.interfaces.Elixir;

public class HealthElixir extends Item implements Elixir {
    public HealthElixir() {
        super("Elixir", "MaxHealth", 0, 5, 0, 0, 0);
    }
}