#ifndef MYSNAKE_H
#define MYSNAKE_H
#include <iso646.h>

#include <QDebug>
#include <QImage>
#include <QKeyEvent>
#include <QLabel>
#include <QList>
#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QRandomGenerator>
#include <QString>
#include <QThread>
#include <QTimer>
#include <QWidget>

#define SPEED_GAME 300
using namespace std;

class Snake : public QWidget {
  Q_OBJECT
public:
  Snake(QWidget *parent = nullptr);
  ~Snake() = default;

private slots:
  void gameLoop();

protected:
  void paintEvent(QPaintEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;

private:
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
  struct Point {
    int x, y;
  };
  void initGame();
  void printMenu(QPainter &painter);
  void printPause(QFont &font, QPainter &painter);
  void printGameOver(QFont &font, QPainter &painter);
  void printStart(QPainter &painter);
  void printScore(QFont &font, QPainter &painter);
  void printFood(QPainter &painter);
  void printSnake(QPainter &painter);
  void printField(QPainter &painter);
  void moveSnake();
  void generateFood();
  void add_fruits();
  void eatFruit();
  bool checkCollision();

  void controlMenu(QKeyEvent *event);
  void controlSnake(QKeyEvent *event);

  QList<Point> snake;
  QList<QString> fruits;
  Direction dir;
  MenuGames mg;
  QTimer *timer;
  Point food;
  Point pointer;
  int gridSize;
  int score;
  bool processingSignal;
};

#endif // MYSNAKE_H
