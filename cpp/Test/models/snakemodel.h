#ifndef SNAKEMODEL_H
#define SNAKEMODEL_H

#include "../inc.h"

class SnakeModel : public QObject {
  Q_OBJECT
public:
  SnakeModel();

  enum Direction { Up, Down, Left, Right, Start, Pause, GameOver, None };
  enum MenuGames {
    N,
    Menu,
    Move_Up,
    Move_Down,
    Tetris_game,
    Snake_game,
    Quit,
    Exit
  };
  Q_ENUM(Direction)
  Q_ENUM(MenuGames)
  void setDir(Direction dir);
  void setMg(MenuGames mg);
  Direction getDir();
  MenuGames getMg();

  struct Point {
    int x, y;
  };
  struct PointSnake {
    double x, y;
  };
  QList<PointSnake> getSnake();

  QList<QString> getFruits();
  Point getFood();
  int getScore();

  void setScore(int score);

  void moveSnake();
  void initGame();
  void add_fruits();
  void generateFood();
  bool checkCollision();
  void eatFruit();

  bool processingSignal;

  QList<PointSnake> snake;
private:
  Direction dir;
  MenuGames mg;
  QList<QString> fruits;
  Point food;
  int score;
};

#endif // SNAKEMODEL_H
