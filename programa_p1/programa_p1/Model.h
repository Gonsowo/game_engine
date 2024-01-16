#pragma once
#include "Solid.h"
#include <vector>
#include "Triangle.h"

using namespace std;

class Model : public Solid
{
private:
	vector<Triangle> pol;

public:
	
	Model() : Solid() {}

	inline void AddTriangle(Triangle t) { pol.push_back(t); }
	inline void Clear() {for (Triangle var : pol) { pol.pop_back(); }}
	void PaintColor(Color color);

	void Render();

	void Update();
};

