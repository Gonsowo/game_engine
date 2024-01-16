#pragma once
#include <GL/glut.h>
#include <vector>
#include "Color.h"
#include "Solid.h"

class Camera : public Solid
{
public:
	Camera() : Solid() {}
	Camera(vector3D dpos) : Solid() {
		this->setCoordinates(dpos);
	}

	void Render();

	void Update();
};

