#pragma once
#include <corecrt_math.h>
#include <iostream>
#include <ostream>
using namespace std;

template <class S> class Vector3Dx;

typedef Vector3Dx<float> Vector3D;

typedef Vector3Dx<float> Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int> Vector3Di;

template <class S> class Vector3Dx
{
private:
	S X;
	S Y;
	S Z;

public:

	//Constructor por defecto
	Vector3Dx() :X(0.0), Y(0.0), Z(0.0) {}//Inicializacion de las tres coordenadas a 0
	//Constructor con argumentos
	Vector3Dx(const S& x, const S& y, const S& z) :X(x), Y(y), Z(z) {}

	//Vector3Dx(const S& p) :X(p), Y(p), Z(p) {}

	void SetVector(const S& x, const S& y, const S& z) { X = x; Y = y; Z = z; }//Cambio de las coordenadas segun los argumentos de la funcion
	void SetVector(Vector3Dx<S> newVector) {
		X = newVector.GetVectorX();
		Y = newVector.GetVectorY();
		Z = newVector.GetVectorZ();
	}
	void SetVectorX(const S& x) { this->X = x; }//Cambio de la coordenada x segun el argumento de la funcion
	void SetVectorY(const S& y) { this->Y = y; }//Cambio de la coordenada y segun el argumento de la funcion
	void SetVectorZ(const S& z) { this->Z = z; }//Cambio de la coordenada z segun el argumento de la funcion

	inline S GetVectorX() const { return X; }//Devolver coordenada x 
	inline S GetVectorY() const { return Y; }//Devolver coordenada y 
	inline S GetVectorZ() const { return Z; }//Devolver coordenada z

	//Operaciones con Vector 3D
	Vector3Dx<S> Add(const Vector3Dx<S>& b) {
		Vector3D result(X + b.GetVectorX(), Y + b.GetVectorY(), Z + b.GetVectorZ());
		return result;
	}
	Vector3Dx<S> Substract(const Vector3Dx<S>& b) {
		Vector3Dx<S> result(X - b.GetVectorX(), Y - b.GetVectorY(), Z - b.GetVectorZ());
		return result;
	}

	Vector3Dx<S> Product(const Vector3Dx<S>& b) {
		Vector3Dx<S> result(X * b.GetVectorX(), Y * b.GetVectorY(), Z * b.GetVectorZ());
		return result;
	}
	S DotProduct(const Vector3Dx<S>& b) {
		S result = X * b.GetVectorX() + Y * b.GetVectorY() + Z * b.GetVectorZ();
		return result;

	}
	Vector3Dx<S> Normalize() {
		return *this / sqrt(X * X + Y * Y + Z * Z);
	}
	S Magnitude() {
		S magnitude = sqrt(X * X + Y * Y + Z * Z);
		return magnitude;
	}
	Vector3Dx<S> operator+(const Vector3Dx<S>& vector) {
		return Add(vector);
	}
	Vector3Dx<S> operator-(const Vector3Dx<S>& vector) {
		return Substract(vector);
	}
	Vector3Dx<S> operator*(const S& value) {
		Vector3Dx<S> result(X * value, Y * value, Z * value);
		return result;
	}
	Vector3Dx<S> operator/(const S& value) {
		Vector3Dx<S> result(X / value, Y / value, Z / value);
		return result;
	}
	S operator*(const Vector3Dx<S>& vector) {
		return DotProduct(vector);
	}
	S& operator [](const int& i) {

		if (i == 0) return this->X;
		if (i == 1) return this->Y;
		if (i == 2) return this->Z;
		if (i < 0 || i>2) {
			throw out_of_range("Error,el indice est  fuera de rango");
		}
	}
	friend ostream& operator<<(ostream& o, const Vector3Dx<S>& v) {
		o << v.GetVectorX() << ", " << v.GetVectorY() << ", " << v.GetVectorZ();
		return o;
	}

};