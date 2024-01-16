#include "Cylinder.h"
void Cylinder::Render() {
	GLUquadricObj* quadricTemp = gluNewQuadric();
	glPushMatrix();
	glTranslatef(this->getcoordinateX(), this->getcoordinateY(), this->getcoordinateZ());
	glColor3f(this->getredComponent(), this->getgreenComponent(), this->getblueComponent());
	glRotatef(this->getorientationX(), 1.0, 0.0, 0.0);
	glRotatef(this->getorientationY(), 0.0, 1.0, 0.0);
	glRotatef(this->getorientationZ(), 0.0, 0.0, 1.0);
	gluCylinder(quadricTemp, this->getRadbase(), this->getRadtop(), this->getHeigth(), this->getSlices(), this->getStacks());
	glPopMatrix();
	gluDeleteQuadric(quadricTemp);
}
