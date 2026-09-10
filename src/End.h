#pragma once
#include "Scene.h"
#include "Star.h"
#include "SpaceShip.h"
#include "Player.h"
class End : public Scene
{
public:
	End(Player*& player) {
		//End
		SolidPtr solidptr;
		solidptr = player;
		this->AddGameObject(solidptr);
		Star* star3 = new Star();
		star3->SetPosition(Vector3D(0, 0, -5));

		star3->PaintColor(Color(0, 0.9, 0));
		star3->SetOrientation(0, 0, 0);
		solidptr = star3;

		this->AddGameObject(solidptr);
		Text* Congratulations = new Text("CONGRATULATIONS", GLUT_BITMAP_TIMES_ROMAN_24);
		solidptr = Congratulations;
		solidptr->SetPosition(-3.47, 6, 0);
		this->AddGameObject(solidptr);
	}
};

