#pragma once
#include <GL/glut.h>
#include <vector>
#include "Color.h"
#include "Solid.h"

class Prism : public Solid
{
private:
	float length;
	float heigth;
	float width;

public:
	Prism() : length(0.0), heigth(0.0), width(0.0), Solid() { }
	Prism(float dl, float dh, float dw, vector3D dorientationSpeed, vector3D dcoordinates, vector3D dorientation, Color dcolor) : length(dl), heigth(dh), width(dw), Solid(dorientationSpeed, dcoordinates, dorientation, dcolor) { }


	/////////////////GETTERS////////////////
	inline float getLength() const { return this->length; }
	inline float getHeigth() const { return this->heigth; }
	inline float getWidth() const { return this->width; }


	/////////////////SETTERS////////////////
	inline void setLength(const float& lengthtoSet) { this->length = lengthtoSet; }
	inline void setHeigth(const float& heigthtoSet) { this->heigth = heigthtoSet; }
	inline void setWidth(const float& widthtoSet) { this->width = widthtoSet; }


	void Render();

	void Update();

};


