#include "controllers/snakecontroller.h"
#include "inc.h"
#include "models/snakemodel.h"
#include "views/snakeview.h"

int main(int argc, char *argv[]) {
  QApplication brickGame(argc, argv);
  SnakeView view;
  SnakeModel model;
  SnakeController controller(&model, &view);
  view.show();
  return brickGame.exec();
}
