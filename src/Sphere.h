#pragma once
#include "Solid.h"

class Sphere:public Solid
{
	int health;
public:
	Sphere(float& x, float& y, float& z) :Solid(x, y, z) { tag = "Sphere"; health = 1; }
	Sphere() { tag = "Sphere"; health = 1; }
	void Render();
	void Update();
	Sphere* Clone() const;
	inline const int GetHealth()const override { return health; }
	bool CheckCollision(Solid* other)override {

			float const rangoColision = this->size + other->GetSize();
			Vector3D diff = this->GetPosition() - other->GetPosition();


			if (diff.Magnitude() < rangoColision && other->GetTag() != "EnemyProyectile")//Hay colision
				if (other->GetPosition().GetVectorY() < this->GetPosition().GetVectorY() || other->GetPosition().GetVectorY() > this->GetPosition().GetVectorY()) {//Esta el objeto por encima o debajo
					this->SetSpeed(GetSpeed().GetVectorX() * 1.001, -GetSpeed().GetVectorY() * 1.001, GetSpeed().GetVectorZ());//incremento progresivo de velocidad por choque con otro objeto
					--health;
				}
			return diff.Magnitude() < rangoColision;

		
	}
	
};

