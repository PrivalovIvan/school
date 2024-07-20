#include "mysnake.h"

#include "ui_mysnake.h"

Snake::Snake(QWidget *parent)
    : QWidget(parent), dir(None), mg(Menu), gridSize(40), score(4),
      processingSignal(false) {
  setFixedSize(10 * gridSize, 20 * gridSize);
  setWindowTitle("Brick Game Snake");
  initGame();
  add_fruits();
  generateFood();

  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &Snake::gameLoop);
  timer->start(SPEED_GAME);
}
void Snake::printMenu(QPainter &painter) {
    painter.setPen(Qt::white);
    if(mg == Tetris_game)
        painter.setPen(Qt::gray);
    painter.drawText(4.6 * gridSize, 9.5 * gridSize, "Tetris\n");
    painter.setPen(Qt::white);
    if(mg == Snake_game)
        painter.setPen(Qt::gray);
  painter.drawText(4.5 * gridSize, 10 * gridSize, "Snake\n\n");
    painter.setPen(Qt::white);

  if(mg == Quit)
      painter.setPen(Qt::gray);
  painter.drawText(9* gridSize,19.5 * gridSize, "\n\n   Quit");
}
void Snake::printFood(QPainter &painter) {
  QPixmap fruit(fruits[QRandomGenerator::global()->bounded(7)]);
  painter.drawPixmap(food.x * gridSize, food.y * gridSize, gridSize, gridSize,
                     fruit);
}
void Snake::printField(QPainter &painter) {
  QPixmap background("/Users/ivanprivalov/MySnake/image/backgrounds/back5.jpg");
  painter.drawPixmap(0, 0, 10 * gridSize, 20 * gridSize, background);
}
void Snake::printSnake(QPainter &painter) {
  QPixmap head("/Users/ivanprivalov/MySnake/image/skins/s-15.svg");
  QPixmap body("/Users/ivanprivalov/MySnake/image/skins/s-16.svg");
  QPixmap tail("/Users/ivanprivalov/MySnake/image/skins/s-17.svg");
  QTransform transformHead, transformTail;
  QPixmap rotatedHead, rotatedTail;
  int for_head{};
  for (auto p : snake) {
    if (!for_head++) {
      if (dir == Up) {
        transformHead.rotate(0);
        rotatedHead = head.transformed(transformHead);
      } else if (dir == Left) {
        transformHead.rotate(-90);
        rotatedHead = head.transformed(transformHead);
      } else if (dir == Right or dir == Start or dir == Pause) {
        transformHead.rotate(90);
        rotatedHead = head.transformed(transformHead);
      } else if (dir == Down) {
        transformHead.rotate(180);
        rotatedHead = head.transformed(transformHead);
      }

      painter.drawPixmap(p.x * gridSize, p.y * gridSize, gridSize, gridSize,
                         rotatedHead);
    }
    // else if (for_head == snake.size()) {
    //   transformTail.rotate(90);
    //   rotatedTail = tail.transformed(transformTail);
    //   painter.drawPixmap(p.x * gridSize, p.y * gridSize, gridSize, gridSize,
    //                      rotatedTail);
    // }

    else {
      if (dir == Left or dir == Right)
        painter.drawPixmap((p.x) * gridSize, (p.y) * gridSize + 7,
                           gridSize / 1.3, gridSize / 1.3, body);
      else if (dir == Up or dir == Down)
        painter.drawPixmap((p.x) * gridSize + 7, (p.y) * gridSize,
                           gridSize / 1.3, gridSize / 1.3, body);
    }
  }
}
void Snake::printStart(QPainter &painter) {
  painter.drawText(rect(), Qt::AlignCenter, "Press Enter for Start");
}
void Snake::printGameOver(QFont &font, QPainter &painter) {
  font.setPointSize(20);
  painter.setFont(font);
  QString str = "Game Over";
  static QString str1;
  static int itemp{};
  // if(i < 10)
  //     painter.drawText(3.8 * gridSize,(i+=0.3 )* gridSize, "Game Over");
  // else
  //     painter.drawText(rect(), Qt::AlignCenter, "Game Over");
  timer->start(100);
  painter.drawText(rect(), Qt::AlignCenter, str1.append(str[itemp]));
  itemp++;

  if (itemp == 9)
            mg = Menu, dir = None ,itemp = 0, timer->start(400), str1.clear();
}
void Snake::printPause(QFont &font, QPainter &painter) {
  font.setPointSize(30);
  painter.setFont(font);
  painter.drawText(rect(), Qt::AlignCenter, "Pause");
}
void Snake::printScore(QFont &font, QPainter &painter) {
  QString sScore;
  sScore.append(to_string(score));
  font.setPointSize(30);
  painter.setFont(font);
  painter.drawText(5 * gridSize, 1 * gridSize, sScore);
}
void Snake::initGame() {
  snake.clear();
  snake.append({4, 10});
  snake.append({3, 10});
  snake.append({2, 10});
  snake.append({1, 10});
  pointer = {4, 10};
}
void Snake::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event);
  QPainter painter(this);
  QFont font = painter.font();
  printField(painter);
  if (mg) {
    printMenu(painter);
  } else {
    if (dir == Start) {
      printStart(painter);
    } else if (dir == Pause) {
      printPause(font, painter);
    } else if (dir == GameOver) {
      printGameOver(font, painter);
      return;
    } else {
      printFood(painter);
      printSnake(painter);
      printScore(font, painter);
    }
  }
}
void Snake::controlMenu(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Up:
        mg= Tetris_game ;
        break;
    case Qt::Key_Down:
        if(mg == Snake_game) mg = Quit;
        else mg = Snake_game;

        break;
    case Qt::Key_Space:
        if(mg == Snake_game) dir = Start, mg = N;
        else if (mg == Quit) mg = Exit;
        break;

    default:
        break;
    }
}
void Snake::controlSnake(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Up:
        if (dir != Down and dir != GameOver and dir != Start and dir != None)
            dir = Up;
        processingSignal = true;
        break;
    case Qt::Key_Down:
        if (dir != Up and dir != GameOver and dir != Start and dir != None)
            dir = Down;
        processingSignal = true;
        break;
    case Qt::Key_Left:
        if (dir != Right and dir != GameOver and dir != Start)
            dir = Left;
        processingSignal = true;
        break;
    case Qt::Key_Right:
        if (dir != Left and dir != GameOver and dir != Start)
            dir = Right;
        processingSignal = true;
        break;
    case Qt::Key_S:
        if (dir == Start)
            dir = Right;
        break;
    case Qt::Key_Space:
        if (dir != Pause and dir != GameOver)
            dir = Pause;
        else if (dir == Pause)
            dir = Right;
        break;
    case Qt::Key_Q:
        if (dir != Pause)
            dir = GameOver;
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
    if (mg != Menu) {
        moveSnake();
        if (checkCollision()) {
            dir = GameOver;
            update();
            return;
        }
        eatFruit();
        update();
    }
}
void Snake::keyPressEvent(QKeyEvent *event) {
    if(!mg){
        controlSnake(event);
    } else {
        controlMenu(event);
    }
}
void Snake::moveSnake() {
  Point new_head = snake.front();
  switch (dir) {
  case Up:
    new_head.y--;
    break;
  case Down:
    new_head.y++;
    break;
  case Left:
    new_head.x--;
    break;
  case Right:
    new_head.x++;
    break;
  default:
    break;
  }
  snake.prepend(new_head);
  snake.removeLast();
}
void Snake::generateFood() {
  int s_x = 10;
  int s_y = 20;
  food = {QRandomGenerator::global()->bounded(s_x),
          QRandomGenerator::global()->bounded(s_y)};
  for (int i{}; i < snake.size(); i++) {
    if (snake[i].x == food.x and snake[i].y == food.y)
      Snake::generateFood();
  }
}
void Snake::eatFruit() {
  if (snake.first().x == food.x and snake.first().y == food.y) {
    score++;
    snake.append(snake.last());
    generateFood();
  }
}
bool Snake::checkCollision() {
  const Point &head = snake.first();
  // for (int i{1}; i < snake.size(); i++)
  //     if (head.x == snake.at(i).x and head.y == snake.at(i).y) return true;

  if (head.x >= 10 or head.x < 0 or head.y >= 20 or head.y < 0)
    return true;

  return false;
}
void Snake::add_fruits() {
  QString path;
  for (int i{}; i <= 6; i++) {
    path = "/Users/ivanprivalov/MySnake/image/fruits/f";
    path.append(std::to_string(i)).append(".svg");
    fruits.append(path);
  }
}

void Snake::gameLoop() {
  qDebug() << dir;
  if ((dir == Start or dir == Pause or dir == GameOver)) {
    update();
      if (dir == GameOver){
        initGame();
        update();


      }
  } else if (mg) {
    timer->start(10);
    // choiceMenu();
    update();
    if(mg == Exit) this->close();
  }
  else {
    if (!processingSignal)
      moveSnake();
    repaint();
    if (checkCollision()) {
      dir = GameOver;
      update();
      initGame();
      this->score = 4;
      return;
    }
    eatFruit();
    update();
    processingSignal = false;

  }
}
