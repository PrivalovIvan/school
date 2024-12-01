package domain;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@AllArgsConstructor
@NoArgsConstructor
@Data
public abstract class Character {
    private int health; // здоровье
    private int dexterity; // ловкость
    private int strength; // сила
}
