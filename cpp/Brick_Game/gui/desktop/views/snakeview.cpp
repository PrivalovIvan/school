#include "snakeview.h"

s21::SnakeView::SnakeView(QWidget *parent) : QWidget(parent), gridSize(40) {
  setFixedSize(10 * gridSize, 20 * gridSize);
  setWindowTitle("Brick Game");
  executableDir = QCoreApplication::applicationDirPath();
  QDir curD(executableDir);
  curD.cd("../../../../../gui/desktop/image/");
  pathFruits = curD.absolutePath().append("/fruits/f");

  loadBackgrounds(curD);
  loadSnake(curD);
  loadImagesFigure(curD);
  loadImagesNextFigure(curD);
}

s21::SnakeView::~SnakeView() {}

void s21::SnakeView::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event);
  QPainter painter(this);
  QFont font = painter.font();
  printField(painter);
  qDebug() << "MG: " << mg;
  qDebug() << "DIR: " << dir;
  qDebug() << "STATE: " << state;
  qDebug() << "Action: " << action;
  if (mg)
    printMenu(painter);
  else if (dir) {
    if (dir == SnakeModel::Start) {
      printStart(painter);
    } else if (dir == SnakeModel::Pause) {
      printPause(font, painter);
    } else if (dir == SnakeModel::GameOver) {
      printGameOver(font, painter);
      return;
    } else if (dir == SnakeModel::WinGame) {
      printWinGame(font, painter);
      return;
    } else {
      printMaxScore(font, painter);
      printLevel(font, painter);
      printFood(painter);
      printSnake(painter);
      printScore(font, painter);
    }
  } else {
    if (state == START) {
      printStart(painter);
    } else if (state == GAME_OVER) {
      if (static int temp; ++temp <= 9)
        printGameOverTetris(font, painter);
      else {
        state = NONE;
        temp = 0;
      }
      return;
    } else {
        if (action == Pause){
        printPause(font,painter);
        }else {
      printDataTetris(font, painter);
      printFieldTetris(painter);
      printNextFigureTetris(painter);
    }
}
  }
}
// SNAKE
void s21::SnakeView::printMenu(QPainter &painter) {
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
void s21::SnakeView::printFood(QPainter &painter) {
  QPixmap fruit(fruits[QRandomGenerator::global()->bounded(7)]);
  painter.drawPixmap(food.x * gridSize, food.y * gridSize, gridSize, gridSize,
                     fruit);
}
void s21::SnakeView::printField(QPainter &painter) {
  if (mg)
    painter.drawPixmap(0, 0, 10 * gridSize, 20 * gridSize, backgrounds[0]);
  else if (dir)
    painter.drawPixmap(0, 0, 10 * gridSize, 20 * gridSize, backgrounds[0]);
  else
    painter.drawPixmap(0, 0, 10 * gridSize, 20 * gridSize, backgrounds[1]);
}
void s21::SnakeView::printSnake(QPainter &painter) {
  // QPixmap head(pathHead);
  // QPixmap body(pathBody);
  QTransform transformHead, transformTail;
  QPixmap rotatedHead, rotatedTail;
  int for_head{};
  for (auto p : snake) {
    if (!for_head++) {
      if (dir == SnakeModel::Up) {
        transformHead.rotate(0);
        rotatedHead = snakeBodyHead[0].transformed(transformHead);
      } else if (dir == SnakeModel::Left) {
        transformHead.rotate(-90);
        rotatedHead = snakeBodyHead[0].transformed(transformHead);
      } else if (dir == SnakeModel::Right or dir == SnakeModel::Start or
                 dir == SnakeModel::Pause) {
        transformHead.rotate(90);
        rotatedHead = snakeBodyHead[0].transformed(transformHead);
      } else if (dir == SnakeModel::Down) {
        transformHead.rotate(180);
        rotatedHead = snakeBodyHead[0].transformed(transformHead);
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
                           gridSize / 1.3, gridSize / 1.3, snakeBodyHead[1]);
      else if (dir == SnakeModel::Up or dir == SnakeModel::Down)
        painter.drawPixmap((p.x) * gridSize + 7, (p.y) * gridSize,
                           gridSize / 1.3, gridSize / 1.3, snakeBodyHead[1]);
    }
  }
}
void s21::SnakeView::printStart(QPainter &painter) {
  painter.drawText(rect(), Qt::AlignCenter, "Press S for Start");
}
void s21::SnakeView::printGameOverTetris(QFont &font, QPainter &painter) {
  font.setPointSize(20);
  painter.setFont(font);
  QString str = "Game Over";
  painter.drawText(rect(), Qt::AlignCenter, str);
}
void s21::SnakeView::printGameOver(QFont &font, QPainter &painter) {
  font.setPointSize(20);
  painter.setFont(font);
  QString str = "Game Over";
  static QString str1;
  static int itemp{};
  painter.drawText(rect(), Qt::AlignCenter, str1.append(str[itemp]));
  if (itemp++ == 8) {
    itemp = 0, str1.clear();
  }
}
void s21::SnakeView::printWinGame(QFont &font, QPainter &painter) {
  font.setPointSize(20);
  painter.setFont(font);
  QString str = "Win Game";
  static QString str2;
  static int itemp{};
  painter.drawText(rect(), Qt::AlignCenter, str2.append(str[itemp]));
  itemp++;
  if (itemp == 8) {
    itemp = 0, str2.clear();
  }
}
void s21::SnakeView::printPause(QFont &font, QPainter &painter) {
  font.setPointSize(30);
  painter.setFont(font);
  painter.drawText(rect(), Qt::AlignCenter, "Pause");
}
void s21::SnakeView::printScore(QFont &font, QPainter &painter) {
  QString sScore;
  sScore.append(std::to_string(score));
  font.setPointSize(30);
  painter.setFont(font);
  painter.drawText(5 * gridSize, 1 * gridSize, sScore);
}
void s21::SnakeView::printMaxScore(QFont &font, QPainter &painter) {

  font.setPointSize(12);
  painter.setFont(font);
  painter.drawText(7.7 * gridSize, 0.5 * gridSize, "high score:");

  QString sScore;
  sScore.append(std::to_string(maxScore));
  font.setPointSize(15);
  painter.setFont(font);
  painter.drawText(9.3 * gridSize, 0.5 * gridSize, sScore);
}
void s21::SnakeView::printLevel(QFont &font, QPainter &painter) {

  font.setPointSize(12);
  painter.setFont(font);
  painter.drawText(8.5 * gridSize, 0.9 * gridSize, "level:");

  QString sLevel;
  sLevel.append(std::to_string(level));
  font.setPointSize(15);
  painter.setFont(font);
  painter.drawText(9.5 * gridSize, 0.9 * gridSize, sLevel);
}
void s21::SnakeView::loadSnake(QDir &curD) {
  QString pathHead = curD.absolutePath().append("/skins/s-18.svg");
  QString pathBody = curD.absolutePath().append("/skins/s-16.svg");
  snakeBodyHead[0] = QPixmap(pathHead);
  snakeBodyHead[1] = QPixmap(pathBody);
}
void s21::SnakeView::loadBackgrounds(QDir &curD) {
  QString pathBackground1 =
      curD.absolutePath().append("/backgrounds/back2.jpg");
  QString pathBackground2 =
      curD.absolutePath().append("/backgrounds/back7.jpg");
  backgrounds[0] = QPixmap(pathBackground1);
  backgrounds[1] = QPixmap(pathBackground2);
}

// TETRIS
void s21::SnakeView::printDataTetris(QFont &font, QPainter &painter) {
  font.setPointSize(10);
  painter.setFont(font);

  QString hi_score;
  hi_score.append(std::to_string(g_info.high_score));
  painter.drawText(8.95 * gridSize, 0.3 * gridSize, "hi-score");
  painter.drawText(9.2 * gridSize, 0.6 * gridSize, hi_score);

  QString score;
  score.append(std::to_string(g_info.score));
  painter.drawText(9.3 * gridSize, 1 * gridSize, "score");
  painter.drawText(9.2 * gridSize, 1.3 * gridSize, score);

  painter.drawText(9.45 * gridSize, 1.8 * gridSize, "next");

  QString level;
  level.append(std::to_string(g_info.level));
  painter.drawText(9.4 * gridSize, 3.5 * gridSize, "level");
  painter.drawText(9.6 * gridSize, 3.75 * gridSize, level);

  QString speed;
  speed.append(std::to_string(g_info.speed));
  painter.drawText(9.2 * gridSize, 4 * gridSize, "speed");
  painter.drawText(9.6 * gridSize, 4.25 * gridSize, speed);
}
void s21::SnakeView::loadImagesFigure(QDir &curD) {
  QString pathTetrisFigure1 = curD.absolutePath().append("/skins/s-27.svg");
  QString pathTetrisFigure2 = curD.absolutePath().append("/skins/s-25.svg");
  QString pathTetrisFigure3 = curD.absolutePath().append("/skins/s-23.svg");
  QString pathTetrisFigure4 = curD.absolutePath().append("/skins/s-28.svg");
  QString pathTetrisFigure5 = curD.absolutePath().append("/skins/s-29.svg");
  QString pathTetrisFigure6 = curD.absolutePath().append("/skins/s-26.svg");
  QString pathTetrisFigure7 = curD.absolutePath().append("/skins/s-30.svg");
  Figures[0] = QPixmap(pathTetrisFigure1);
  Figures[4] = QPixmap(pathTetrisFigure2);
  Figures[8] = QPixmap(pathTetrisFigure3);
  Figures[10] = QPixmap(pathTetrisFigure4);
  Figures[12] = QPixmap(pathTetrisFigure5);
  Figures[16] = QPixmap(pathTetrisFigure6);
  Figures[20] = QPixmap(pathTetrisFigure7);
}
void s21::SnakeView::loadImagesNextFigure(QDir &curD) {
  QString pathTetrisNextFigure1 = curD.absolutePath().append("/skins/s-33.svg");
  QString pathTetrisNextFigure2 = curD.absolutePath().append("/skins/s-36.svg");
  QString pathTetrisNextFigure3 = curD.absolutePath().append("/skins/s-37.svg");
  QString pathTetrisNextFigure4 = curD.absolutePath().append("/skins/s-32.svg");
  QString pathTetrisNextFigure5 = curD.absolutePath().append("/skins/s-35.svg");
  QString pathTetrisNextFigure6 = curD.absolutePath().append("/skins/s-34.svg");
  QString pathTetrisNextFigure7 = curD.absolutePath().append("/skins/s-31.svg");
  nextFigures[0] = QPixmap(pathTetrisNextFigure1);
  nextFigures[4] = QPixmap(pathTetrisNextFigure2);
  nextFigures[8] = QPixmap(pathTetrisNextFigure3);
  nextFigures[10] = QPixmap(pathTetrisNextFigure4);
  nextFigures[12] = QPixmap(pathTetrisNextFigure5);
  nextFigures[16] = QPixmap(pathTetrisNextFigure6);
  nextFigures[20] = QPixmap(pathTetrisNextFigure7);

  for (int i : {0, 4, 8, 10, 12, 16, 20}) {
    if (Figures[i].isNull()) {
      qDebug() << "Failed to load image for index:" << i;
    }
  }
}
void s21::SnakeView::printFieldTetris(QPainter &painter) {
  for (int i{}; i < 20; i++)
    for (int k{}; k < 10; k++) {
      if (g_info.field[i][k] == 0)
        painter.drawPixmap(k * gridSize, i * gridSize, 40, 40, Figures[0]);
      else if (g_info.field[i][k] == 4)
        painter.drawPixmap(k * gridSize, i * gridSize, 40, 40, Figures[4]);
      else if (g_info.field[i][k] == 8)
        painter.drawPixmap(k * gridSize, i * gridSize, 40, 40, Figures[8]);
      else if (g_info.field[i][k] == 10)
        painter.drawPixmap(k * gridSize, i * gridSize, 40, 40, Figures[10]);
      else if (g_info.field[i][k] == 12)
        painter.drawPixmap(k * gridSize, i * gridSize, 40, 40, Figures[12]);
      else if (g_info.field[i][k] == 16)
        painter.drawPixmap(k * gridSize, i * gridSize, 40, 40, Figures[16]);
      else if (g_info.field[i][k] == 20)
        painter.drawPixmap(k * gridSize, i * gridSize, 40, 40, Figures[20]);
    }
}
void s21::SnakeView::printNextFigureTetris(QPainter &painter) {
  for (int i{}; i < 4; i++)
    for (int k{}; k < 4; k++)
      if (g_info.next[i][k] == 1)
        painter.drawPixmap((9.1 + k * 0.2) * gridSize, (2 + i * 0.2) * gridSize,
                           10, 10, nextFigures[idNextFigure]);
}

// Setters and Getters
// SNAKE
void s21::SnakeView::set_dir(SnakeModel::Direction dir) { this->dir = dir; }
void s21::SnakeView::set_mg(SnakeModel::MenuGames mg) { this->mg = mg; }
void s21::SnakeView::setSnake(QList<SnakeModel::PointSnake> snake) {
  this->snake = snake;
}
void s21::SnakeView::setFood(SnakeModel::Point food) { this->food = food; }
void s21::SnakeView::setScore(int score) { this->score = score; }
void s21::SnakeView::setFruits(QList<QString> fruits) { this->fruits = fruits; }
void s21::SnakeView::setMaxScore(int maxScore) { this->maxScore = maxScore; }
void s21::SnakeView::setLevel(int newLevel) { level = newLevel; }

// TETRIS
void s21::SnakeView::setState(state_s newState) { this->state = newState; }
void s21::SnakeView::setAction(UserAction_t newAction) {
  this->action = newAction;
}
void s21::SnakeView::setG_Info(GameInfo_t newG_Info) {
  this->g_info = newG_Info;
}
void s21::SnakeView::setIdFigure(int newIdFigure) {
  this->idFigure = newIdFigure;
}
void s21::SnakeView::setIdNextFigure(int newIdNextFigure) {
  this->idNextFigure = newIdNextFigure;
}
