#pragma once
#include <GL/glut.h>
#include "vector3D.h"
#include "Color.h"
#include "Solid.h"

class Teapot : public Solid
{
private:

	float size;

public:
	Teapot() : Solid(), size(0.0) {}
	Teapot(float dsize, vector3D dorientationSpeed,vector3D dcoordinates, vector3D dorientation, Color dcolor) : size(dsize), Solid(dorientationSpeed, dcoordinates, dorientation, dcolor) { }

	/////////////////GETTERS////////////////
	inline float getsize() const { return this->size; }


	/////////////////SETTERS////////////////
	inline void setsize(const float& sizetoSet) { this->size = sizetoSet; }

	void Update();

	void Render();


};


