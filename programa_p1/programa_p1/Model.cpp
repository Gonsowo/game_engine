#include "Model.h"

void Model::Render() {
	glPushMatrix();
	glTranslatef(this->getcoordinateX(), this->getcoordinateY(), this->getcoordinateZ());
	glColor3f(this->getredComponent(), this->getgreenComponent(), this->getblueComponent());
	glRotatef(this->getorientationX(), 1.0, 0.0, 0.0);
	glRotatef(this->getorientationY(), 0.0, 1.0, 0.0);
	glRotatef(this->getorientationZ(), 0.0, 0.0, 1.0);
	for (Triangle& triangle : this->pol) {
		triangle.Render();
	}
	glPopMatrix();
}

void Model::PaintColor(Color color) {
	for (Triangle& triangle : this->pol) {
		triangle.setColor0(color);
		triangle.setColor1(color);
		triangle.setColor2(color);
	}
}


