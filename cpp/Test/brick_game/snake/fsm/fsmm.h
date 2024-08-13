#ifndef FSMM_H
#define FSMM_H

#include "../../../gui/desktop/views/snakeview.h"
#include "../controllers/snakecontroller.h"
#include "../inc.h"
#include "../models/snakemodel.h"

class FsmM {
  typedef void (FsmM::*Action)();

public:
  FsmM(s21::SnakeModel *model, s21::SnakeView *view);
  enum states { Start, Spawn, Moving, Shifting, WinGame, GameOver };
  void executeAction(states state, s21::SnakeModel::Direction event);
  void setSt(states st);
  states getSt() const;

private:
  states st;
  Action fsmTable[6][9];
  void start();
  void pause();
  void spawn();
  void moving();
  void shifting();
  void winGame();
  void exit_snake();
  s21::SnakeModel *model;
  s21::SnakeView *view;
};

#endif // FSMM_H
