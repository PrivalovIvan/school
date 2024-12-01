package domain.hero.components;

import domain.Level;
import domain.hero.Hero;
import domain.hero.interfaces.use.UseItem;
import domain.items.Item;
import domain.items.MapItems;
import domain.items.interfaces.Armor;
import domain.items.interfaces.Scroll;
import domain.items.interfaces.Weapon;

public class ObjectManager implements UseItem {
    @Override
    public void use(Item item, Hero hero) {
        if (item instanceof Weapon) hero.setWeapon(item);
        else if (item instanceof Armor) hero.setArmor(item);
        hero.applyItemEffect(item, true);
    }

    @Override
    public void change(Item item, Hero hero) {
        if (item instanceof Armor) {
            hero.applyItemEffect(hero.getArmor(), false);
            hero.setArmor(item);
        } else if (item instanceof Weapon) {
            hero.applyItemEffect(hero.getWeapon(), false);
            hero.setWeapon(item);
        } else return;
        hero.applyItemEffect(item, true);
    }

    @Override
    public void throwObject(Item item, Level level) {
        if (item instanceof Scroll) return;
        int x = level.getHero().getPlayerX();
        int y = level.getHero().getPlayerY();
        char[][] field = level.getRoomManager().getField();
        int[][] direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

        for (int[] dir : direction) {
            int newX = x + dir[0];
            int newY = y + dir[1];
            if (field[newX][newY] == '.') {
                Item.addItemOfTheMap((new MapItems(item, new int[]{newX, newY})));
//                level.getRoomManager().getField()[newX][newY] = 'W';
                level.getRoomManager().getField()[newX][newY] = item instanceof Weapon ? 'W' : 'A';
                return;
            }
        }
    }
}
