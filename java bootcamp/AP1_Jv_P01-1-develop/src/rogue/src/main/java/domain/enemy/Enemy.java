package domain.enemy;

import domain.Character;
import domain.enemy.interfaces.AttackPattern;
import domain.enemy.interfaces.MovementPattern;
import domain.room.RoomManager;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.NoArgsConstructor;
import lombok.ToString;

@EqualsAndHashCode(callSuper = true)
@Data
@ToString(callSuper = true)
@NoArgsConstructor
public abstract class Enemy extends Character implements Cloneable {
    private String type; //тип
    private int hostility; //враждебность
    private int experience;

    private int posX, posY;
    private char enemySymbol;
    private boolean visible;
    private char prevChar = '.';
    private int prevStep = 1;
    private boolean fighting = false;
    private int firstHitForVampire = 0;
    private int counterHits = 0;

    private RoomManager roomManager;
    private MovementPattern movementPattern;
    private AttackPattern attackPattern;

    public Enemy(String type, char enemySymbol, int health, int dexterity, int strength, int hostility, int experience,
                 MovementPattern movementPattern, RoomManager roomManager, AttackPattern attackPattern) {
        super(health, dexterity, strength);
        this.type = type;
        this.hostility = hostility;
        this.movementPattern = movementPattern;
        this.enemySymbol = enemySymbol;
        this.roomManager = roomManager;
        this.attackPattern = attackPattern;
        this.experience = experience;
    }

    public void move() {
        movementPattern.move(this, roomManager);
    }

    public void attack() {
        attackPattern.attack(this, roomManager);
    }

    @Override
    public Enemy clone() {
        try {
            return (Enemy) super.clone();
        } catch (CloneNotSupportedException e) {
            throw new RuntimeException(e.getMessage());
        }
    }
}
