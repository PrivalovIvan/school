#ifndef SNAKECONTROLLER_H
#define SNAKECONTROLLER_H

#include "../inc.h"
#include "../models/snakemodel.h"
#include "../views/snakeview.h"

class SnakeModel;
class SnakeView;

class SnakeController : public QObject {
  Q_OBJECT

protected:
  bool eventFilter(QObject *obj, QEvent *event) override;

public:
  SnakeController(SnakeModel *model, SnakeView *view);

  void setDirec() { view->set_dir(model->getDir()); }
  void setMenuGame() { view->set_mg(model->getMg()); }
  void setSnake() { view->setSnake(model->getSnake()); }
  void setFood() { view->setFood(model->getFood()); }
  void setScore() { view->setScore(model->getScore()); }
  void setFruits() { view->setFruits(model->getFruits()); }

private:
  void handleKeyPress(QKeyEvent *event);
  void gameLoop();
  void controlMenu(QKeyEvent *event);
  void controlSnake(QKeyEvent *event);

  SnakeModel *model;
  SnakeView *view;
  QTimer *timer;
};

#endif // SNAKECONTROLLER_H
