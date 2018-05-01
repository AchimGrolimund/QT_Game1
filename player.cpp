#include "player.h"
#include "gameobject.h"

Player::Player(int x, int y)
	: GameObject(x, y, ":/Game/Images/img/worms 3 bazooka.png", 100) {
}

void Player::move() {
	//leer lassen (player bewegt sich nicht) // noch nicht
}
