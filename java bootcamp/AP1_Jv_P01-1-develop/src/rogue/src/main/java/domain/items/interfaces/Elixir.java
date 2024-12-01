package domain.items.interfaces;

import com.fasterxml.jackson.annotation.JsonSubTypes;
import com.fasterxml.jackson.annotation.JsonTypeInfo;
import domain.items.elixir.DexterityElixir;
import domain.items.elixir.HealthElixir;
import domain.items.elixir.StrengthElixir;

@JsonTypeInfo(use = JsonTypeInfo.Id.NAME, include = JsonTypeInfo.As.WRAPPER_OBJECT)
@JsonSubTypes({
        @JsonSubTypes.Type(value = DexterityElixir.class, name = "Dexterity"),
        @JsonSubTypes.Type(value = HealthElixir.class, name = "MaxHealth"),
        @JsonSubTypes.Type(value = StrengthElixir.class, name = "Strength"),
})
public interface Elixir {
}
