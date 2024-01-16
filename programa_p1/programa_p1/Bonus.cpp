#include "Bonus.h"

bool Bonus::CheckCollision(Player* p, Solid* b) {
	if ((p->getcoordinateX() > (b->getcoordinateX() + 2) || p->getcoordinateX() < (b->getcoordinateX() - 2)) ||
		(p->getcoordinateY() > (b->getcoordinateY() + 2) || p->getcoordinateY() < (b->getcoordinateY() - 2)) ||
		(p->getcoordinateZ() > (b->getcoordinateZ() + 2) || p->getcoordinateZ() < (b->getcoordinateZ() - 2)))
	{
		return false;
	}
	else {
		std::cout << "OwO";
		b->setcoordinateX(100.0);
		return true;
	}
	
}
