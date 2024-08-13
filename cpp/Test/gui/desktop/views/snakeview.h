#ifndef SNAKEVIEW_H
#define SNAKEVIEW_H

#include "../../../brick_game/snake/inc.h"
#include "../../../brick_game/snake/models/snakemodel.h"

extern "C" {
#include "../../../brick_game/tetris/inc/backend.h"
}

namespace s21 {
class SnakeView : public QWidget {
  Q_OBJECT

protected:
  void paintEvent(QPaintEvent *event) override;

public:
  SnakeView(QWidget *parent = nullptr);
  ~SnakeView();
  void set_dir(SnakeModel::Direction dir);
  void set_mg(SnakeModel::MenuGames mg);
  void setSnake(QList<SnakeModel::PointSnake> snake);
  void setFood(SnakeModel::Point food);
  void setScore(int score);
  void setFruits(QList<QString> fruits);
  void setMaxScore(int maxScore);
  void setLevel(int newLevel);

private:
  SnakeModel::Direction dir;
  SnakeModel::MenuGames mg;
  void printField(QPainter &painter);
  void printMenu(QPainter &painter);
  void printPause(QFont &font, QPainter &painter);
  void printGameOver(QFont &font, QPainter &painter);
  void printWinGame(QFont &font, QPainter &painter);
  void printStart(QPainter &painter);
  void printScore(QFont &font, QPainter &painter);
  void printLevel(QFont &font, QPainter &painter);
  void printMaxScore(QFont &font, QPainter &painter);
  void printFood(QPainter &painter);
  void printSnake(QPainter &painter);

  int gridSize;
  QList<SnakeModel::PointSnake> snake;
  QList<QString> fruits;
  SnakeModel::Point food;
  int score;
  int maxScore;
  int level;

  QString executableDir;
  // QString pathHead;
  // QString pathBody;
  QString pathFruits;

  void loadSnake(QDir &curD);
  QPixmap snakeBodyHead[2];

  void loadBackgrounds(QDir &curD);
  QPixmap backgrounds[10];

  // TETRIS
public:
  void setState(state_s newState);
  void setAction(UserAction_t newAction);
  void setG_Info(GameInfo_t newG_Info);
  void setIdFigure(int newIdFigure);
  void setIdNextFigure(int newIdNextFigure);

private:
  void printNextFigureTetris(QPainter &painter);
  void printDataTetris(QFont &font, QPainter &painter);
  void printFieldTetris(QPainter &painter);
  void printGameOverTetris(QFont &font, QPainter &painter);

  QPixmap Figures[21];
  void loadImagesFigure(QDir &curD);
  QPixmap nextFigures[21];
  void loadImagesNextFigure(QDir &curD);

  int idFigure;
  int idNextFigure;

  state_s state;
  UserAction_t action;
  GameInfo_t g_info;
};
} // namespace s21
#endif // SNAKEVIEW_H
