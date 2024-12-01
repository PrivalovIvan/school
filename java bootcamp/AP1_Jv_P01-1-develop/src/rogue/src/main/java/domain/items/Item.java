package domain.items;

import com.fasterxml.jackson.annotation.JsonSubTypes;
import com.fasterxml.jackson.annotation.JsonTypeInfo;
import domain.items.armor.Armor;
import domain.items.armor.ChainMail;
import domain.items.armor.LeatherArmor;
import domain.items.armor.MagicShield;
import domain.items.elixir.DexterityElixir;
import domain.items.elixir.HealthElixir;
import domain.items.elixir.StrengthElixir;
import domain.items.food.Food;
import domain.items.gold.Gold;
import domain.items.scroll.DexterityScroll;
import domain.items.scroll.HealthScroll;
import domain.items.scroll.StrengthScroll;
import domain.items.weapon.BattleAxe;
import domain.items.weapon.Bow;
import domain.items.weapon.Dagger;
import domain.items.weapon.Sword;
import lombok.Data;
import lombok.Getter;

import java.util.ArrayList;
import java.util.List;

@Data
@JsonTypeInfo(use = JsonTypeInfo.Id.NAME, include = JsonTypeInfo.As.WRAPPER_OBJECT)
@JsonSubTypes({
        @JsonSubTypes.Type(value = BattleAxe.class, name = "BattleAxe"),
        @JsonSubTypes.Type(value = Bow.class, name = "Bow"),
        @JsonSubTypes.Type(value = Dagger.class, name = "Dagger"),
        @JsonSubTypes.Type(value = Sword.class, name = "Sword"),
        @JsonSubTypes.Type(value = ChainMail.class, name = "ChainMail"),
        @JsonSubTypes.Type(value = LeatherArmor.class, name = "LeatherArmor"),
        @JsonSubTypes.Type(value = MagicShield.class, name = "MagicShield"),
        @JsonSubTypes.Type(value = Armor.class, name = "Armor"),
        @JsonSubTypes.Type(value = DexterityElixir.class, name = "DexterityElixir"),
        @JsonSubTypes.Type(value = HealthElixir.class, name = "HealthElixir"),
        @JsonSubTypes.Type(value = StrengthElixir.class, name = "StrengthElixir"),
        @JsonSubTypes.Type(value = DexterityScroll.class, name = "DexterityScroll"),
        @JsonSubTypes.Type(value = HealthScroll.class, name = "HealthScroll"),
        @JsonSubTypes.Type(value = StrengthScroll.class, name = "StrengthScroll"),
        @JsonSubTypes.Type(value = Gold.class, name = "Gold"),
        @JsonSubTypes.Type(value = Food.class, name = "Food"),
})
public abstract class Item {
    private String type;
    private String subType;
    private int healthBoost;
    private int maxHealthBoost;
    private int dexterityBoost;
    private int strengthBoost;
    private int cost;
    @Getter
    private static List<MapItems> listItemsOfTheMap = new ArrayList<>();

    public Item(String type, String subType, int healthBoost, int maxHealthBoost, int dexterityBoost, int strengthBoost, int cost) {
        this.type = type;
        this.subType = subType;
        this.healthBoost = healthBoost;
        this.maxHealthBoost = maxHealthBoost;
        this.dexterityBoost = dexterityBoost;
        this.strengthBoost = strengthBoost;
        this.cost = cost;
    }

    public static void addItemOfTheMap(MapItems item) {
        listItemsOfTheMap.add(item);
    }

    @Override
    public String toString() {
        return "Item{" +
                "type='" + type + '\'' +
                ", subType='" + subType + '\'' +
                ", healthBoost=" + healthBoost +
                ", maxHealthBoost=" + maxHealthBoost +
                ", dexterityBoost=" + dexterityBoost +
                ", strengthBoost=" + strengthBoost +
                ", cost=" + cost +
                '}';
    }
}


