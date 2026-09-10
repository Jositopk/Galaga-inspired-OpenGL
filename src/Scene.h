#pragma once
#include <vector>
#include "Solid.h"
#include "Camera.h"
#include "Vector3D.h"
using namespace std;
typedef Solid* SolidPtr;

class Scene :public Solid

{
	
private:

	vector<SolidPtr> gameObject;//Vector de punteros hacia los objetos en escena
	Camera camera;//Camara
	Vector3D boundary;
	int numberEnemies;
	//LevelText leveltext contador de enemigos que dara el wincondition
public:
	Scene() :camera(Vector3D(0.f,0.f,16.f)), boundary(8.f, 8.f, 4.f), numberEnemies(1) {

		gameObject.reserve(100);
		
	}

	//metodo que recibe un puntero Solid y lo almacena
	void AddGameObject(SolidPtr& solidptr) override {
		gameObject.push_back(solidptr);
		
	}
	//metodo que establece el player de un nivel

	void checkBoundary(SolidPtr i) {
		

			float checkBoundaryX;
			checkBoundaryX=i->GetPosition().GetVectorX();
			if (checkBoundaryX > boundary.GetVectorX() || checkBoundaryX < -boundary.GetVectorX()) {
				i->SetSpeed(-i->GetSpeed().GetVectorX(), i->GetSpeed().GetVectorY(), i->GetSpeed().GetVectorZ());
				
			}
			float checkBoundaryY;
			checkBoundaryY = i->GetPosition().GetVectorY();
			if (checkBoundaryY > boundary.GetVectorY() || checkBoundaryY < -boundary.GetVectorY()) {
				i->SetSpeed(i->GetSpeed().GetVectorX(), -i->GetSpeed().GetVectorY(), i->GetSpeed().GetVectorZ());
				if (i->CompareTag("PlayerProyectile") || i->CompareTag("EnemyProyectile") || i->CompareTag("Proyectile")) {
					removeGameObject(i);
				}
				if (checkBoundaryY < -boundary.GetVectorY() && i->CompareTag("Enemy")) {
					this->gameObject[0]->SetHealth(0);
				}
			}
			float checkBoundaryZ;
			checkBoundaryZ = i->GetPosition().GetVectorZ();
			if (checkBoundaryZ > boundary.GetVectorZ() || checkBoundaryZ < -boundary.GetVectorZ()) {
				i->SetSpeed(i->GetSpeed().GetVectorX(), i->GetSpeed().GetVectorY(), -i->GetSpeed().GetVectorZ());
			}
		
	}
	void CountEnemies() {
		int n = 0;
		for(SolidPtr i:gameObject){
			if (i->CompareTag("Enemy")) {
				++n;
			}
		}
		numberEnemies = n;
	}
	int GetNumberEnemies() { return numberEnemies; }

	void removeGameObject(SolidPtr posObj) {
		vector<SolidPtr>::iterator i=find(gameObject.begin(), gameObject.end(),posObj);
	  

		if (posObj->CompareTag("Enemy")) {
			--numberEnemies;
		}
	
	  if (i != gameObject.end()) {//No queremos que se borre el cilindro
		  gameObject.erase(i);//Borra el elemento en la posicion del puntero
		  
	  }
	  
	}
	void checkCollision(SolidPtr c) {
		
		//Comprobamos la colision de todos con todos
		for (SolidPtr i : gameObject) {//Comprobar la colision del player con todos los objetos
			
			if (i != c && !i->CompareTag("Text")) {//Comprobar que no hace colision consigo mismo
				if (((!c->CompareTag("Player") && i->CompareTag("PlayerProyectile")) || (i->CompareTag("Player") && !c->CompareTag("PlayerProyectile"))) 
					|| ((!c->CompareTag("Enemy") && i->CompareTag("EnemyProyectile")) || (i->CompareTag("Enemy") && !c->CompareTag("EnemyProyectile"))) || ((!c->CompareTag("EnemyProyectile") && !i->CompareTag("EnemyProyectile")) || ((!i->CompareTag("EnemyProyectile") && !c->CompareTag("EnemyProyectile"))))) {//No hay fuego amigo, no se choca una bala del player con el player
					//Tampoco entre enemigos
					
						c->CheckCollision(i);
						i->CheckCollision(c);


					
				}
			
		}
		}
	}
	void Render() {
		camera.Render();
		for (SolidPtr i : gameObject) {//Recorremos el vector de punteros y activamos la funcion Render de cada uno
			i->Render();
			
		}
		// boundary(8.f, 10.f, 4.f) 
		int offset = 4;
		glBegin(GL_LINES);
		glVertex3f(-boundary.GetVectorX()-offset, boundary.GetVectorY(), 0);//Linea Inicial Superior
		glVertex3f(boundary.GetVectorX()+offset,boundary.GetVectorY(), 0);//Linea Final
		
		glVertex3f(-boundary.GetVectorX()-offset, boundary.GetVectorY(), 0);//Linea inicial
		glVertex3f(-boundary.GetVectorX()-offset, -boundary.GetVectorY(), 0);//Linea Final Izquierda

		glVertex3f(-boundary.GetVectorX()-offset, -boundary.GetVectorY(), 0); //inferior
		glVertex3f(boundary.GetVectorX()+offset, -boundary.GetVectorY(), 0);

		glVertex3f(boundary.GetVectorX()+offset, -boundary.GetVectorY(), 0);//derecha
		glVertex3f(boundary.GetVectorX()+offset, boundary.GetVectorY(), 0);

		glEnd();
	}
	void Update(const float& TIME_INCREMENT) {
		
			for ( SolidPtr i : gameObject) {//Recorremos el vector de punteros y activamos la funcion Update de cada uno

				i->Update(TIME_INCREMENT);
				
				checkBoundary(i);
				
					checkCollision(i);
				if (i->GetHealth() <= 0&&!i->CompareTag("Text"))//Si la salud llega a  0 o es menor de  0 el gameObject desaparece
					removeGameObject(i);
			}
			
			CountEnemies();
		
		
	}

};

