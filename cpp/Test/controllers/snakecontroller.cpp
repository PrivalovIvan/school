#include "snakecontroller.h"
#include <QTimer>

SnakeController::SnakeController(SnakeModel *model, SnakeView *view)
    : model(model), view(view) {
  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &SnakeController::gameLoop);
  timer->start(300);

  view->installEventFilter(this);
}

bool SnakeController::eventFilter(QObject *obj, QEvent *event) {
  Q_UNUSED(obj);
  if (event->type() == QEvent::KeyPress) {
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    SnakeController::handleKeyPress(keyEvent);
    return true;
  }
  return QObject::eventFilter(obj, event);
}
void SnakeController::handleKeyPress(QKeyEvent *event) {
  if (!model->getMg()) {
    controlSnake(event);
  } else {
    controlMenu(event);
  }
}

void SnakeController::gameLoop() {
  setDirec();
  setMenuGame();
  setSnake();
  setFood();
  setScore();
  setFruits();
  view->update();
  if ((model->getDir() == SnakeModel::Start or
       model->getDir() == SnakeModel::Pause or
       model->getDir() == SnakeModel::GameOver)) {
    view->update();
    if (model->getDir() == SnakeModel::GameOver) {
      model->initGame();
      // view->update();
      if (static int itemp{}; itemp++ == 8) {
        model->setDir(SnakeModel::None);
        model->setMg(SnakeModel::Menu);
        itemp = 0;
      }
      timer->start(200);
      return;
    }
  } else if (model->getMg()) {
    view->update();
    if (model->getMg() == SnakeModel::Exit)
      view->close();
  } else {
    if (!model->processingSignal)
      model->moveSnake();
    setSnake();
    // view->repaint();
    if (model->checkCollision()) {
      model->setDir(SnakeModel::GameOver);
      model->initGame();
      model->setScore(4);
      return;
    }
    model->eatFruit();
    // view->update();
    model->processingSignal = false;
  }
  setSnake();
  view->update();
}

void SnakeController::controlMenu(QKeyEvent *event) {
  switch (event->key()) {
  case Qt::Key_Up:
    model->setMg(SnakeModel::Tetris_game);
    break;
  case Qt::Key_Down:
    if (model->getMg() == SnakeModel::Snake_game)
      model->setMg(SnakeModel::Quit);
    else
      model->setMg(SnakeModel::Snake_game);
    break;
  case Qt::Key_Space:
    if (model->getMg() == SnakeModel::Snake_game)
      model->setDir(SnakeModel::Start), model->setMg(SnakeModel::N);
    else if (model->getMg() == SnakeModel::Quit)
      model->setMg(SnakeModel::Exit);
    break;

  default:
    break;
  }
}
void SnakeController::controlSnake(QKeyEvent *event) {
  switch (event->key()) {
  case Qt::Key_Up:
    if (model->getDir() != SnakeModel::Down and
        model->getDir() != SnakeModel::GameOver and
        model->getDir() != SnakeModel::Start and
        model->getDir() != SnakeModel::None)
      model->setDir(SnakeModel::Up);
    model->processingSignal = true;
    break;
  case Qt::Key_Down:
    if (model->getDir() != SnakeModel::Up and
        model->getDir() != SnakeModel::GameOver and
        model->getDir() != SnakeModel::Start and
        model->getDir() != SnakeModel::None)
      model->setDir(SnakeModel::Down);
    model->processingSignal = true;
    break;
  case Qt::Key_Left:
    if (model->getDir() != SnakeModel::Right and
        model->getDir() != SnakeModel::GameOver and
        model->getDir() != SnakeModel::Start)
      model->setDir(SnakeModel::Left);
    model->processingSignal = true;
    break;
  case Qt::Key_Right:
    if (model->getDir() != SnakeModel::Left and
        model->getDir() != SnakeModel::GameOver and
        model->getDir() != SnakeModel::Start)
      model->setDir(SnakeModel::Right);
    model->processingSignal = true;
    break;
  case Qt::Key_S:
    if (model->getDir() == SnakeModel::Start)
      model->setDir(SnakeModel::Right);
    break;
  case Qt::Key_Space:
    if (model->getDir() != SnakeModel::Pause and
        model->getDir() != SnakeModel::GameOver)
      model->setDir(SnakeModel::Pause);
    else if (model->getDir() == SnakeModel::Pause)
      model->setDir(SnakeModel::Right);
    break;
  case Qt::Key_Q:
    if (model->getDir() != SnakeModel::Pause)
      model->setDir(SnakeModel::GameOver);
    break;
  default:
    break;
  }
  if (model->getMg() != SnakeModel::Menu) {
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
}
