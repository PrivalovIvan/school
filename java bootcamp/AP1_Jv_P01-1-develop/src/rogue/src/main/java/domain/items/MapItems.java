package domain.items;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

import java.util.Arrays;

//@Data
@AllArgsConstructor
@Getter
@Setter
public class MapItems {
    private Item item;
    private int[] coordsOfItem;

    @Override
    public String toString() {
        return "MapItems{" +
                "coordsOfItem=" + Arrays.toString(coordsOfItem) +
                '}';
    }
}
