#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QImage>
#include <QVector>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QString>
#include <QWidget>
#include <QSoundEffect>

#include "obstacle.h"
#include "player.h"
#include "shoot.h"

class GameArea : public QWidget {
  private:
	QVector<GameObject *> gameObjects;
  public:
	explicit GameArea(QWidget *parent = nullptr);
	void paintEvent(QPaintEvent *event);
	QImage *backgroundImg;
	void startGame();
	void shoot(int speed, int angle);
	void next();
	QPaintEvent *event;
	QPainter *painter;
	QSoundEffect *youLoose;
	QSoundEffect *youWin;

  protected:
	void gameFinished();

  signals:

  public slots:
};

#endif // GAMEAREA_H
