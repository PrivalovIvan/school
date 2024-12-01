package domain.enemy.list;

import domain.enemy.Enemy;
import domain.enemy.components.attack.SnakeMagicianAttack;
import domain.enemy.components.movement.SnakeMagicianMovement;
import domain.room.RoomManager;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.util.Random;

@EqualsAndHashCode(callSuper = true)
@Data
public class SnakeMagician extends Enemy {
    public SnakeMagician(RoomManager roomManager) {
        super("SnakeMagician", 's', 15, 7, 2, 3, new Random().nextInt(5, 16), new SnakeMagicianMovement(), roomManager, new SnakeMagicianAttack());
    }
}
/*
*Змей-маг (отображение: белая s):
* Ходит по карте по диагоналям, постоянно меняя сторону.
* У каждой успешной атаки есть вероятность «усыпить» игрока на один ход.
* Высокая враждебность. Очень высокая ловкость.

  мал/сред/бол/
 * здоровье 5, 10, 15
 * ловкость 1,2,3
 * сила 1,2,3
 * враждебность 1,2,3
 * */