package domain.enemy.list;

import domain.enemy.Enemy;
import domain.enemy.components.attack.OgreAttack;
import domain.enemy.components.movement.OgreMovement;
import domain.room.RoomManager;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.util.Random;

@EqualsAndHashCode(callSuper = true)
@Data
//todo Ходит по комнате на две клетки. после каждой атаки отдыхает один ход, затем гарантированно контратакует.
public class Ogre extends Enemy {
    public Ogre(RoomManager roomManager) {
        super("Ogre", 'O', 20, 1, 7, 2,
                new Random().nextInt(20, 41), new OgreMovement(), roomManager, new OgreAttack());
    }
}

/*
* Ходит по комнате на две клетки.
* Очень высокая сила и здоровье, но после каждой атаки отдыхает один ход,
* затем гарантированно контратакует. Низкая ловкость.
* Средняя враждебность.
*
  мал/сред/бол/
 * здоровье 5, 10, 15 ,20
 * ловкость 1,2,3
 * сила 1,2,3
 * враждебность 1,2,3
*
* */
