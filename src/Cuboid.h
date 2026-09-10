#pragma once
#include"Solid.h"


class Cuboid:public Solid
{
public:

	//La escala es un atributo unico de la clase Cuboid
	Vector3D scale;

	
public:
	// Constructor vacio
	Cuboid() : scale(3.5f, 1.5f, 2.f) {}
	//Constructor que fija las coordenadas
	Cuboid(float& x, float& y, float& z) :Solid(x, y, z),scale(1.0f, 2.0f, 1.0f) {}
	
	//Ver escalado
	inline const Vector3D GetScale() { return Vector3D(scale.GetVectorX(), scale.GetVectorY(), scale.GetVectorZ()); }
	//Cambiar escalado
	void SetScale(const float& x, const float& y, const float& z) { scale.SetVector(x, y, z); }

	Cuboid* Clone() const;
	void Render();
	void Update();
	bool CheckCollision (Solid* other);
	
};

