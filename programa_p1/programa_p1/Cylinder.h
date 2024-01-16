#pragma once
#include <GL/glut.h>
#include <vector>
#include "Color.h"
#include "Solid.h"

class Cylinder : public Solid
{
private:
	float radbase;
	float radtop;
	float heigth;
	float slices;
	float stacks;

public:
	Cylinder() : radbase(0.0), radtop(0.0), heigth(0.0), slices(0.0), stacks(0.0), Solid() { }
	Cylinder(float dradbase, float dradtop, float dheigth, float dslices, float dstacks, vector3D dorientationSpeed, vector3D dcoordinates, vector3D dorientation, Color dcolor)
		: radbase(dradbase), radtop(dradtop), heigth(dheigth), slices(dslices), stacks(dstacks), Solid(dorientationSpeed, dcoordinates, dorientation, dcolor) { }


	/////////////////GETTERS////////////////
	inline float getRadbase() const { return this->radbase; }
	inline float getRadtop() const { return this->radtop; }
	inline float getHeigth() const { return this->heigth; }
	inline float getSlices() const { return this->slices; }
	inline float getStacks() const { return this->stacks; }


	/////////////////SETTERS////////////////
	inline void setRadbase(const float& radbasetoSet) { this->radbase = radbasetoSet; }
	inline void setRadtop(const float& radtoptoSet) { this->radtop = radtoptoSet; }
	inline void setHeigth(const float& heigthtoSet) { this->heigth = heigthtoSet; }
	inline void setSlices(const float& slicestoSet) { this->slices = slicestoSet; }
	inline void setStacks(const float& stackstoSet) { this->stacks = stackstoSet; }


	void Render();

	void Update();

};

