#pragma once
#include "math.h"
#include "Scene.h"
#include "SpaceShip.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Boss.h"



class Level : public Scene
{
public:
	//Constructor de niveles
	Level(Player*& player, int nlevel) {
		SolidPtr solidptr;
		Enemy* enemigo;
		Enemy* enemigo2;
		Enemy* enemigo3;
		Enemy* enemigo4;
		Enemy* enemigo5;
		Enemy* enemigo6;
		Enemy* enemigo7;
		Enemy* enemigo8;

		if (nlevel > 0) {
			solidptr = player;
			this->AddGameObject(solidptr);//Todos los niveles tienen su player
			srand(time(nullptr));
			switch (nlevel) {
				//Nivel 1
			case 1:
				
				//Enemigos
				solidptr = this;
				 enemigo = new Enemy3(solidptr);
				solidptr = enemigo;
				solidptr->SetPosition(0, (6+rand()) %7, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				 enemigo2 = new Enemy1(solidptr);
				solidptr = enemigo2;
				solidptr->SetPosition(-3, (6 + rand()) % 7, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				 enemigo3 = new Enemy1(solidptr);
				solidptr = enemigo3;
				solidptr->SetPosition(3, (6 + rand()) % 7, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				enemigo4 = new Enemy1(solidptr);
				solidptr = enemigo4;
				solidptr->SetPosition(-6, (6 + rand()) % 7, 0);
				this->AddGameObject(solidptr);
				//Enemigos
				solidptr = this;
				enemigo5 = new Enemy1(solidptr);
				solidptr = enemigo5;
				solidptr->SetPosition(6, (6 + rand()) % 7, 0);
				this->AddGameObject(solidptr);

				break;
			case 2:
				//Enemigos lvl2
		/////////////////////////////////////////////////////////
		//E1
				solidptr = this;
				enemigo = new Enemy2(solidptr);
				solidptr = enemigo;
				solidptr->SetPosition(0, (4 + rand()) % 5, 0);
				this->AddGameObject(solidptr);

				//E2
				solidptr = this;
				enemigo2 = new Enemy1(solidptr);
				solidptr = enemigo2;
				solidptr->SetPosition(-4, (5 + rand()) % 6, 0);
				this->AddGameObject(solidptr);

				//E3
				solidptr = this;
				enemigo3 = new Enemy1(solidptr);
				solidptr = enemigo3;
				solidptr->SetPosition(4, (5 + rand()) % 5, 0);
				this->AddGameObject(solidptr);

				//E4
				solidptr = this;
				enemigo4 = new Enemy2(solidptr);
				solidptr = enemigo4;
				solidptr->SetPosition(-8,( 6 + rand()) % 7, 0);
				this->AddGameObject(solidptr);

				//E5
				solidptr = this;
				enemigo5 = new Enemy2(solidptr);
				solidptr = enemigo5;
				solidptr->SetPosition(8, (6 + rand()) % 7, 0);
				this->AddGameObject(solidptr);
				break;
			case 3:
				//Enemigos lvl3
		/////////////////////////////////////////////////////////
				solidptr = this;
				enemigo = new Boss(solidptr);
				solidptr = enemigo;
				solidptr->SetPosition(0, (6 + rand()) % 7, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				enemigo2 = new Enemy1(solidptr);
				solidptr = enemigo2;
				solidptr->SetPosition(3, (6 + rand()) % 7, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				enemigo3 = new Enemy1(solidptr);
				solidptr = enemigo3;
				solidptr->SetPosition(-3, (6 + rand()) % 7, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				enemigo4 = new Enemy1(solidptr);
				solidptr = enemigo4;
				solidptr->SetPosition(0, (12 + rand()) % 13, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				enemigo5 = new Enemy1(solidptr);
				solidptr = enemigo5;
				solidptr->SetPosition(-3, (12 + rand()) % 13, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				enemigo6 = new Enemy1(solidptr);
				solidptr = enemigo6;
				solidptr->SetPosition(3, (12 + rand()) % 13, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				enemigo7 = new Enemy1(solidptr);
				solidptr = enemigo7;
				solidptr->SetPosition(-6, (12 + rand()) % 13, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				enemigo8 = new Enemy1(solidptr);
				solidptr = enemigo8;
				solidptr->SetPosition(6,( 12 + rand()) % 13, 0);
				this->AddGameObject(solidptr);
				break;
			case 4:
				//Enemigos lvl4
		/////////////////////////////////////////////////////////
				solidptr = this;
				enemigo = new Enemy3(solidptr);
				solidptr = enemigo;
				solidptr->SetPosition(0, (2 + rand()) % 3, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				enemigo2 = new Boss(solidptr);
				solidptr = enemigo2;
				solidptr->SetPosition(3, (6 + rand()) % 7, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				enemigo3 = new Boss(solidptr);
				solidptr = enemigo3;
				solidptr->SetPosition(-3, (6 + rand()) % 7, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				enemigo4 = new Boss(solidptr);
				solidptr = enemigo4;
				solidptr->SetPosition(6, (12 + rand()) % 13, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				enemigo5 = new Boss(solidptr);
				solidptr = enemigo5;
				solidptr->SetPosition(-6, (12 + rand()) % 13, 0);
				this->AddGameObject(solidptr);

				solidptr = this;
				enemigo6 = new Enemy3(solidptr);
				solidptr = enemigo6;
				solidptr->SetPosition(0, (12 + rand()) % 13, 0);
				this->AddGameObject(solidptr);
				break;
			case 5:
				break;
			}
		}
		else {
			cerr << "El nmero de nivel no existe";
			throw;
			
		}
	}
};

