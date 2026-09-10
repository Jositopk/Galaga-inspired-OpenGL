#pragma once
#include "SpaceShip.h"
#include "math.h"
class Enemy:public SpaceShip
{
public:
	Enemy(string modelToLoad, SolidPtr& s) : SpaceShip(modelToLoad, s) {
		tag = "Enemy"; this->SetOrientation(Vector3D(-90, 180, 0)); this->PaintColor(Color(1, 0, 0)); health = 1;
	}

	bool CheckCollision(Solid* other) {

		bool colision = SpaceShip::CheckCollision(other);
		milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long UPDATE_PERIOD = 500;//cada   segundo
		if(other->CompareTag("Enemy") && colision){
			Vector3D checkrebound = this->GetPosition() - other->GetPosition();
			this->position.SetVectorX(checkrebound.GetVectorX() * 0.15 + position.GetVectorX());
			
		}
		else if ((currentTime.count() - this->initialMilliseconds.count()) - lastUpdatedTime > UPDATE_PERIOD && colision) {
			this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
			--health;
			
			
			return colision;

		}

		return false;
	}
	inline const int GetHealth() const override {  return health; }
	 void Update(const float& TIME_INCREMENT) {

		//orientation = orientation + orientationSpeed * TIME_INCREMENT;
		 float random = rand()%100;
		 if (random > 80)
			 position.SetVectorY(position.GetVectorY() - 0.05);
		  float randomShoot = rand() % 100;
		 static bool shoot = true;
		 //Poner temporizador
		 milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		 long UPDATE_PERIOD = 4000;//cada medio  segundo
	


			 if (randomShoot < 0.0001 && shoot) {

				 if ((currentTime.count() - this->initialMilliseconds.count()) - lastUpdatedTime > UPDATE_PERIOD) {

					 this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();

				 this->Shoot(Vector3D(0, -0.25, 0));
				 //shoot = false;
			 }
		 }
	}

};

