#pragma once
#include <cmath>
#include "SpaceShip.h"
#include "PlayerText.h"
//#include "PlayerText.h" hereda de text sera el texto que pondra por pantalla todas las caracteristicas de player
class Player:public SpaceShip
{
private:
	PlayerText playerText;

public:
	Player(string modelToLoad, SolidPtr& s) :SpaceShip(modelToLoad, s) {
		health = 3;
		playerText.SetHealth(health);
		 tag = "Player"; this->SetOrientation(Vector3D(90, 180, 0)); this->PaintColor(Color(0, 0, 1));
	}
//	Player() :SpaceShip() {}
	

	void Movement(unsigned char key) {
		static float speedMov = .2f;
		switch (key)
		{
		case'A':
		case 'a'://mov izquierda
			this->SetSpeed(-speedMov, this->GetSpeed().GetVectorY(), 0.f);
			//this->SetOrientationSpeed(this->GetOrientationSpeed().GetVectorX() ,-speedMov,  0);
			this->SetOrientationSpeed(this->GetOrientationSpeed().GetVectorX(), this->GetOrientationSpeed().GetVectorY(), -speedMov*20);
			break;
		case 'D':
		case 'd'://mov derecha
			this->SetSpeed(speedMov, this->GetSpeed().GetVectorY(), 0.f);
			//this->SetOrientationSpeed(this->GetOrientationSpeed().GetVectorX(),speedMov,  0);
			this->SetOrientationSpeed(this->GetOrientationSpeed().GetVectorX(), this->GetOrientationSpeed().GetVectorY(), speedMov*20);
			break;
		case'W':
		case'w':
			this->SetSpeed(this->GetSpeed().GetVectorX(), speedMov, 0.f);
			this->SetOrientationSpeed(-speedMov * 20,this->GetOrientationSpeed().GetVectorY(), this->GetOrientationSpeed().GetVectorZ());
			
			break;

		case'S':
		case's':
			this->SetSpeed(this->GetSpeed().GetVectorX(), -speedMov, 0.f);
			this->SetOrientationSpeed(speedMov * 20, this->GetOrientationSpeed().GetVectorY(), this->GetOrientationSpeed().GetVectorZ());
			
			break;
		case' ':
			this->playerShooting(0);
			
			break;

		}
		
	}
	void playerShooting(int button) {
		milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long UPDATE_PERIOD = 500;//cada medio  segundo
		if ((currentTime.count() - this->initialMilliseconds.count()) - lastUpdatedTime > UPDATE_PERIOD) {
			
			this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();

			
			if (button == 0) {
				
				//Vector3D pointAt(difx, dify, 0);
				Vector3D pointAt(0, 1, 0);
				//Poner temporizador 
				this->Shoot(pointAt.Normalize());


			}
		}

	}
	inline const int GetHealth() const override {  return health; }

	void Update(const float& TIME_INCREMENT)override {
		orientation = orientation + orientationSpeed * TIME_INCREMENT;
		if (orientation.GetVectorZ() > 20) {
			orientation.SetVectorZ(20)  ;
		}
		else if (orientation.GetVectorZ() < -20) {
			orientation.SetVectorZ(-20) ;
		}
		else if (orientation.GetVectorX() > 120) {
			orientation.SetVectorX(120);
		}
		else if (orientation.GetVectorX() < 60) {
			orientation.SetVectorX(60);
		}
		position = position + speed * TIME_INCREMENT;
		this->SetSpeed(this->GetSpeed().GetVectorX() - this->GetSpeed().GetVectorX() * 0.025, this->GetSpeed().GetVectorY() - this->GetSpeed().GetVectorY() * 0.08, 0);
		this->SetOrientationSpeed(this->GetOrientationSpeed().GetVectorX()-this->GetOrientationSpeed().GetVectorX() * 0.8, this->GetOrientationSpeed().GetVectorY() - this->GetOrientationSpeed().GetVectorY() * 0.8, this->GetOrientationSpeed().GetVectorZ() - this->GetOrientationSpeed().GetVectorZ() * 0.9);
		playerText.SetHealth(health);
		playerText.Update(0);
	}
bool CheckCollision(Solid* other) override {

	bool colision=SpaceShip::CheckCollision(other);
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	long UPDATE_PERIOD = 1000;//cada   segundo
	
	if ((currentTime.count() - this->initialMilliseconds.count()) - lastUpdatedTime > UPDATE_PERIOD && colision) {
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();
		--health;
	
		return colision;

	}

	return false;

	}
void SetActiveScene(SolidPtr scene) { activeScene = scene; }
	void  Render() {
		Model::Render();
		playerText.Render();

	}
};

