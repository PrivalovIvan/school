package domain;

import domain.items.Item;
import domain.items.gold.Gold;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@Data
@NoArgsConstructor
public class BackPack {
    private static final int MAX_ITEMS_PER_TYPE = 9;
    private List<Item> items = new ArrayList<>();
    private int gold;

    /**
     * Добавляет предметы в рюкзак. В случае, предметов отдельного типа в рюкзаке больше 9,
     * то предмет не будет добавлен.
     *
     * @param item Предмет, который будет помещен в список предметов items.
     * @return Возвращает успешно ли добавлен предмет
     */
    public boolean add(Item item) {
        if (item instanceof Gold) addGold((Gold) item);
        else return addOtherItem(item);
        return true;
    }

    /**
     * Возвращает список предметов из рюкзака, которые реализуют указанный тип (интерфейс или класс).
     *
     * @param type класс или интерфейсов, которым должны соответствовать объекты,
     *             например {@code Weapon.class}
     * @return Возвращает список предметов реализующий указанный тип, если таких типов нет, то возвращает null
     * @see Item
     */
    public List<Item> getItemsByType(Class<?> type) {
        return items.stream()
                .filter(item -> type.isAssignableFrom(item.getClass()))
                .collect(Collectors.toList());
    }

    private void addGold(Gold gold) {
        this.gold += gold.getCost();
    }

    private boolean addOtherItem(Item item) {
        long itemsTypeCount = items.stream()
                .filter(i -> i.getType().equals(item.getType()))
                .count();
        if (itemsTypeCount < MAX_ITEMS_PER_TYPE) {
            items.add(item);
            return true;
        }
        return false;
    }

    //возможно не будет использоваться
    public void remove(Item item) {
        items.remove(item);
    }

    //возможно не будет использоваться
    public Map<String, Long> getCountItemByType() {
        return items.stream()
                .collect(Collectors.groupingBy(Item::getType, Collectors.counting()));
    }
}
