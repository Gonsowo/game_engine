#include "Prism.h"
void Prism::Render() {
	glPushMatrix();
	glTranslatef(this->getcoordinateX(), this->getcoordinateY(), this->getcoordinateZ());
	glColor3f(this->getredComponent(), this->getgreenComponent(), this->getblueComponent());
	glRotatef(this->getorientationX(), 1.0, 0.0, 0.0);
	glRotatef(this->getorientationY(), 0.0, 1.0, 0.0);
	glRotatef(this->getorientationZ(), 0.0, 0.0, 1.0);
	glScalef(this->getLength(), this->getHeigth(), this->getWidth());
	glutSolidCube(1);
	glPopMatrix();
}
