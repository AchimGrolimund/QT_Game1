#include "gamearea.h"
#include "gameobject.h"
#include "obstacle.h"
#include "player.h"
#include "shoot.h"
#include "thread.h"
#include "collisiondetection.h"

#include <QDebug>
#include <QPainter>
#include <QWidget>
#include <QSoundEffect>

GameArea::GameArea(QWidget *parent) : QWidget(parent) {
	Thread *t = new Thread();
	QObject::connect(t, &Thread::refresh, this, &GameArea::next);
	t->start();
	youLoose = new QSoundEffect;
	youLoose->setSource(QUrl::fromLocalFile(":/Game/Sounds/sounds/178875__rocotilos__you-lose-evil.wav"));
	youWin = new QSoundEffect;
	youWin->setSource(QUrl::fromLocalFile(":/Game/Sounds/sounds/sfx-explosion-treffer.wav"));
}

void GameArea::paintEvent(QPaintEvent *event) {
	//painter QPainter(this);
	QPainter painter(this);
	painter.setRenderHint(QPainter::HighQualityAntialiasing);
	painter.setPen(QPen(Qt::white, 2));
	//--------------------------------------------------
//	painter->drawText((width() - 45) / 2, (height() - 80) / 2,  "GameArea");
//	painter->drawLine(0, 0, width(), height());
//	painter->drawLine(width(), 0, 0, height());
//	painter->drawRect(0, 0, width(), height());
	//--------------------------------------------------
	painter.drawImage(0, 0, QImage(":/Game/Images/img/background.jpg"));
	for (GameObject *x : gameObjects) {
		x->paint(&painter);
	}
}
void GameArea::startGame() {
	Obstacle *obst = new Obstacle(700, 20);
	Player *play = new Player(10, 490);
	gameObjects.push_back(play);
	gameObjects.push_back(obst);
	this->update();
}

void GameArea::shoot(int speed, int angle) {
	Shoot *kugel = new Shoot(88, 495, speed, angle);
	gameObjects.push_back(kugel);
	//kugel->paint(painter); Absturz wen aktiv...
}

void GameArea::next() {
	for (GameObject *obj : gameObjects) {
		obj->move();
		if (obj->getX() >= 1000 || obj->getY() >= 600) {
			youLoose->play();
			qDebug() << "gameObjects size --> " << gameObjects.size();
			gameObjects.removeOne(obj);
			qDebug() << "rem gameObjects size --> " << gameObjects.size();
			delete obj;
		}
	}
	//--------------------------------------------------
	for (int i(0); i < gameObjects.size(); ++i) {
		// Collision detection
		//0 -> Player
		//1 -> Enemy
		//2...n -> Rockets obj
		if ((gameObjects.size() > 2 && i > 1) && (gameObjects.size() > i))  {
			qDebug() << "Collision Loop";
			if (CollisionDetection::CheckCollision(gameObjects.at(i), gameObjects.at(1))) {
				qDebug() << "Collision with Enemy";
				youWin->play();
				gameObjects.at(i);
				delete gameObjects.at(i);
				qDebug() << "Remove Rocket"; //Absturz nach Ausgabe
			}
		}
	}
	this->update();
}
