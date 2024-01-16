#include "Enemy.h"

bool Enemy::CheckCollision(Player* p, Solid* b) {
	if ((p->getcoordinateX() > (b->getcoordinateX() + 2) || p->getcoordinateX() < (b->getcoordinateX() - 2)) ||
		(p->getcoordinateY() > (b->getcoordinateY() + 2) || p->getcoordinateY() < (b->getcoordinateY() - 2)) ||
		(p->getcoordinateZ() > (b->getcoordinateZ() + 2) || p->getcoordinateZ() < (b->getcoordinateZ() - 2)))
	{
		return false;
	}
	else {
		std::cout << "EwE";
		b->setcoordinateX(100.0);
		return true;
	}

}