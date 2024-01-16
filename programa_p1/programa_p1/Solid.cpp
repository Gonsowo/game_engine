#include "Solid.h"

vector3D Solid::getOrientationSpeed() {
	vector3D v;
	v.setX(this->getOrientationSpeedX());
	v.setY(this->getOrientationSpeedY());
	v.setZ(this->getOrientationSpeedZ());
	return v;
}

vector3D Solid::getSpeed() {
	vector3D v;
	v.setX(this->getSpeedX());
	v.setY(this->getSpeedY());
	v.setZ(this->getSpeedZ());
	return v;
}

vector3D Solid::getCoordinates() {
	vector3D v;
	v.setX(this->getcoordinateX());
	v.setY(this->getcoordinateY());
	v.setZ(this->getcoordinateZ());
	return v;
}

vector3D Solid::getOrientation() {
	vector3D v;
	v.setX(this->getorientationX());
	v.setY(this->getorientationY());
	v.setZ(this->getorientationZ());
	return v;
}

Color Solid::getColorComponent() {
	Color v;
	v.setRed(this->getredComponent());
	v.setBlue(this->getblueComponent());
	v.setGreen(this->getgreenComponent());
	return v;
}

void Solid::setOrientationSpeed(vector3D orientationSpeedToSet) {
	this->orientationSpeed.setX(orientationSpeedToSet.getX());
	this->orientationSpeed.setY(orientationSpeedToSet.getY());
	this->orientationSpeed.setZ(orientationSpeedToSet.getZ());
}

void Solid::setSpeed(vector3D SpeedToSet) {
	this->speed.setX(SpeedToSet.getX());
	this->speed.setY(SpeedToSet.getY());
	this->speed.setZ(SpeedToSet.getZ());
}

void Solid::setCoordinates(vector3D coordinatesToSet) {
	this->coordinates.setX(coordinatesToSet.getX());
	this->coordinates.setY(coordinatesToSet.getY());
	this->coordinates.setZ(coordinatesToSet.getZ());
}

void Solid::setOrientation(vector3D orientationToSet) {
	this->orientation.setX(orientationToSet.getX());
	this->orientation.setY(orientationToSet.getY());
	this->orientation.setZ(orientationToSet.getZ());
}

void Solid::setColorComponent(Color colorToSet) {
	this->colorComponent.setRed(colorToSet.getRed());
	this->colorComponent.setBlue(colorToSet.getBlue());
	this->colorComponent.setGreen(colorToSet.getGreen());
}

void Solid::Update(const float& time) {
	this->setOrientation(this->getOrientation() + this->getOrientationSpeed() * time);
	this->setCoordinates(this->getCoordinates() + this->getSpeed() * time);
}