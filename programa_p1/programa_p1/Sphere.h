#pragma once
#include <GL/glut.h>
#include <vector>
#include "Color.h"
#include "Solid.h"


class Sphere : public Solid
{
private:

	float radius;
	float slacks;
	float slices;
 
public:
	Sphere() : radius(0.0), slices(0.0), slacks(0.0), Solid() { }
	Sphere(float dradius, float dslacks, float dslices, vector3D dorientationSpeed, vector3D dcoordinates, vector3D dorientation, Color dcolor) : radius(dradius), slacks(dslacks), slices(dslices), Solid(dorientationSpeed, dcoordinates, dorientation, dcolor) { }


	/////////////////GETTERS////////////////
	inline float getradiusComponent() const { return this->radius; }
	inline float getslacksComponent() const { return this->slacks; }
	inline float getslicesComponent() const { return this->slices; }


	/////////////////SETTERS////////////////
	inline void setRadius(const float& radiustoSet) { this->radius = radiustoSet; }
	inline void setSlacks(const float& slackstoSet) { this->slacks = slackstoSet; }
	inline void setSlices(const float& slicestoSet) { this->slices = slicestoSet; }


	void Render();

	void Update();

};

