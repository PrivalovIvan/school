package presentation.states;

import lombok.Getter;
import lombok.Setter;
import presentation.GameRenderer;

import java.io.IOException;

@Setter
@Getter
public class GameContext {
    private ScreenState currentState;

    public GameContext(GameRenderer gameRenderer) {
        currentState = new Playing(gameRenderer);
    }

    public void render() throws IOException {
        currentState.render();
    }
}
