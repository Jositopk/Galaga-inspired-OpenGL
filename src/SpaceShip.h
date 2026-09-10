#pragma once
#include "Model.h"
#include "ModelLoader.h"
#include "Sphere.h"
#include "Cilinder.h"

#include<chrono>
using namespace std::chrono;
typedef Solid* SolidPtr;
//Clase Nave espacial que heredara la clase player y la clase enemy
//Esta clase implementa nueva funcionalidad como la capacidad de disparar proyectiles
class SpaceShip:public Model
{
protected:
	ModelLoader loader;
	SolidPtr activeScene;
	int health;//puntos de vida

	//Variables de tiempo para el retardo de los disparos
	milliseconds initialMilliseconds;
	long lastUpdatedTime;
public:
	SpaceShip(string modelToLoad, float scale) :activeScene(nullptr), health(3), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0) {
		loader.SetScale(scale);
		loader.LoadModel(modelToLoad);
		triangleList = loader.GetModel().GetTrianglesList();
		loader.Clear();


		this->SetPosition(Vector3D(0, 0, 0));

		this->SetOrientation(Vector3D(90, 180, 0));

		//player->SetOrientationSpeed(Vector3D(0, 0.1, 0));

		//star->SetSpeed(Vector3D(0.01, 0.02, 0.03));

	}
	SpaceShip(string modelToLoad,SolidPtr& s):activeScene(s),health(3), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0) {
		loader.SetScale(.5f);
		loader.LoadModel(modelToLoad);
		triangleList = loader.GetModel().GetTrianglesList();
		loader.Clear();


		this->SetPosition(Vector3D(0, 0, 0));

		this->SetOrientation(Vector3D(90, 180, 0));

		//player->SetOrientationSpeed(Vector3D(0, 0.1, 0));

		//star->SetSpeed(Vector3D(0.01, 0.02, 0.03));

		this->PaintColor(Color(0, 0, 1));
	
	}
	SpaceShip(string modelToLoad,float scale, SolidPtr& s) :activeScene(s), health(3), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0) {
		loader.SetScale(scale);
		loader.LoadModel(modelToLoad);
		triangleList = loader.GetModel().GetTrianglesList();
		loader.Clear();


		this->SetPosition(Vector3D(0, 0, 0));

		this->SetOrientation(Vector3D(90, 180, 0));

		//player->SetOrientationSpeed(Vector3D(0, 0.1, 0));

		//star->SetSpeed(Vector3D(0.01, 0.02, 0.03));

		this->PaintColor(Color(0, 0, 1));

	}
	

	/*SpaceShip() :activeScene(new Scene()), health(1) {
		loader.SetScale(1.f);
		loader.LoadModel("assets/models/spaceship4.obj");
		triangleList = loader.GetModel().GetTrianglesList();
		loader.Clear();


		this->SetPosition(Vector3D(0, 0, 0));

		

		//player->SetOrientationSpeed(Vector3D(0, 0.1, 0));

		//star->SetSpeed(Vector3D(0.01, 0.02, 0.03));

		
	*/


	void Shoot(Vector3D pointAt) {

		Sphere* proyectil = new Sphere();
		proyectil->SetSize(0.1);
		proyectil->SetColor(1, 0, 0);
		proyectil->SetOrientation(0, 0, 0);
		
		if (pointAt.GetVectorY() > 0) {
			proyectil->SetTag("PlayerProyectile");
			proyectil->SetColor(0, 1, 1);
			static bool change = true;
			if (change) {
				proyectil->SetPosition(this->GetPosition() + Vector3D(1.5, .5, 0));
				change = !change;
			}
			else {
				proyectil->SetPosition(this->GetPosition() - Vector3D(1.5, -.5, 0));
				change = !change;
			}
		}
		else {
			proyectil->SetTag("EnemyProyectile");
			proyectil->SetSize(.70);
			proyectil->SetColor(1, 1, 0);
			proyectil->SetPosition(this->GetPosition() - Vector3D(0, .5, 0));
		}



		
	
		proyectil->SetSpeed(pointAt);

		Solid* solidptr = proyectil;
		//proyectil->SetSpeed(proyectil->GetSpeed().Normalize());
		//proyectil->SetSpeed(GetSpeed() * 0.5);
		activeScene->AddGameObject(solidptr);

	}
	void ShootBeam(Vector3D pointAt) {
		Sphere* laser1 = new Sphere();
		Sphere* laser2 = new Sphere();
		Sphere* laser3 = new Sphere();
		Sphere* laser4 = new Sphere();
		Sphere* laser5 = new Sphere();
		Sphere* laser6 = new Sphere();
		Sphere* laser7 = new Sphere();
		Sphere* laser8 = new Sphere();
		
		laser1->SetColor(1, 0, 1);
		laser1->SetSize(.50);
		laser1->SetOrientation(90, 0, 0);
		laser1->SetTag("EnemyProyectile");
		laser1->SetPosition(this->GetPosition() - Vector3D(0, 0.5, 0));

		laser1->SetSpeed(pointAt);

		laser2->SetColor(1, 0, 1);
		laser2->SetSize(.50);
		laser2->SetOrientation(90, 0, 0);
		laser2->SetTag("EnemyProyectile");
		laser2->SetPosition(this->GetPosition() - Vector3D(0, 1, 0));

		laser2->SetSpeed(pointAt);

		laser3->SetColor(1, 0, 1);
		laser3->SetSize(.50);
		laser3->SetOrientation(90, 0, 0);
		laser3->SetTag("EnemyProyectile");
		laser3->SetPosition(this->GetPosition() - Vector3D(0, 1.5, 0));

		laser3->SetSpeed(pointAt);

		laser4->SetColor(1, 0, 1);
		laser4->SetSize(.50);
		laser4->SetOrientation(90, 0, 0);
		laser4->SetTag("EnemyProyectile");
		laser4->SetPosition(this->GetPosition() - Vector3D(0, 2, 0));

		laser4->SetSpeed(pointAt);

		laser5->SetColor(1, 0, 1);
		laser5->SetSize(.50);
		laser5->SetOrientation(90, 0, 0);
		laser5->SetTag("EnemyProyectile");
		laser5->SetPosition(this->GetPosition() - Vector3D(0, 2.5, 0));

		laser5->SetSpeed(pointAt);

		laser6->SetColor(1, 0, 1);
		laser6->SetSize(.50);
		laser6->SetOrientation(90, 0, 0);
		laser6->SetTag("EnemyProyectile");
		laser6->SetPosition(this->GetPosition() - Vector3D(0, 3, 0));

		laser6->SetSpeed(pointAt);

		laser7->SetColor(1, 0, 1);
		laser7->SetSize(.50);
		laser7->SetOrientation(90, 0, 0);
		laser7->SetTag("EnemyProyectile");
		laser7->SetPosition(this->GetPosition() - Vector3D(0, 3.5, 0));

		laser7->SetSpeed(pointAt);

		laser8->SetColor(1, 0, 1);
		laser8->SetSize(.50);
		laser8->SetOrientation(90, 0, 0);
		laser8->SetTag("EnemyProyectile");
		laser8->SetPosition(this->GetPosition() - Vector3D(0, 4, 0));

		laser8->SetSpeed(pointAt);

		Solid* solidptr = laser1;
		activeScene->AddGameObject(solidptr);
		solidptr = laser2;
		activeScene->AddGameObject(solidptr);
		solidptr = laser3;
		activeScene->AddGameObject(solidptr);
		solidptr = laser4;
		activeScene->AddGameObject(solidptr);
		solidptr = laser5;
		activeScene->AddGameObject(solidptr);
		solidptr = laser6;
		activeScene->AddGameObject(solidptr);
		solidptr = laser7;
		activeScene->AddGameObject(solidptr);
		solidptr = laser8;
		activeScene->AddGameObject(solidptr);

	}
	inline const int GetHealth() const override {// cout << "fuuuck";
		return health; }
	void SetHealth(int h) { health = h; }

	bool CheckCollision(Solid* other)override {
		float const rangoColision = this->GetSize() + other->GetSize();
		Vector3D diff = this->GetPosition() - other->GetPosition();


		if (diff.Magnitude() < rangoColision)//Hay colision
			if (other->GetPosition().GetVectorY() < this->GetPosition().GetVectorY() || other->GetPosition().GetVectorY() > this->GetPosition().GetVectorY()) {//Esta el objeto por encima o debajo
				this->SetSpeed(GetSpeed().GetVectorX() * 1.001, -GetSpeed().GetVectorY() * 1.001, GetSpeed().GetVectorZ());//incremento progresivo de velocidad por choque con otro objeto
				

			}
		return diff.Magnitude() < rangoColision;

	}
	//El render es exactamente el mismo que el de la clase Model
	

};

