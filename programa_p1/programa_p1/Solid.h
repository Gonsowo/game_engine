#pragma once
#include "Color.h"
#include "vector3D.h"

class Solid
{

private:

	vector3D orientationSpeed;

	vector3D speed;

	vector3D coordinates;

	vector3D orientation;

	Color colorComponent;

public:

	Solid() : colorComponent(0.0, 0.0, 0.0), orientation(0.0, 0.0, 0.0), coordinates(0.0, 0.0, 0.0), orientationSpeed(0.0, 0.0, 0.0), speed(0.0 ,0.0,0.0) {}
	Solid(vector3D dorientationSpeed, vector3D dcoordinates, vector3D dorientation, Color dcolor) : orientationSpeed(dorientationSpeed), coordinates(dcoordinates), orientation(dorientation), colorComponent(dcolor) {}

	/////////////////GETTERS////////////////
	inline float getOrientationSpeedX() const { return this->orientationSpeed.getX(); }
	inline float getOrientationSpeedY() const { return this->orientationSpeed.getY(); }
	inline float getOrientationSpeedZ() const { return this->orientationSpeed.getZ(); }
	vector3D getOrientationSpeed();

	inline float getSpeedX() const { return this->speed.getX(); }
	inline float getSpeedY() const { return this->speed.getY(); }
	inline float getSpeedZ() const { return this->speed.getZ(); }
	vector3D getSpeed();

	inline float getcoordinateX() const { return this->coordinates.getX(); }
	inline float getcoordinateY() const { return this->coordinates.getY(); }
	inline float getcoordinateZ() const { return this->coordinates.getZ(); }
	vector3D getCoordinates(); 

	inline float getorientationX() const { return this->orientation.getX(); }
	inline float getorientationY() const { return this->orientation.getY(); }
	inline float getorientationZ() const { return this->orientation.getZ(); }
	vector3D getOrientation();

	inline float getredComponent() const { return this->colorComponent.getRed(); }
	inline float getgreenComponent() const { return this->colorComponent.getGreen(); }
	inline float getblueComponent() const { return this->colorComponent.getBlue(); }
	Color getColorComponent();



	/////////////////SETTERS////////////////
	inline void setSpeedX(const float& SpeedXtoSet) { this->speed.setX(SpeedXtoSet); }
	inline void setSpeedY(const float& SpeedYtoSet) { this->speed.setY(SpeedYtoSet); }
	inline void setSpeedZ(const float& SpeedZtoSet) { this->speed.setZ(SpeedZtoSet); }
	void setSpeed(vector3D orientationSpeedToSet);

	inline void setOrientationSpeedX(const float& orientationSpeedXtoSet) { this->orientationSpeed.setX(orientationSpeedXtoSet); }
	inline void setOrientationSpeedY(const float& orientationSpeedYtoSet) { this->orientationSpeed.setY(orientationSpeedYtoSet); }
	inline void setOrientationSpeedZ(const float& orientationSpeedZtoSet) { this->orientationSpeed.setZ(orientationSpeedZtoSet); }
	void setOrientationSpeed(vector3D orientationSpeedToSet);

	inline void setcoordinateX(const float& coordinateXtoSet) { this->coordinates.setX(coordinateXtoSet); }
	inline void setcoordinateY(const float& coordinateYtoSet) { this->coordinates.setY(coordinateYtoSet); }
	inline void setcoordinateZ(const float& coordinateZtoSet) { this->coordinates.setZ(coordinateZtoSet); }
	void setCoordinates(vector3D coordinatesToSet);

	inline void setorientationX(const float& orientationXtoSet) { this->orientation.setX(orientationXtoSet); }
	inline void setorientationY(const float& orientationYtoSet) { this->orientation.setY(orientationYtoSet); }
	inline void setorientationZ(const float& orientationZtoSet) { this->orientation.setZ(orientationZtoSet); }
	void setOrientation(vector3D orientationToSet);

	inline void setredComponent(const float& redComponenttoSet) { this->colorComponent.setRed(redComponenttoSet); }
	inline void setgreenComponent(const float& greenComponenttoSet) { this->colorComponent.setGreen(greenComponenttoSet); }
	inline void setblueComponent(const float& blueComponenttoSet) { this->colorComponent.setBlue(blueComponenttoSet); }
	void setColorComponent(Color colorToSet);

	virtual void Update(const float& time);

	virtual void Render() = 0;
};

