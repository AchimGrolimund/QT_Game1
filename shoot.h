#ifndef SHOOT_H
#define SHOOT_H

#include "gameobject.h"

class Shoot : public GameObject {
  public:
	Shoot(int x, int y, int speed, int angle);
	virtual void move();
  private:
	int speed;
	int angle;
	double t;
};

#endif // SHOOT_H
