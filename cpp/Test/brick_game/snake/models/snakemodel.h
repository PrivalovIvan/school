#ifndef SNAKEMODEL_H
#define SNAKEMODEL_H

#include "../inc.h"

namespace s21 {
class SnakeModel : public QObject {
  Q_OBJECT
public:
  SnakeModel();

  enum Direction {
    None,
    Up,
    Down,
    Left,
    Right,
    Start,
    Pause,
    GameOver,
    WinGame
  };
  enum MenuGames { N, Tetris_game, Snake_game, Quit, Exit };
  Q_ENUM(Direction)
  Q_ENUM(MenuGames)
  void setDir(Direction dir);
  void setMg(MenuGames mg);
  void setScore(int score);

  Direction getDir();
  MenuGames getMg();
  int getMaxScore();
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

  void moveSnake();
  void initGame();
  void add_fruits();
  void generateFood();
  bool checkCollision();
  bool eatFruit();

  bool processingSignal;

  void readScore();
  void writeScore();
  void changeScore();
  void changeLevel(int &level, int &speed);

  int score;
  int maxScore;

private:
  QList<PointSnake> snake;
  Direction dir;
  MenuGames mg;
  QList<QString> fruits;
  Point food;
};
} // namespace s21
#endif // SNAKEMODEL_H
