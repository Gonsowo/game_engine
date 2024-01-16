#include "Text.h"

void Text::Render() {
	glPushMatrix();
	glColor3f(this->getredComponent(), this->getgreenComponent(), this->getblueComponent());
	glTranslatef(this->getcoordinateX(), this->getcoordinateY(), this->getcoordinateZ());
	glRasterPos3d(0, 0, 0);
	for (char c : text)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
	glPopMatrix();
}