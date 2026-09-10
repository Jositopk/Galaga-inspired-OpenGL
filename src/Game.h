#pragma once
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "Display.h"
#include "Model.h"
#include "ModelLoader.h"
#include "Scene.h"
#include "MainMenu.h"
#include "Level.h"
#include "End.h"
#include "GameOver.h"
#include "Camera.h"
#include "Cilinder.h"
#include "Text.h"
#include "SpaceShip.h"
#include "Player.h"
#include "Enemy.h"
#include <string>
#include <chrono>
#include <vector>
using namespace std::chrono;
using namespace std;
typedef Scene* ScenePtr;

class Game
{
private:
	const double TIME_INCREMENT = 0.4;//ms en tiempo de juego
	const long UPDATE_PERIOD = 10;//ms en tiempo del mundo real

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

	ScenePtr activeScene;
	vector<ScenePtr> scenes;

	
	Player* player;

public:
	
	Game() :activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0) {}
	
	//Game(float x,float y,float z):cube( x,  y,  z) {}//Constructor para inicializar el cubo con unas coordenadas
		void Init();
		void Render();
		void Update();
		void ProcessKeyPressed(unsigned char key, int px, int py);
		void ProcessMouseMovement(int x, int y);
		void ProcessMouseClick(int button, int state, int x, int y);
	
};

