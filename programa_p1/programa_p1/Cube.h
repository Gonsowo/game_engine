#pragma once
#include <GL/glut.h>
#include <vector>
#include "Color.h"
#include "Solid.h"

class Cube : public Solid
{
	private:
		float size;

	public:
		Cube() : size(0), Solid() { }
		Cube(float dsize, vector3D dorientationSpeed, vector3D dcoordinates, vector3D dorientation, Color dcolor) : size(dsize), Solid(dorientationSpeed, dcoordinates, dorientation, dcolor) { }


		/////////////////GETTERS////////////////
		inline float getsize() const { return this->size; }


		/////////////////SETTERS////////////////
		inline void setsize(const float& sizetoSet) { this->size = sizetoSet; }


		void Render();

		void Update();

};

