package domain.room.components;

import domain.items.Item;
import domain.items.armor.Armor;
import domain.items.armor.ChainMail;
import domain.items.armor.LeatherArmor;
import domain.items.armor.MagicShield;
import domain.items.elixir.DexterityElixir;
import domain.items.elixir.HealthElixir;
import domain.items.elixir.StrengthElixir;
import domain.items.gold.Gold;
import domain.items.scroll.DexterityScroll;
import domain.items.scroll.HealthScroll;
import domain.items.scroll.StrengthScroll;
import domain.items.weapon.BattleAxe;
import domain.items.weapon.Bow;
import domain.items.weapon.Dagger;
import domain.items.weapon.Sword;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ItemFactory {

    public List<Item> initTreasures() {
        return new ArrayList<>(Arrays.asList(new Gold(), new Armor(), new LeatherArmor(), new MagicShield(), new ChainMail(),
                new Gold(), new Dagger(), new Sword(), new BattleAxe(), new Bow(), new Gold(), new DexterityElixir(),
                new HealthElixir(), new StrengthElixir(), new Gold(), new DexterityScroll(), new HealthScroll(),
                new StrengthScroll(), new Gold()));
    }
}
