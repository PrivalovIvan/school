#include "snakeview.h"

SnakeView::SnakeView(QWidget *parent) : QWidget(parent), gridSize(40) {
  setFixedSize(10 * gridSize, 20 * gridSize);
  setWindowTitle("Brick Game");
}

SnakeView::~SnakeView() {}

void SnakeView::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event);
  QPainter painter(this);
  QFont font = painter.font();
  printField(painter);
  // qDebug() << mg;
  // qDebug() << dir;
  if (mg) {
    printMenu(painter);
  } else {
    if (dir == SnakeModel::Start) {
      printStart(painter);
    } else if (dir == SnakeModel::Pause) {
      printPause(font, painter);
    } else if (dir == SnakeModel::GameOver) {
      printGameOver(font, painter);
      return;
    } else {
      printFood(painter);
      printSnake(painter);
      printScore(font, painter);
    }
  }
}
void SnakeView::printMenu(QPainter &painter) {
  painter.setPen(Qt::white);
  if (mg == SnakeModel::Tetris_game)
    painter.setPen(Qt::gray);
  painter.drawText(4.6 * gridSize, 9.5 * gridSize, "Tetris\n");
  painter.setPen(Qt::white);
  if (mg == SnakeModel::Snake_game)
    painter.setPen(Qt::gray);
  painter.drawText(4.5 * gridSize, 10 * gridSize, "Snake\n\n");
  painter.setPen(Qt::white);
  if (mg == SnakeModel::Quit)
    painter.setPen(Qt::gray);
  painter.drawText(9 * gridSize, 19.5 * gridSize, "\n\n   Quit");
}
void SnakeView::printFood(QPainter &painter) {
  QPixmap fruit(fruits[QRandomGenerator::global()->bounded(7)]);
  painter.drawPixmap(food.x * gridSize, food.y * gridSize, gridSize, gridSize,
                     fruit);
}
void SnakeView::printField(QPainter &painter) {
  QPixmap background("/Users/ivanprivalov/Test/image/backgrounds/back2.jpg");
  painter.drawPixmap(0, 0, 10 * gridSize, 20 * gridSize, background);
}
void SnakeView::printSnake(QPainter &painter) {
  QPixmap head("/Users/ivanprivalov/Test/image/skins/s-18.svg");
  QPixmap body("/Users/ivanprivalov/Test/image/skins/s-16.svg");
  QPixmap tail("/Users/ivanprivalov/Test/image/skins/s-17.svg");
  QTransform transformHead, transformTail;
  QPixmap rotatedHead, rotatedTail;
  int for_head{};
  for (auto p : snake) {
    if (!for_head++) {
      if (dir == SnakeModel::Up) {
        transformHead.rotate(0);
        rotatedHead = head.transformed(transformHead);
      } else if (dir == SnakeModel::Left) {
        transformHead.rotate(-90);
        rotatedHead = head.transformed(transformHead);
      } else if (dir == SnakeModel::Right or dir == SnakeModel::Start or
                 dir == SnakeModel::Pause) {
        transformHead.rotate(90);
        rotatedHead = head.transformed(transformHead);
      } else if (dir == SnakeModel::Down) {
        transformHead.rotate(180);
        rotatedHead = head.transformed(transformHead);
      }

      painter.drawPixmap(p.x * gridSize, p.y * gridSize, gridSize, gridSize,
                         rotatedHead);
    }
    // else if (for_head == snake.size()) {
    //   transformTail.rotate(90);
    //   rotatedTail = tail.transformed(transformTail);
    //   painter.drawPixmap(p.x * gridSize, p.y * gridSize, gridSize,
    // gridSize,
    //                      rotatedTail);
    // }

    else {
      if (dir == SnakeModel::Left or dir == SnakeModel::Right)
        painter.drawPixmap((p.x) * gridSize, (p.y) * gridSize + 7,
                           gridSize / 1.3, gridSize / 1.3, body);
      else if (dir == SnakeModel::Up or dir == SnakeModel::Down)
        painter.drawPixmap((p.x) * gridSize + 7, (p.y) * gridSize,
                           gridSize / 1.3, gridSize / 1.3, body);
    }
  }
}
void SnakeView::printStart(QPainter &painter) {
  painter.drawText(rect(), Qt::AlignCenter, "Press S for Start");
}
void SnakeView::printGameOver(QFont &font, QPainter &painter) {
  font.setPointSize(20);
  painter.setFont(font);
  QString str = "Game Over";
  static QString str1;
  static int itemp{};
  painter.drawText(rect(), Qt::AlignCenter, str1.append(str[itemp]));
  itemp++;
  if (itemp == 9) {
    mg = SnakeModel::Menu, dir = SnakeModel::None, itemp = 0, str1.clear();
  }
}
void SnakeView::printPause(QFont &font, QPainter &painter) {
  font.setPointSize(30);
  painter.setFont(font);
  painter.drawText(rect(), Qt::AlignCenter, "Pause");
}
void SnakeView::printScore(QFont &font, QPainter &painter) {
  QString sScore;
  sScore.append(std::to_string(score));
  font.setPointSize(30);
  painter.setFont(font);
  painter.drawText(5 * gridSize, 1 * gridSize, sScore);
}


//Setters and Getters
void SnakeView::set_dir(SnakeModel::Direction dir) { this->dir = dir; }
void SnakeView::set_mg(SnakeModel::MenuGames mg) { this->mg = mg; }
void SnakeView::setSnake(QList<SnakeModel::PointSnake> snake) { this->snake = snake; }
void SnakeView::setFood(SnakeModel::Point food) { this->food = food; }
void SnakeView::setScore(int score) { this->score = score; }
void SnakeView::setFruits(QList<QString> fruits) { this->fruits = fruits; }
