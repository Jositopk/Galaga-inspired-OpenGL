#pragma once
#include "Scene.h"
#include "Star.h"
#include "SpaceShip.h"
#include "Player.h"
class MainMenu : public Scene
{
public:
	MainMenu(Player*& player) {

		//Menu principal
		SolidPtr solidptr;
		solidptr = player;
		this->AddGameObject(solidptr);
		Text* Galaga = new Text("GALAGA", GLUT_BITMAP_TIMES_ROMAN_24);
		solidptr = Galaga;
		solidptr->SetPosition(-1.5, 6, 0);
		this->AddGameObject(solidptr);

		Text* Start = new Text("Start", GLUT_BITMAP_HELVETICA_18);

		solidptr = Start;
		solidptr->SetPosition(-0.2, 0, 10);

		this->AddGameObject(solidptr);
		Star* star = new Star();
		star->SetPosition(Vector3D(0, 0, 0));
		star->PaintColor(Color(0, 0.9, 0));
		star->SetOrientation(0, 0, 0);
		star->SetHealth(1);

		solidptr = star;

		this->AddGameObject(solidptr);
	}
};

