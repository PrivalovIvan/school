package domain.hero.components;

import domain.hero.Hero;
import domain.hero.interfaces.use.Drinkable;
import domain.items.Item;
import domain.items.interfaces.Elixir;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class PotionManager implements Drinkable {
    ExecutorService executorService = Executors.newVirtualThreadPerTaskExecutor();

    @Override
    public void drinkPotion(Elixir elixir, Hero hero) {
        hero.applyItemEffect((Item) elixir, true);
        executorService.submit(() -> {
            try {
                TimeUnit.SECONDS.sleep(13);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                throw new RuntimeException(e);
            }
            hero.applyItemEffect((Item) elixir, false);
        });
    }

    public void shutdown() {
        executorService.shutdown();
    }
}
