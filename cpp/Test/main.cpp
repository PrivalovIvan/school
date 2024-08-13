#include "brick_game/snake/controllers/snakecontroller.h"
#include "brick_game/snake/fsm/fsmm.h"
#include "brick_game/snake/inc.h"
#include "brick_game/snake/models/snakemodel.h"
#include "gui/desktop/views/snakeview.h"

extern "C" {
#include "brick_game/tetris/inc/backend.h"
}

int main(int argc, char *argv[]) {
  QApplication brickGame(argc, argv);
  qDebug() << "1";
  // brickGame.setWindowIcon(QIcon("../../../../../gui/desktop/image/fruits/f3.svg"));
  // brickGame.setWindowIcon(QIcon("/Users/ivanprivalov/Test/gui/desktop/image/skins/s-6.svg"));
  s21::SnakeView view;
  qDebug() << "2";
  s21::SnakeModel model;
  qDebug() << "3";
  s21::SnakeController controller(&model, &view);
  qDebug() << "4";
  view.show();

  return brickGame.exec();
}
