#pragma once
#include <vector>
#include "vector3D.h"
#include "Solid.h"
#include <iostream>

using namespace std;

class Scene
{
private:
	vector3D boundary;
	vector<Solid*> gameObjects;

	void checkBoundary(Solid* vector);

public:
	Scene() : boundary(9.0,6.0,8.0) {}

	inline void AddGameObject(Solid* newobject) { gameObjects.push_back(newobject); }
	void Render() { for (Solid* var : gameObjects) { var->Render(); } }
	void Update(const float& time);

	inline float getBoundaryX() const { return this->boundary.getX(); }
	inline float getBoundaryY() const { return this->boundary.getY(); }
	inline float getBoundaryZ() const { return this->boundary.getZ(); }
	vector3D getBoundary();

	inline void setBoundaryX(const float& d) { this->boundary.setX(d); }
	inline void setBoundaryY(const float& d) { this->boundary.setY(d); }
	inline void setBoundaryZ(const float& d) { this->boundary.setZ(d); }
	void setBoundary(vector3D d);
};


