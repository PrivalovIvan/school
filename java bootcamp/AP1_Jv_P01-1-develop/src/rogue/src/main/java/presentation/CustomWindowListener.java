package presentation;

import domain.Level;
import lombok.AllArgsConstructor;

import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

@AllArgsConstructor
public class CustomWindowListener implements WindowListener {
    private final Level level;

    @Override
    public void windowOpened(WindowEvent e) {

    }

    @Override
    public void windowClosing(WindowEvent e) {

    }

    @Override
    public void windowClosed(WindowEvent e) {
        level.getHero().shutdownPotionManager();
        System.exit(0);
    }

    @Override
    public void windowIconified(WindowEvent e) {

    }

    @Override
    public void windowDeiconified(WindowEvent e) {

    }

    @Override
    public void windowActivated(WindowEvent e) {

    }

    @Override
    public void windowDeactivated(WindowEvent e) {

    }
}
