package presentation.states;

import lombok.AllArgsConstructor;
import presentation.GameRenderer;

import java.io.IOException;

@AllArgsConstructor
public class Playing implements ScreenState {
    private final GameRenderer gameRenderer;

    @Override
    public void render() throws IOException {
        gameRenderer.renderField();
        gameRenderer.renderStats();
    }
}
