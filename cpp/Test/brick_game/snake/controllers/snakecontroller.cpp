#include "snakecontroller.h"
#include "../fsm/fsmm.h"

extern "C" {
#include "../../tetris/inc/backend.h"
}

s21::SnakeController::SnakeController(s21::SnakeModel *model,
                                      s21::SnakeView *view)
    : model(model), view(view), speed(0) {
  // Snake
  setFruits();

  fsm = new FsmM(model, view);
  tempDir = s21::SnakeModel::Right;

  // TETRIS
  INIT_FIELD(21, 10)
  INIT_NEXT_FIGURE(4, 4)
  system("mkdir -p hi_score");

  init_list_shape(list);
  state = NONE;
  action = No_sig;

  setState();
  setAction();
  setDirec();

  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &SnakeController::gameLoop);
  timer->start(speed);
  view->installEventFilter(this);
}

bool s21::SnakeController::eventFilter(QObject *obj, QEvent *event) {
  Q_UNUSED(obj);
  if (event->type() == QEvent::KeyPress) {
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    SnakeController::handleKeyPress(keyEvent);
    return true;
  }
  return QObject::eventFilter(obj, event);
}
void s21::SnakeController::handleKeyPress(QKeyEvent *event) {
  if (model->getDir())
    controlSnake(event);
  else if (state != NONE) {
    controlTetris(event);
  } else
    controlMenu(event);
}
void s21::SnakeController::gameLoop() {
  setDirec();
  setMenuGame();
  setState();
  setAction();
  view->update();

  if (state != NONE and state != GAME_OVER)
    s21::SnakeController::TetrisLoop();
  else if (state == GAME_OVER) {
    model->setMg(SnakeModel::Tetris_game);
    state = NONE;
    action = Terminate;
  } else
    s21::SnakeController::SnakeLoop();
}
void s21::SnakeController::SnakeLoop() {
  setSnake();
  setFood();
  setScore();
  setFruits();
  setMaxScore();

  if (model->score > model->maxScore)
    model->writeScore(), model->readScore();

  if (level < 10)
    model->changeLevel(level, speed);
  view->setLevel(level);

  if (SnakeModel::WinGame == model->getDir() or
      SnakeModel::GameOver == model->getDir()) {
    timer->start(300);
  } else {
    qDebug() << "                   " << speed << "!!!!!!!!!!!!!!!!!!!!!!!";
    timer->start(speed);
  }

  fsm->executeAction(fsm->getSt(), model->getDir());
  view->update();

  if (model->getMg()) {
    view->update();
    if (model->getMg() == SnakeModel::Exit)
      view->close();
  }
}

