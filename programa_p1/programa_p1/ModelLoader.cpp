#include "ModelLoader.h"

void ModelLoader::LoadModel(const string& filePath) {
	try {
		ifstream objFile(filePath);
		if (objFile.is_open()) {
			string line;
			int count = 0;
			while (getline(objFile, line)) {
				if (line[0] == 'v' && line[1] == 'n') {
					vector3D normal = this->parseObjLineToVector3D(line);
					this->normals.push_back(normal);
				}
				else if (line[0] == 'v') {
					vector3D vertex = this->parseObjLineToVector3D(line);
					this->calcBoundaries(vertex);
					this->vertexes.push_back(vertex);
				}
				else if (line[0] == 'f') {
					Triangle triangle = this->parseObjLineTriangle(line);
					this->model.AddTriangle(this->Center(triangle));
				}
			}
			objFile.close();
		}
		else {
			cout << "No se ha podido abrir el archivo desde: " << filePath;
		}
	}
	catch (exception& ex) {
		cout << "Excepcion al abrir: " << filePath;
		cout << ex.what();
	}
}

vector3D ModelLoader::parseObjLineToVector3D(const string& line) {
	string typeOfPoint;
	float xCoord, yCoord, zCoord;
	istringstream stringStream(line);
	stringStream >> typeOfPoint >> xCoord >> yCoord >> zCoord;
	vector3D vectorPoint(xCoord, yCoord, zCoord);
	return vectorPoint * this->getSize();
}

Triangle ModelLoader::parseObjLineTriangle(const string& line) {
	char c;
	int idxVertex0, idxVertex1, idxVertex2;
	int idxNormal0, idxNormal1, idxNormal2;

	istringstream stringStream(line);
	stringStream >> c;
	stringStream >> idxVertex0 >> c >> c >> idxNormal0;
	stringStream >> idxVertex1 >> c >> c >> idxNormal1;
	stringStream >> idxVertex2 >> c >> c >> idxNormal2;

	vector3D vertex0 = this->vertexes[idxVertex0 - 1];
	vector3D vertex1 = this->vertexes[idxVertex1 - 1];
	vector3D vertex2 = this->vertexes[idxVertex2 - 1];	
	vector3D normal = this->normals[idxNormal0 - 1];

	Triangle parsedTriangle(vertex0, vertex1, vertex2, normal, normal, normal);

	return parsedTriangle;
}

void ModelLoader::calcBoundaries(const vector3D vectorPoint) {
	this->vmax[0] = fmax(this->vmax[0], vectorPoint.getX());
	this->vmax[1] = fmax(this->vmax[1], vectorPoint.getY());
	this->vmax[2] = fmax(this->vmax[2], vectorPoint.getZ());
	this->vmin[0] = fmin(this->vmin[0], vectorPoint.getX());
	this->vmin[1] = fmin(this->vmin[1], vectorPoint.getY());
	this->vmin[2] = fmin(this->vmin[2], vectorPoint.getZ());
}

Triangle ModelLoader::Center(Triangle triangle) {
	vector3D modelCenter(this->vmin[0] + this->getWidth() / 2.0,
		this->vmin[1] + this->getHeight() / 2.0,
		this->vmin[2] + this->getLenght() / 2.0);
	Triangle centeredT(
		triangle.getVertex0() - modelCenter,
		triangle.getVertex1() - modelCenter,
		triangle.getVertex2() - modelCenter,
		triangle.getNormal0(),
		triangle.getNormal1(),
		triangle.getNormal2());
	return centeredT;
}

