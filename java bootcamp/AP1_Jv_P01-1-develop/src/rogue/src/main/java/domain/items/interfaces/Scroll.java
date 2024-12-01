package domain.items.interfaces;

import com.fasterxml.jackson.annotation.JsonSubTypes;
import com.fasterxml.jackson.annotation.JsonTypeInfo;
import domain.items.scroll.DexterityScroll;
import domain.items.scroll.HealthScroll;
import domain.items.scroll.StrengthScroll;

@JsonTypeInfo(use = JsonTypeInfo.Id.NAME, include = JsonTypeInfo.As.WRAPPER_OBJECT)
@JsonSubTypes({
        @JsonSubTypes.Type(value = DexterityScroll.class, name = "Dexterity"),
        @JsonSubTypes.Type(value = HealthScroll.class, name = "Health"),
        @JsonSubTypes.Type(value = StrengthScroll.class, name = "Strength"),
})
public interface Scroll {
}
