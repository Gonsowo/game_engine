#pragma once
#include "Text.h"
#include <String>
#include <cmath>
#include <iostream>

using namespace std;

class Score : public Text
{
private:
	int points;
	vector3D ogCoords = this->getCoordinates();

	inline void UpScore() { this->points++; }
	inline int CountDigits(const int n) { return int(log10(n)); }

public:
	Score() : Text(string("Score: "), vector3D(4.0, 11.0, -0.2)), points(0) {};

	inline const int GetScore() { return this->points; }

	inline void SetScore(const string& text) { this->setText(text); }

	inline void Reset() { this->points = 0; }

	inline void ScoreBonus(const float& time) { this->points = this->points + 200 + time / 5; }


	void Update(const float& time);
};

