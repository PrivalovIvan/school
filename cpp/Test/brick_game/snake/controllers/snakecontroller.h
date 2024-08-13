#ifndef SNAKECONTROLLER_H
#define SNAKECONTROLLER_H

#include "../../../gui/desktop/views/snakeview.h"
#include "../fsm/fsmm.h"
#include "../inc.h"
#include "../models/snakemodel.h"

extern "C" {
#include "../../tetris/inc/backend.h"
}

class SnakeModel;
class SnakeView;
class FsmM;

namespace s21 {
class SnakeController : public QObject {
  Q_OBJECT

protected:
  bool eventFilter(QObject *obj, QEvent *event) override;

public:
  SnakeController(s21::SnakeModel *model, s21::SnakeView *view);

  void setDirec() { view->set_dir(model->getDir()); }
  void setMenuGame() { view->set_mg(model->getMg()); }
  void setSnake() { view->setSnake(model->getSnake()); }
  void setFood() { view->setFood(model->getFood()); }
  void setScore() { view->setScore(model->getScore()); }
  void setFruits() { view->setFruits(model->getFruits()); }
  void setMaxScore() { view->setMaxScore(model->getMaxScore()); }

private:
  void gameLoop();
  void SnakeLoop();
  void controlMenu(QKeyEvent *event);
  void controlSnake(QKeyEvent *event);
  void handleKeyPress(QKeyEvent *event);

  s21::SnakeModel *model;
  s21::SnakeView *view;
  QTimer *timer;
  FsmM *fsm;
  int speed;
  int level;

  s21::SnakeModel::Direction tempDir;

  // TETRIS
public:
  void setState() { view->setState(this->state); }
  void setAction() { view->setAction(this->action); }
  void setG_Info() { view->setG_Info(this->g_info); }
  void controlTetris(QKeyEvent *event);
  void TetrisLoop();
  void setIdFigure() { view->setIdFigure(list[sh.num_shape].id); }
  void setIdNextFigure() { view->setIdNextFigure(list[sh.temp].id); }

private:
  state_s state;
  UserAction_t action;
  GameInfo_t g_info;
  shapes_s list[24];
  shapes_s sh{};
};
} // namespace s21
#endif // SNAKECONTROLLER_H
