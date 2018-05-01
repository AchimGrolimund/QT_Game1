#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include "gameobject.h"

class CollisionDetection {
  public:
	CollisionDetection();
	static bool CheckCollision(GameObject *go_kugel, GameObject *go_enemy);
};

#endif // COLLISIONDETECTION_H
