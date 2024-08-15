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
  // brickGame.setWindowIcon(QIcon("../../../../../gui/desktop/image/fruits/f3.svg"));
  brickGame.setWindowIcon(QIcon("/Users/ivanprivalov/Brick_Game/gui/desktop/image/skins/s-6.svg"));
  s21::SnakeView view;
  // view.setWindowIcon(QIcon("/Users/ivanprivalov/Test/gui/desktop/image/skins/s-6.svg"));
  s21::SnakeModel model;
  s21::SnakeController controller(&model, &view);
  view.show();

  return brickGame.exec();
}
