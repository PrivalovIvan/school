package domain.enemy.list;

import domain.enemy.Enemy;
import domain.enemy.components.attack.VampireAttack;
import domain.enemy.components.movement.VampireMovement;
import domain.room.RoomManager;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.util.Random;

@EqualsAndHashCode(callSuper = true)
@Data
public class Vampire extends Enemy {
    public Vampire(RoomManager roomManager) {
        super("Vampire", 'v', 10, 3, 2, 3,
                new Random().nextInt(10, 21), new VampireMovement(), roomManager, new VampireAttack());
    }
}

/*
Вампир (отображение: красная v):
Высокая ловкость, враждебность и здоровье. Средняя сила.
Отнимает некоторое количество максимального уровня здоровья игроку при успешной атаке.
Первый удар по вампиру — всегда промах.

  мал/сред/бол/
 * здоровье 5, 10, 15
 * ловкость 1,2,3
 * сила 1,2,3
 * враждебность 1,2,3
        * */