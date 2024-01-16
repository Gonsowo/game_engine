#pragma once
#include <GL/glut.h>
#include <vector>
#include "Color.h"
#include "Solid.h"

class Torus : public Solid
{
private:
	float rad1;
	float rad2;
	float faces;
	float rings;

public:
	Torus() : rad1(0.0), rad2(0.0), faces(0.0), rings(0.0), Solid() { }
	Torus(float drad1, float drad2, float dfaces, float drings, vector3D dorientationSpeed, vector3D dcoordinates, vector3D dorientation, Color dcolor) : rad1(drad1), rad2(drad2), faces(dfaces), rings(drings), Solid(dorientationSpeed, dcoordinates, dorientation, dcolor) { }


	/////////////////GETTERS////////////////
	inline float getRad1() const { return this->rad1; }
	inline float getRad2() const { return this->rad2; }
	inline float getFaces() const { return this->faces; }
	inline float getRings() const { return this->rings; }


	/////////////////SETTERS////////////////
	inline void setRad1(const float& rad1toSet) { this->rad1 = rad1toSet; }
	inline void setRad2(const float& rad2toSet) { this->rad2 = rad2toSet; }
	inline void setFaces(const float& facestoSet) { this->faces = facestoSet; }
	inline void setRings(const float& ringstoSet) { this->rings = ringstoSet; }

	void Render();

	void Update();

};


