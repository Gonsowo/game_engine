#include "Scene.h"

void Scene::checkBoundary(Solid* vector) {
	if (vector->getcoordinateX() > this->getBoundaryX() || vector->getcoordinateX() < -1.0) vector->setSpeedX(0.0);
	if (vector->getcoordinateY() > this->getBoundaryY() || vector->getcoordinateY() < 0.0) vector->setSpeedY(0.0);
	//if (vector->getcoordinateZ() > this->getBoundaryZ() || vector->getcoordinateZ() < 0.0) vector->setSpeedZ(0.0);
}

vector3D Scene::getBoundary() {
	vector3D v;
	v.setX(this->getBoundaryX());
	v.setY(this->getBoundaryY());
	v.setZ(this->getBoundaryZ());
	return v;
}

void Scene::setBoundary(vector3D d) {
	this->boundary.setX(d.getX());
	this->boundary.setY(d.getY());
	this->boundary.setZ(d.getZ());
}

void Scene::Update(const float& time) {
	for (Solid* var : gameObjects) { 
		checkBoundary(var);
		var->Update(time); 
	} 
}