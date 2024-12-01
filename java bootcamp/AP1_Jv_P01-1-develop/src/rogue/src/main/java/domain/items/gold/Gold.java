package domain.items.gold;

import domain.items.Item;
import domain.items.interfaces.GoldTag;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.util.Random;

@EqualsAndHashCode(callSuper = true)
@Data
public class Gold extends Item implements GoldTag {
    private static final Random random = new Random();

    public Gold() {
        super("Gold",
                "Gold",
                0,
                0,
                0,
                0,
                random.nextInt(1, 15));
    }
}
