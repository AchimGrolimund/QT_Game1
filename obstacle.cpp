#include "obstacle.h"
#include "gameobject.h"

#include <QImage>
#include <QDebug>

Obstacle::Obstacle(int x, int y)
	: GameObject(x, y, ":/Game/Images/img/Red_Angry.png", 80) {
	qDebug() << "Constructor Obstacle";
}

void Obstacle::move() {
	//leer lassen (obstacle bewegt sich nicht) //noch nicht
}
