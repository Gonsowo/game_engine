#include "Camera.h"

void Camera::Render() {
	glTranslatef(-1 * this->getcoordinateX(), -1 * this->getcoordinateY(), -1 * this->getcoordinateZ());
	glRotatef(this->getorientationX(), 1.0, 0.0, 0.0);
	glRotatef(this->getorientationY(), 0.0, 1.0, 0.0);
	glRotatef(this->getorientationZ(), 0.0, 0.0, 1.0);
}

void Camera::Update() {}