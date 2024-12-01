package domain.enemy.list;

import domain.enemy.Enemy;
import domain.enemy.components.attack.ZombieAttack;
import domain.enemy.components.movement.ZombieMovement;
import domain.room.RoomManager;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.ToString;

import java.util.Random;

@EqualsAndHashCode(callSuper = true)
@Data
@ToString(callSuper = true)
public class Zombie extends Enemy {
    public Zombie(RoomManager roomManager) {
        super("Zombie", 'z', 15, 1, 2, 2,
                new Random().nextInt(10, 20), new ZombieMovement(), roomManager, new ZombieAttack());
    }
}
/*
* Зомби (отображение: зеленый z): Низкая ловкость. Средняя сила, враждебность. Высокое здоровье.

   мал/сред/бол/
 * здоровье 5, 10, 15
 * ловкость 1,2,3
 * сила 1,2,3
 * враждебность 1,2,3
 * */