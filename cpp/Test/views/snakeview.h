#ifndef SNAKEVIEW_H
#define SNAKEVIEW_H

#include "../inc.h"
#include "../models/snakemodel.h"

class SnakeView : public QWidget {
  Q_OBJECT

protected:
  void paintEvent(QPaintEvent *event) override;

public:
  SnakeView(QWidget *parent = nullptr);
  ~SnakeView();
  void set_dir(SnakeModel::Direction dir);
  void set_mg(SnakeModel::MenuGames mg);
  void setSnake(QList<SnakeModel::PointSnake> snake) ;
  void setFood(SnakeModel::Point food);
  void setScore(int score) ;
  void setFruits(QList<QString> fruits) ;

private:
  SnakeModel::Direction dir;
  SnakeModel::MenuGames mg;
  void printField(QPainter &painter);
  void printMenu(QPainter &painter);
  void printPause(QFont &font, QPainter &painter);
  void printGameOver(QFont &font, QPainter &painter);
  void printStart(QPainter &painter);
  void printScore(QFont &font, QPainter &painter);
  void printFood(QPainter &painter);
  void printSnake(QPainter &painter);

  int gridSize;
  QList<SnakeModel::PointSnake> snake;
  QList<QString> fruits;
  SnakeModel::Point food;
  int score;
};
#endif // SNAKEVIEW_H
