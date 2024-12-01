package domain.items.interfaces;

import com.fasterxml.jackson.annotation.JsonSubTypes;
import com.fasterxml.jackson.annotation.JsonTypeInfo;
import domain.items.armor.ChainMail;
import domain.items.armor.LeatherArmor;
import domain.items.armor.MagicShield;

@JsonTypeInfo(use = JsonTypeInfo.Id.NAME, include = JsonTypeInfo.As.WRAPPER_OBJECT)
@JsonSubTypes({
        @JsonSubTypes.Type(value = ChainMail.class, name = "ChainMail"),
        @JsonSubTypes.Type(value = LeatherArmor.class, name = "LeatherArmor"),
        @JsonSubTypes.Type(value = MagicShield.class, name = "MagicShield"),
        @JsonSubTypes.Type(value = domain.items.armor.Armor.class, name = "Armor"),
})
public interface Armor {
}
