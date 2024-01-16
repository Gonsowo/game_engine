#pragma once
#include <iostream>
#include "Cube.h"
#include <cmath>

class Player : public Cube
{
private:
	float finalCoord;
	bool move;

public:
	Player() : Cube(), finalCoord(0.0), move(false) {};

	inline const float GetFinalCoord() { return this->finalCoord; };
	inline const bool GetMove() { return this->move; };

	inline void SetFinalCoord(const float& dtime) { this->finalCoord = dtime; }
	inline void SetMove(const bool& dmove) { this->move = dmove; }

	void Update(const float& time);

};

