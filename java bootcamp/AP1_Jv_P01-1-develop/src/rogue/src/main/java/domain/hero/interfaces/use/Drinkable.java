package domain.hero.interfaces.use;

import domain.hero.Hero;
import domain.items.interfaces.Elixir;

public interface Drinkable {
    void drinkPotion(Elixir elixir, Hero hero);
    void shutdown();
}
