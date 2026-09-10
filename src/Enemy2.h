#pragma once
#include "Enemy.h"
class Enemy2 : public Enemy
{
public:
	Enemy2(Solid*& s) : Enemy("assets/models/spaceship5.obj", s) {
		this->SetOrientation(90, 0, 0); //Este modelo en especifico tiene otra orientacion
		health = 1;
	}
	inline const int GetHealth() const override {
		return health;
	}
	void Update(const float& TIME_INCREMENT) {

		//orientation = orientation + orientationSpeed * TIME_INCREMENT;
		float random = rand() % 100;
		if (random > 80)
			position.SetVectorY(position.GetVectorY() ); //0.05
		float randomShoot = rand() % 100;
		static bool shoot = true;
		//Poner temporizador
		milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long UPDATE_PERIOD = 4000;//cada medio  segundo



		if (randomShoot < 0.001 && shoot) {

			if ((currentTime.count() - this->initialMilliseconds.count()) - lastUpdatedTime > UPDATE_PERIOD) {

				this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
				if (random > 60) { this->Shoot(Vector3D(0.25, -0.25, 0)); }
				if (random < 60) { this->Shoot(Vector3D(-0.25, -0.25, 0)); }
				
				//shoot = false;
			}
		}
	}
};
