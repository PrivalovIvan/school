package domain.items.interfaces;

import com.fasterxml.jackson.annotation.JsonSubTypes;
import com.fasterxml.jackson.annotation.JsonTypeInfo;
import domain.items.weapon.BattleAxe;
import domain.items.weapon.Bow;
import domain.items.weapon.Dagger;
import domain.items.weapon.Sword;

@JsonTypeInfo(use = JsonTypeInfo.Id.NAME, include = JsonTypeInfo.As.WRAPPER_OBJECT)
@JsonSubTypes({
        @JsonSubTypes.Type(value = BattleAxe.class, name = "BattleAxe"),
        @JsonSubTypes.Type(value = Bow.class, name = "Bow"),
        @JsonSubTypes.Type(value = Dagger.class, name = "Dagger"),
        @JsonSubTypes.Type(value = Sword.class, name = "Sword"),
})
public interface Weapon {
}
