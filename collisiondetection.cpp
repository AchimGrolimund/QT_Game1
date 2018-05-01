#include "collisiondetection.h"

#include <QDebug>

CollisionDetection::CollisionDetection() {
}

bool CollisionDetection::CheckCollision(GameObject *go_kugel, GameObject *go_enemy) {
	if (go_kugel->getY() >= go_enemy->getY() && go_kugel->getY() <= go_enemy->getY() + go_enemy->height()) {
		if (go_kugel->getX() >= go_enemy->getX() - 10 && go_kugel->getX() <= go_enemy->getX() + go_enemy->width() ) {
			return true;
		}
	}
	return false;
}
