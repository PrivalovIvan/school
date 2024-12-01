package domain.enemy.list;

import domain.enemy.Enemy;
import domain.enemy.components.attack.GhostAttack;
import domain.enemy.components.movement.GhostMovement;
import domain.room.RoomManager;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.util.Random;

@EqualsAndHashCode(callSuper = true)
@Data
public class Ghost extends Enemy {
    public Ghost(RoomManager roomManager) {
        super("Ghost", 'g', 5, 3, 1, 1,
                new Random().nextInt(10, 21), new GhostMovement(), roomManager, new GhostAttack());
    }
}

/*
* Привидение (отображение: белый g):
* Высокая ловкость. Низкая сила, враждебность и здоровье.
* Постоянно телепортируется по комнате и периодически становится невидимым, пока игрок не вступил в бой.

  мал/сред/бол/
 * здоровье 5, 10, 15
 * ловкость 1,2,3
 * сила 1,2,3
 * враждебность 1,2,3
 * */