#include "Triangle.h"

void Triangle::Render() {
	glBegin(GL_TRIANGLES);
	//vértice 1
	glColor3f(color[0].getRed(), color[0].getGreen(), color[0].getBlue());
	glNormal3f(normal[0].getX(), normal[0].getY(), normal[0].getZ());
	glVertex3f(position[0].getX(), position[0].getY(), position[0].getZ());
	//vértice 2
	glColor3f(color[1].getRed(), color[1].getGreen(), color[1].getBlue());
	glNormal3f(normal[1].getX(), normal[1].getY(), normal[1].getZ());
	glVertex3f(position[1].getX(), position[1].getY(), position[1].getZ());
	//vértice 3
	glColor3f(color[2].getRed(), color[2].getGreen(), color[2].getBlue());
	glNormal3f(normal[2].getX(), normal[2].getY(), normal[2].getZ());
	glVertex3f(position[2].getX(), position[2].getY(), position[2].getZ());
	glEnd();
}

void Triangle::Update() {
	
}