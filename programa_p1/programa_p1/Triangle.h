#pragma once
#include <GL/glut.h>
#include <vector>
#include "Color.h"
#include "Solid.h"

using namespace std;

class Triangle : public Solid
{
private:
	vector3D position[3];
	vector3D normal[3];
	Color color[3];

public:
	Triangle() : position{vector3D(), vector3D(), vector3D() }, normal{ vector3D(), vector3D(), vector3D() }, color{ Color(), Color(), Color() } {}
	Triangle(vector3D p1, vector3D p2, vector3D p3, vector3D n1, vector3D n2, vector3D n3) : position{ p1, p2, p3 }, normal{ n1,n2,n3 }, color{ Color(), Color(), Color() } {}

	/////////////////GETTERS////////////////
	inline vector3D getVertex0() { return this->position[0].getVector(); }
	inline vector3D getVertex1() { return this->position[1].getVector(); }
	inline vector3D getVertex2() { return this->position[2].getVector(); }

	inline vector3D getNormal0() { return this->normal[0].getVector(); }
	inline vector3D getNormal1() { return this->normal[1].getVector(); }
	inline vector3D getNormal2() { return this->normal[2].getVector(); }

	/////////////////SETTERS////////////////
	inline void setColor0(const Color& d) { this->color[0] = d; }
	inline void setColor1(const Color& d) { this->color[1] = d; }
	inline void setColor2(const Color& d) { this->color[2] = d; }


	void Render();

	void Update();

};
