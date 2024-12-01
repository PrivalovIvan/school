package presentation.states;

import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.terminal.Terminal;
import lombok.AllArgsConstructor;

import java.io.IOException;

import static presentation.ScreensRendererUtils.outText;

@AllArgsConstructor
public class WinScreen implements ScreenState {
    private final Terminal terminal;

    @Override
    public void render() throws IOException {
        outText(terminal, "YOU WIN. PRESS SPACE", TextColor.ANSI.GREEN);
    }
}
