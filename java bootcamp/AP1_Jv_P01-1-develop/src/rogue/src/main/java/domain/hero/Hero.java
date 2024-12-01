package domain.hero;

import domain.BackPack;
import domain.Character;
import domain.Level;
import domain.enemy.components.attack.StatusEffect;
import domain.hero.components.HeroStatManagerImpl;
import domain.hero.interfaces.attack.CombatHandler;
import domain.hero.interfaces.attack.StatusEffectManager;
import domain.hero.interfaces.use.Drinkable;
import domain.hero.interfaces.use.HeroStatManager;
import domain.hero.interfaces.use.UseItem;
import domain.items.Item;
import domain.items.interfaces.Elixir;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.ToString;

@EqualsAndHashCode(callSuper = true)
@Data
@ToString(callSuper = true)
final public class Hero extends Character {
    private int maxHealth; // максимальное здоровье
    private int experience;
    private int playerX, playerY;
    private BackPack backpack;
    private CombatHandler combatHandler;
    private Drinkable potionManager;
    private UseItem objectManager;
    private StatusEffectManager statusEffectManager;
    private HeroStatManager statManager;

    private Item armor;
    private Item weapon;

    public Hero(CombatHandler combatHandler, Drinkable potionManager, UseItem objectManager, StatusEffectManager statusEffectManager,
                HeroStatManager statManager) {
        super(40, 5, 5);
        this.maxHealth = super.getHealth();
        this.backpack = new BackPack();
        this.combatHandler = combatHandler;
        this.potionManager = potionManager;
        this.objectManager = objectManager;
        this.statusEffectManager = statusEffectManager;
        this.statManager = statManager;
    }

    public void setPosition(int[] points) {
        this.playerX = points[0];
        this.playerY = points[1];
    }

    public boolean pickUpItem(Item item) {
        return backpack.add(item);
    }

    public void applyItemEffect(Item item, boolean positive) {
        statManager.updateDataHero(this, item, positive);
    }

    public void attack(Character target) {
        combatHandler.combat(this, target);
    }

    public void shutdownPotionManager() {
        potionManager.shutdown();
    }

    public void useElixir(Elixir elixir) {
        potionManager.drinkPotion(elixir, this);
    }

    //взять объект если ничего не используется сейчас
    public void useItem(Item item) {
        objectManager.use(item, this);
    }

    // выбросить объект, если это не свиток
    public void discardItem(Item item, Level level) {
        objectManager.throwObject(item, level);
    }

    // поменять объект если уже что-то используется, если это не свиток
    public void equipItem(Item item) {
        objectManager.change(item, this);
    }

    public boolean isAlive() {
        return this.getHealth() > 0 && this.getMaxHealth() > 0;
    }

    public void applyStatusEffect(StatusEffect effect, int duration) {
        statusEffectManager.applyStatusEffect(effect, duration);
    }

    public void updateStatusEffects() {
        statusEffectManager.updateStatusEffects();
    }

    public boolean isSleeping() {
        return statusEffectManager.hasStatusEffect(StatusEffect.SLEEP);
    }
}