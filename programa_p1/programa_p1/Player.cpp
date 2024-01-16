#include "Player.h"

using namespace std;

void Player::Update(const float& time) {

	if (this->getcoordinateX() - this->GetFinalCoord() != 0) {
		this->SetMove(true);
		Solid::Update(time);
	}
	else { this->SetMove(false); }
}

