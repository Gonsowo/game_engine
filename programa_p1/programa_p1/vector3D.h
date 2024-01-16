#pragma once
template <class S> class vector3Dx;

typedef vector3Dx<float> vector3D;

typedef vector3Dx<float> vector3D;
typedef vector3Dx<double> vector3Dd;
typedef vector3Dx<int> vector3Di;

template <class S> class vector3Dx
{
private: 
	S x;
	S y;
	S z;

public:
	vector3Dx(S x = 0, S y = 0, S z = 0) : x(x), y(y), z(z) {};

	inline S getX() const { return this->x; }
	inline S getY() const { return this->y; }
	inline S getZ() const { return this->z; }
	vector3Dx<S> getVector() { return vector3Dx<S>(x, y, z); }

	inline void setX(S XtoSet) { this->x = XtoSet; }
	inline void setY(S YtoSet) { this->y = YtoSet; }
	inline void setZ(S ZtoSet) { this->z = ZtoSet; }

	vector3Dx<S> operator+(vector3Dx<S> v);
	vector3Dx<S> operator-(vector3Dx<S> v);
	vector3Dx<S> operator*(S s);
	vector3Dx<S> operator/(S s);
	S operator*(vector3Dx<S> v);
};

template <class S> vector3Dx<S> vector3Dx<S>::operator+(vector3Dx<S> vector) {
	return vector3Dx<S>(this->getX() + vector.getX(), this->getY() + vector.getY(), this->getZ() + vector.getZ());
}
template <class S> vector3Dx<S> vector3Dx<S>::operator-(vector3Dx<S> vector) {
	return vector3Dx<S>(this->getX() - vector.getX(), this->getY() - vector.getY(), this->getZ() - vector.getZ());
}
template <class S> vector3Dx<S> vector3Dx<S>::operator*(S s) {
	return vector3Dx<S>(this->getX() * s, this->getY() * s, this->getZ() * s);
}
template <class S> vector3Dx<S> vector3Dx<S>::operator/(S s) {
	return vector3Dx<S>(this->getX() / s, this->getY() / s, this->getZ() / s);
}

