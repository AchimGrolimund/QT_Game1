#include <QDebug>

#include "shoot.h"
#include "gameobject.h"

Shoot::Shoot(int x, int y, int speed, int angle)
	: GameObject(x, y, ":/Game/Images/img/rocket.png", 50) {
	this->speed = speed;
	this->angle = angle;
	qDebug() << "Shoot konstruktor[speed-->" << speed << "]" << "[Angle-->" << angle << "]";
}

void Shoot::move() {
	const double g = 9.81;
	double rad = 3.1415926 / 180 * angle;
	int dx = speed / 3 * cos(rad) * t;
	int dy = speed / 3 * sin(rad) * t - (g / 2 ) * pow(t, 2 );
	t = t + 0.1;
	x = x + dx / 2 ;
	y = y - dy / 2 ; // + oder - ......
	//--------------------------------------------------
	//--------------------------------------------------
//	x += 2;
//	y -= 1.5;
}
