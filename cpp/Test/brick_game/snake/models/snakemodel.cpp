#include "snakemodel.h"

s21::SnakeModel::SnakeModel()
    : processingSignal(false), score(START_SCORE), maxScore(0), dir(None),
      mg(Tetris_game) {
  initGame();
  add_fruits();
  generateFood();
  readScore();
}

void s21::SnakeModel::initGame() {
  snake.clear();
  snake.append({4, 10});
  snake.append({3.5, 10});
  snake.append({3, 10});
  snake.append({2.5, 10});
  score = START_SCORE;
  // snake.append({4, 10});
  // snake.append({3, 10});
  // snake.append({2, 10});
  // snake.append({1, 10});
}
void s21::SnakeModel::add_fruits() {
  QString executableDir = QCoreApplication::applicationDirPath();
  QDir curD(executableDir);
  curD.cd("../../../../../gui/desktop/image/fruits");
  QString path;
  for (int i{}; i <= 6; i++) {
    path = curD.absolutePath()
               .append("/f")
               .append(std::to_string(i))
               .append(".svg");
    fruits.append(path);
  }
}
void s21::SnakeModel::generateFood() {
  int s_x = 10;
  int s_y = 20;
  food = {QRandomGenerator::global()->bounded(s_x),
          QRandomGenerator::global()->bounded(s_y)};
  for (int i{}; i < snake.size(); i++) {
    if (snake[i].x == food.x and snake[i].y == food.y)
      s21::SnakeModel::generateFood();
  }
}
void s21::SnakeModel::moveSnake() {
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
    new_head.y = new_head.y - 0.5;
    break;
  case Down:
    new_head.y = new_head.y + 0.5;
    break;
  case Left:
    new_head.x = new_head.x - 0.5;
    break;
  case Right:
    new_head.x = new_head.x + 0.5;
    break;
  default:
    break;
  }
  snake.prepend(new_head);
  snake.removeLast();
}
bool s21::SnakeModel::checkCollision() {
  const PointSnake &head = snake.first();
  // for (int i{1}; i < snake.size(); i++)
  //     if (head.x == snake.at(i).x and head.y == snake.at(i).y) return true;

  if (head.x > 9 or head.x < 0 or head.y > 19 or head.y < 0)
    return true;

  return false;
}
bool s21::SnakeModel::eatFruit() {
  if (snake.first().x == food.x and snake.first().y == food.y) {
    score++;
    snake.append(snake.last());
    // generateFood();
    return true;
  }
  return false;
}
void s21::SnakeModel::readScore() {
  QString executableDir = QCoreApplication::applicationDirPath();
  QDir curD(executableDir);
  curD.cd("../../../../../brick_game/snake/max_score");
  QString path = curD.absolutePath().append("/score.txt");
  QFile file(path);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Cannot open file for reading: " << file.errorString();
    return;
  }
  QTextStream in(&file);
  QString content = in.readAll();
  // qDebug() << content;
  this->maxScore = content.toInt();

  file.close();
}
void s21::SnakeModel::writeScore() {
  QString executableDir = QCoreApplication::applicationDirPath();
  QDir curD(executableDir);
  curD.cd("../../../../../brick_game/snake/max_score");
  QString path = curD.absolutePath().append("/score.txt");
  QFile file(path);
  if (!file.open(QIODevice::WriteOnly)) {
    qDebug() << "Cannot open file for writing: " << file.errorString();
    return;
  }
  QTextStream out(&file);
  out << (this->maxScore += 1);

  file.close();
}
void s21::SnakeModel::changeScore() {
  if (this->score > this->maxScore) {
    writeScore();
  }
}
void s21::SnakeModel::changeLevel(int &level, int &speed) {
  if (level < 9) {
    level = score / 10 + 1;
    speed = SPEED_SNAKE / level;
  }
}

// Getters and Setters
s21::SnakeModel::Point s21::SnakeModel::getFood() { return this->food; }
s21::SnakeModel::MenuGames s21::SnakeModel::getMg() { return this->mg; }
s21::SnakeModel::Direction s21::SnakeModel::getDir() { return this->dir; }
int s21::SnakeModel::getScore() { return this->score; }
int s21::SnakeModel::getMaxScore() { return this->maxScore; }
QList<QString> s21::SnakeModel::getFruits() { return this->fruits; }
QList<s21::SnakeModel::PointSnake> s21::SnakeModel::getSnake() {
  return this->snake;
}

void s21::SnakeModel::setMg(MenuGames mg) { this->mg = mg; }
void s21::SnakeModel::setDir(Direction dir) { this->dir = dir; }
void s21::SnakeModel::setScore(int score) { this->score = score; }
