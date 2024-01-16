#include "Score.h"
 
void Score::Update(const float& time) {
	this->UpScore();

	this->SetScore(to_string(this->GetScore()));

	//ALIGN
	this->setCoordinates(ogCoords + vector3D(-0.1,0,0) * CountDigits(points));

}