void s21::SnakeController::TetrisLoop() {
  if (g_info.high_score < g_info.score) {
    write_hi_score(g_info);
    read_hi_score(&g_info);
  }
  init_list_shape(list);
  if (action != No_sig)
    speed_game(&g_info);

  sigact(get_signal(action), &state, &g_info, list, &sh);

  if (state == GAME_OVER) {
    timer->start(500);
  } else
    timer->start(BASE_SPEED - g_info.speed);

  if (state != MOVING and state != START)
    action = No_sig;

  if (state == MOVING and action == No_sig)
    state = SHIFTING;

  setIdFigure();
  setIdNextFigure();

  setG_Info();
  view->update();
}
void s21::SnakeController::controlMenu(QKeyEvent *event) {
  switch (event->key()) {
  case Qt::Key_Up:
    if (model->getMg() == SnakeModel::Snake_game)
      model->setMg(SnakeModel::Tetris_game);
    else if (model->getMg() == SnakeModel::Quit)
      model->setMg(SnakeModel::Snake_game);
    else
      model->setMg(SnakeModel::Tetris_game);
    break;
  case Qt::Key_Down:
    if (model->getMg() == SnakeModel::Tetris_game)
      model->setMg(SnakeModel::Snake_game);
    else if (model->getMg() == SnakeModel::Snake_game)
      model->setMg(SnakeModel::Quit);
    else
      model->setMg(SnakeModel::Quit);
    break;
  case Qt::Key_Space:
    if (model->getMg() == SnakeModel::Snake_game)
      model->setDir(SnakeModel::Start), model->setMg(SnakeModel::N);
    else if (model->getMg() == SnakeModel::Quit)
      model->setMg(SnakeModel::Exit);
    else if (model->getMg() == SnakeModel::Tetris_game)
      state = START, model->setMg(SnakeModel::N);
    break;

  default:
    break;
  }
}
void s21::SnakeController::controlSnake(QKeyEvent *event) {
  switch (event->key()) {
  case Qt::Key_Up:
    if (model->getDir() != SnakeModel::Down and
        model->getDir() != SnakeModel::GameOver and
        model->getDir() != SnakeModel::Start and
        model->getDir() != SnakeModel::Pause)
      model->setDir(SnakeModel::Up);
    model->processingSignal = true;
    break;
  case Qt::Key_Down:
    if (model->getDir() != SnakeModel::Up and
        model->getDir() != SnakeModel::GameOver and
        model->getDir() != SnakeModel::Start and
        model->getDir() != SnakeModel::Pause)
      model->setDir(SnakeModel::Down);
    model->processingSignal = true;
    break;
  case Qt::Key_Left:
    if (model->getDir() != SnakeModel::Right and
        model->getDir() != SnakeModel::GameOver and
        model->getDir() != SnakeModel::Start and
        model->getDir() != SnakeModel::Pause)
      model->setDir(SnakeModel::Left);
    model->processingSignal = true;
    break;
  case Qt::Key_Right:
    if (model->getDir() != SnakeModel::Left and
        model->getDir() != SnakeModel::GameOver and
        model->getDir() != SnakeModel::Start and
        model->getDir() != SnakeModel::Pause)
      model->setDir(SnakeModel::Right);
    model->processingSignal = true;
    break;
  case Qt::Key_S:
    if (model->getDir() == SnakeModel::Start)
      model->setDir(SnakeModel::Right);
    break;
  case Qt::Key_Space:
    if (model->getDir() != SnakeModel::Pause and
        model->getDir() != SnakeModel::GameOver and
        model->getDir() != SnakeModel::Start)
      model->setDir(SnakeModel::Pause);
    else if (model->getDir() == SnakeModel::Pause)
      model->setDir(tempDir);
    break;
  case Qt::Key_Q:
    if (model->getDir() != SnakeModel::Pause)
      model->setDir(SnakeModel::GameOver);
    timer->start(200);
    break;
  default:
    break;
  }
  // для избежания пролета клетки при нажатии направления для змейки
  if (model->getDir() != SnakeModel::Pause) {
    model->moveSnake();
    view->update();
    if (model->checkCollision()) {
      model->setDir(SnakeModel::GameOver);
      view->update();
      return;
    }
    model->eatFruit();
    view->update();
  }
  // сохраняется направление, которое было до паузы
  if (model->getDir() == SnakeModel::Up or
      model->getDir() == SnakeModel::Down or
      model->getDir() == SnakeModel::Left or
      model->getDir() == SnakeModel::Right) {
    tempDir = model->getDir();
  }
}
void s21::SnakeController::controlTetris(QKeyEvent *event) {
  switch (event->key()) {
  case Qt::Key_S:
    action = Start;
    break;
  case Qt::Key_Space:
    action = Pause;
    break;
  case Qt::Key_Left:
    action = Left;
    break;
  case Qt::Key_Right:
    action = Right;
    break;
  case Qt::Key_Up:
    action = Up;
    break;
  case Qt::Key_Down:
    action = Down;
    break;
  case Qt::Key_Q:
    action = Terminate;
    state = GAME_OVER;
    break;
  default:
    action = No_sig;
    break;
  }
}
