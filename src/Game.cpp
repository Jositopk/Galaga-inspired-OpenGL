#include "Game.h"
#include <iostream>

void Game ::ProcessKeyPressed(unsigned char key, int px, int py) {
	//std::cout << "Tecla pulsada : " << key << std::endl;
	
	//display.displayNumber(key);

	player->Movement(key);

	
}
void Game ::ProcessMouseMovement(int x, int y) {
	//std::cout << "Movimiento del mouse" << x << ", "<<y<<std::endl;
	/*
	SolidPtr solidptr = player->playerShooting(0, x, y);

	if (solidptr != nullptr)
		this->activeScene->AddGameObject(solidptr);*/

}
void Game ::ProcessMouseClick(int button, int state, int x, int y) {
	//std::cout << "Click:" << button << std::endl;

	player->playerShooting(button);

	
	
}
void Game ::Init(){
	

	Solid* solidptr;
	Sphere* sphereptr;
	ModelLoader* loader = new ModelLoader();
	
	solidptr = activeScene;

	//MI player
	player = new Player("assets/models/spaceship4.obj", solidptr);
	solidptr = player;
	solidptr->SetPosition(0, -6, 0);
	

	MainMenu* mainMenu = new MainMenu(player);
	activeScene = mainMenu;
	player->SetActiveScene(activeScene);

	Level* lvl1 = new Level(player,1);
	Level* lvl2 = new Level(player, 2);
	Level* lvl3 = new Level(player, 3);
	Level* lvl4 = new Level(player, 4);

	End* end = new End(player);

	GameOver* gameOver = new GameOver();
	
	//activar la escena
	this->scenes.push_back(mainMenu);
	
	this->scenes.push_back(lvl1);
	this->scenes.push_back(lvl2);
	this->scenes.push_back(lvl3);
	this->scenes.push_back(lvl4);
	this->scenes.push_back(end);
	this->scenes.push_back(gameOver);
	activeScene = mainMenu;
	
	}
void Game::Render() {
	this->activeScene->Render();
	//scene.Render();
	/*this->GetSphere().Render();
	
	this->GetDisplay().Render();
	this->GetCube().Render();
	
	this->GetCuboid().Render();
	this->GetTeapot().Render();*/

}
void Game ::Update(){
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	static int i = 1;

	if ((currentTime.count()-this->initialMilliseconds.count())-lastUpdatedTime>UPDATE_PERIOD) {
		activeScene->Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();

	}
	string NombreDeArchivo = "NivelesSuperados.txt";
	ofstream Archivo(NombreDeArchivo);

	if (activeScene->GetNumberEnemies()<=0) {
		//this->activeScene++;
		
		
		if(i < scenes.size()-1){//GameOver es la ultima escena
			cout << "Cambio de escena" << endl;
			
			activeScene = scenes[i];
			SolidPtr solidptr=activeScene;
			player->SetActiveScene(solidptr);
			player->SetHealth(3);
			
		}
		else {
			i = scenes.size();
			if (Archivo.is_open()) {
				Archivo << "Niveles Superados: " << i - 2 << endl;
			}
		}
		i++;
			
	}
	if (player->GetHealth() <= 0)//Si el jugador muere la escena activa es game Over
		activeScene = scenes[scenes.size()-1];
	if (Archivo.is_open()) {
		Archivo << "Niveles Superados: " << i - 2 << endl;
	}
}