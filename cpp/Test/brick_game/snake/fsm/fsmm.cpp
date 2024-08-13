#include "fsmm.h"

FsmM::FsmM(s21::SnakeModel *model, s21::SnakeView *view)
    : model(model), view(view) {
  fsmTable[0][0] = nullptr;
  fsmTable[0][1] = nullptr;
  fsmTable[0][2] = nullptr;
  fsmTable[0][3] = nullptr;
  fsmTable[0][4] = nullptr;
  fsmTable[0][5] = &FsmM::start;
  fsmTable[0][6] = nullptr;

  fsmTable[1][0] = &FsmM::spawn;
  fsmTable[1][1] = &FsmM::spawn;
  fsmTable[1][2] = &FsmM::spawn;
  fsmTable[1][3] = &FsmM::spawn;
  fsmTable[1][4] = &FsmM::spawn;
  fsmTable[1][5] = &FsmM::spawn;
  fsmTable[1][6] = &FsmM::spawn;
  fsmTable[1][7] = &FsmM::spawn;
  fsmTable[1][8] = &FsmM::spawn;

  fsmTable[2][0] = nullptr;
  fsmTable[2][1] = &FsmM::moving;
  fsmTable[2][2] = &FsmM::moving;
  fsmTable[2][3] = &FsmM::moving;
  fsmTable[2][4] = &FsmM::moving;
  fsmTable[2][5] = nullptr;
  fsmTable[2][6] = &FsmM::pause;
  fsmTable[2][7] = &FsmM::exit_snake;

  fsmTable[3][0] = &FsmM::shifting;
  fsmTable[3][1] = &FsmM::shifting;
  fsmTable[3][2] = &FsmM::shifting;
  fsmTable[3][3] = &FsmM::shifting;
  fsmTable[3][4] = &FsmM::shifting;
  fsmTable[3][5] = &FsmM::shifting;
  fsmTable[3][6] = &FsmM::shifting;
  fsmTable[3][7] = &FsmM::shifting;
  fsmTable[3][8] = &FsmM::shifting;

  fsmTable[4][0] = &FsmM::winGame;
  fsmTable[4][1] = &FsmM::winGame;
  fsmTable[4][2] = &FsmM::winGame;
  fsmTable[4][3] = &FsmM::winGame;
  fsmTable[4][4] = &FsmM::winGame;
  fsmTable[4][5] = &FsmM::winGame;
  fsmTable[4][6] = &FsmM::winGame;
  fsmTable[4][7] = &FsmM::winGame;
  fsmTable[4][8] = &FsmM::winGame;

  fsmTable[5][0] = &FsmM::exit_snake;
  fsmTable[5][1] = &FsmM::exit_snake;
  fsmTable[5][2] = &FsmM::exit_snake;
  fsmTable[5][3] = &FsmM::exit_snake;
  fsmTable[5][4] = &FsmM::exit_snake;
  fsmTable[5][5] = &FsmM::exit_snake;
  fsmTable[5][6] = &FsmM::exit_snake;
  fsmTable[5][7] = &FsmM::exit_snake;
  fsmTable[5][8] = &FsmM::exit_snake;
}

void FsmM::executeAction(states state, s21::SnakeModel::Direction event) {
  Action action = fsmTable[state][event];
  if (action != nullptr) {
    (this->*action)();
    view->update();
  }
}

void FsmM::start() {
  // model->initGame();
  // model->generateFood();
  setSt(Moving);
}

void FsmM::spawn() {
  model->generateFood();
  setSt(Moving);
}

void FsmM::moving() {
  if (model->checkCollision()) {
    setSt(GameOver);
  } else if (model->score == WIN_GAME) {
    setSt(WinGame);
  } else if (model->eatFruit()) {
    setSt(Spawn);
  } else
    setSt(Shifting);
}

void FsmM::shifting() {
  if (!model->processingSignal) {
    model->moveSnake();
  }
  model->processingSignal = false;
  setSt(Moving);
}

void FsmM::exit_snake() {
  model->setDir(s21::SnakeModel::GameOver);

  if (static int itemp{}; itemp++ == 8) {
    model->initGame();
    model->setDir(s21::SnakeModel::None);
    model->setMg(s21::SnakeModel::Tetris_game);
    view->update();
    itemp = 0;
    setSt(Start);
    view->update();
  }

  return;
}
void FsmM::winGame() {
  model->setDir(s21::SnakeModel::WinGame);

  if (static int itemp{}; itemp++ == 8) {
    model->initGame();
    model->setDir(s21::SnakeModel::None);
    model->setMg(s21::SnakeModel::Tetris_game);
    itemp = 0;
    setSt(Start);
    view->update();
  }
  return;
}
void FsmM::pause() { view->update(); }

// Getters and setters
FsmM::states FsmM::getSt() const { return st; }
void FsmM::setSt(FsmM::states st) { this->st = st; }
