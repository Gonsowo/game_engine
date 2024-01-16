#pragma once
#include "Model.h"
#include "vector3D.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;


class ModelLoader
{
private:
	float size;
	Model model;
	float vmax[3];
	float vmin[3];
	vector<vector3D> normals;
	vector<vector3D> vertexes;

	inline float getWidth() { return vmax[0] - vmin[0]; }
	inline float getHeight() { return vmax[1] - vmin[1]; }
	inline float getLenght() { return vmax[2] - vmin[2]; }

	void calcBoundaries(const vector3D v);
	Triangle Center(Triangle t);
	vector3D parseObjLineToVector3D(const string& s);
	Triangle parseObjLineTriangle(const string& s);
public:

	inline Model getModel() { return this->model; }

	inline float getSize() { return this->size; }
	inline void setSize(const float& sizetoset) { this->size = sizetoset; }
	void LoadModel(const string& s);
	inline void Clear() { this->model.Clear(); }
};

