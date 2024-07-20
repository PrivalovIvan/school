#include "snakemodel.h"

SnakeModel::SnakeModel()
    : dir(None), mg(Menu), score(4), processingSignal(false) {
  initGame();
  add_fruits();
  generateFood();
}

void SnakeModel::initGame() {
  snake.clear();
    snake.append({4, 10});
    snake.append({3.5, 10});
    snake.append({3, 10});
    snake.append({2.5, 10});
    // snake.append({4, 10});
    // snake.append({3, 10});
    // snake.append({2, 10});
    // snake.append({1, 10});
}
void SnakeModel::add_fruits() {
  QString path;
  for (int i{}; i <= 6; i++) {
    path = "/Users/ivanprivalov/Test/image/fruits/f";
    path.append(std::to_string(i)).append(".svg");
    fruits.append(path);
  }
}
void SnakeModel::generateFood() {
  int s_x = 10;
  int s_y = 20;
  food = {QRandomGenerator::global()->bounded(s_x),
          QRandomGenerator::global()->bounded(s_y)};
  for (int i{}; i < snake.size(); i++) {
    if (snake[i].x == food.x and snake[i].y == food.y)
      SnakeModel::generateFood();
  }
}
void SnakeModel::moveSnake() {
  PointSnake new_head = snake.front();
  switch (dir) {
  // case Up:
  //   new_head.y--;
  //   break;
  // case Down:
  //   new_head.y++;
  //   break;
  // case Left:
  //   new_head.x--;
  //   break;
  // case Right:
  //   new_head.x++;
  //   break;
  // default:
  //   break;
    case Up:
        new_head.y= new_head.y - 0.5;
        break;
    case Down:
        new_head.y= new_head.y + 0.5;
        break;
    case Left:
        new_head.x= new_head.x - 0.5;
        break;
    case Right:
        new_head.x= new_head.x + 0.5;
        break;
    default:
        break;
  }
  snake.prepend(new_head);
  snake.removeLast();
}
bool SnakeModel::checkCollision() {
  const PointSnake &head = snake.first();
  // for (int i{1}; i < snake.size(); i++)
  //     if (head.x == snake.at(i).x and head.y == snake.at(i).y) return true;

  if (head.x > 9 or head.x < 0 or head.y > 19 or head.y < 0)
    return true;

  return false;
}
void SnakeModel::eatFruit() {
  if (snake.first().x == food.x and snake.first().y == food.y) {
    score++;
    snake.append(snake.last());
    generateFood();
  }
}

// Getters and Setters
QList<SnakeModel::PointSnake> SnakeModel::getSnake() { return this->snake; }
SnakeModel::Point SnakeModel::getFood() { return this->food; }
int SnakeModel::getScore() { return this->score; }
QList<QString> SnakeModel::getFruits() { return this->fruits; }
void SnakeModel::setScore(int score) { this->score = score; }
void SnakeModel::setDir(Direction dir) { this->dir = dir; }
void SnakeModel::setMg(MenuGames mg) { this->mg = mg; }
SnakeModel::Direction SnakeModel::getDir() { return this->dir; }
SnakeModel::MenuGames SnakeModel::getMg() { return this->mg; }
