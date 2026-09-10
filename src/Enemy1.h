#pragma once
#include "Enemy.h"
class Enemy1 : public Enemy
{
public:
	Enemy1(Solid*& s) : Enemy("assets/models/spaceship.obj", s) {
		health = 1;
	}
	inline const int GetHealth() const override {
		return health;
	}
	void Update(const float& TIME_INCREMENT) {
		float random = rand() % 100;
		float random2 = rand() % 100;
		if (random2 > 95) {

			SetSpeed(this->GetSpeed().GetVectorX() - 1000, this->GetSpeed().GetVectorY(), this->GetSpeed().GetVectorZ());
			position.SetVectorX(position.GetVectorX() - 0.15);
		}
		if (random2 < 5) {
			SetSpeed(this->GetSpeed().GetVectorX() + 1000, this->GetSpeed().GetVectorY(), this->GetSpeed().GetVectorZ());
			position.SetVectorX(position.GetVectorX() + 0.15);
		}
		if (random > 80)
			position.SetVectorY(position.GetVectorY() - 0.10);
	}
	
};