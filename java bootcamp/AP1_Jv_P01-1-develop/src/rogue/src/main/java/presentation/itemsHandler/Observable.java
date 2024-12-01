package presentation.itemsHandler;

public interface Observable {
    void addObserver(Observer observer);

    void removeObserver(Observer observer);
}
