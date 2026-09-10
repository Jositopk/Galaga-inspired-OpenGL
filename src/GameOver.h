#pragma once
#include "Scene.h"
#include "Star.h"
#include "SpaceShip.h"
#include "Player.h"
class GameOver : public Scene
{
public:
	GameOver() {
		//Game Over
		SolidPtr solidptr;
		Star* star2 = new Star();
		star2->SetPosition(Vector3D(0, 0, -5));

		star2->PaintColor(Color(0, 0.9, 0));
		star2->SetOrientation(0, 0, 0);
		solidptr = star2;

		this->AddGameObject(solidptr);
		Text* gameOver = new Text("GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24);
		solidptr = gameOver;
		solidptr->SetPosition(-2, 6, 0);
		this->AddGameObject(solidptr);
	}
};

