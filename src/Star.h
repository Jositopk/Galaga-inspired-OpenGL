#pragma once
#include "SpaceShip.h"

class Star : public SpaceShip
{
public:
	Star() :SpaceShip("assets/models/star.obj",2){
		health = 1; 
		this -> SetTag("Enemy");
	}


	bool CheckCollision(Solid* other)override {
		float const rangoColision = this->GetSize() + other->GetSize();
		Vector3D diff = this->GetPosition() - other->GetPosition();


		if (diff.Magnitude() < rangoColision)//Hay colision
			if (other->GetPosition().GetVectorY() < this->GetPosition().GetVectorY() || other->GetPosition().GetVectorY() > this->GetPosition().GetVectorY()) {//Esta el objeto por encima o debajo
				this->SetSpeed(GetSpeed().GetVectorX() * 1.001, -GetSpeed().GetVectorY() * 1.001, GetSpeed().GetVectorZ());//incremento progresivo de velocidad por choque con otro objeto
				--health;

			}
		return diff.Magnitude() < rangoColision;

	}
};

