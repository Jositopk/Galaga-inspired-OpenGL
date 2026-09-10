#pragma once
#include"GL/glut.h"
#include "Vector3D.h"
#include "Color.h"
#include "Cuboid.h"

class Display
{
private:
	Vector3D position;

	float size;
public:

	Cuboid cuboidA, cuboidB, cuboidC, cuboidD, cuboidE, cuboidF, cuboidG;

	//construcctor vacio
	Display() : position(0.0f,0.0f,-2.0f), size(1){
		//Fijamos coordenadas para cuboid A
		cuboidA.SetPosition(0.0f, 1.0f, -2.0f);
		//Fijamos color
		cuboidA.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidA.SetSize(0.5f);
		//fijaAmos su rotacion
		cuboidA.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidA.SetScale(1.5f, 0.25f, 0.25f);
		

		//Fijamos coordenadas para cuboid B
		cuboidB.SetPosition(0.50f, 0.50f, -2.0f);
		//Fijamos color
		cuboidB.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidB.SetSize(0.5f);
		//fijaAmos su rotacion
		cuboidB.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidB.SetScale(0.25f, 1.5f, 0.25f);
		//fijamos el angulo de giro
		
		//Fijamos coordenadas para cuboid C
		cuboidC.SetPosition(0.50f, -0.50f, -2.0f);
		//Fijamos color
		cuboidC.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidC.SetSize(0.5f);
		//fijaAmos su rotacion
		cuboidC.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidC.SetScale(0.25f, 1.5f, 0.25f);
		//fijamos el angulo de giro
		

		//Fijamos coordenadas para cuboid D
		cuboidD.SetPosition(0.0f, -1.0f, -2.0f);
		//Fijamos color
		cuboidD.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidD.SetSize(0.5f);
		//fijamos su rotacion
		cuboidD.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidD.SetScale(1.5f, 0.25f, 0.25f);
		//fijamos el angulo de giro
		

		//Fijamos coordenadas para cuboid E
		cuboidE.SetPosition(-0.50f, -0.50f, -2.0f);
		//Fijamos color
		cuboidE.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidE.SetSize(0.5f);
		//fijaAmos su rotacion
		cuboidE.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidE.SetScale(0.25f, 1.5f, 0.25f);
		//fijamos el angulo de giro
		

		//Fijamos coordenadas para cuboid F
		cuboidF.SetPosition(-0.50f, 0.50f, -2.0f);
		//Fijamos color
		cuboidF.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidF.SetSize(0.5f);
		//fijaAmos su rotacion
		cuboidF.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidF.SetScale(0.25f, 1.5f, 0.25f);
		//fijamos el angulo de giro
		

		//Fijamos coordenadas para cuboid G
		cuboidG.SetPosition(0.0f, 0.0f, -2.0f);
		//Fijamos color
		cuboidG.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidG.SetSize(0.5f);
		//fijamos su rotacion
		cuboidG.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidG.SetScale(1.5f, 0.25f, 0.25f);
		//fijamos el angulo de giro
		
	}
	//constructor de coordenadas
	Display(float& x, float& y, float& z) : position(x, y, z), size(1) {
		//Fijamos coordenadas para cuboid A
		cuboidA.SetPosition(0.0f, 1.0f, -2.0f);
		//Fijamos color
		cuboidA.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidA.SetSize(0.5f);
		//fijaAmos su rotacion
		cuboidA.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidA.SetScale(1.5f, 0.25f, 0.25f);
		

		//Fijamos coordenadas para cuboid B
		cuboidB.SetPosition(0.50f, 0.50f, -2.0f);
		//Fijamos color
		cuboidB.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidB.SetSize(0.5f);
		//fijaAmos su rotacion
		cuboidB.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidB.SetScale(0.25f, 1.5f, 0.25f);
		

		//Fijamos coordenadas para cuboid C
		cuboidC.SetPosition(0.50f, -0.50f, -2.0f);
		//Fijamos color
		cuboidC.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidC.SetSize(0.5f);
		//fijaAmos su rotacion
		cuboidC.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidC.SetScale(0.25f, 1.5f, 0.25f);
		

		//Fijamos coordenadas para cuboid D
		cuboidD.SetPosition(0.0f, -1.0f, -2.0f);
		//Fijamos color
		cuboidD.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidD.SetSize(0.5f);
		//fijamos su rotacion
		cuboidD.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidD.SetScale(1.5f, 0.25f, 0.25f);
		

		//Fijamos coordenadas para cuboid E
		cuboidE.SetPosition(-0.50f, -0.50f, -2.0f);
		//Fijamos color
		cuboidE.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidE.SetSize(0.5f);
		//fijaAmos su rotacion
		cuboidE.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidE.SetScale(0.25f, 1.5f, 0.25f);
	

		//Fijamos coordenadas para cuboid F
		cuboidF.SetPosition(-0.50f, 0.50f, -2.0f);
		//Fijamos color
		cuboidF.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidF.SetSize(0.5f);
		//fijaAmos su rotacion
		cuboidF.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidF.SetScale(0.25f, 1.5f, 0.25f);
		

		//Fijamos coordenadas para cuboid G
		cuboidG.SetPosition(0.0f, 0.0f, -2.0f);
		//Fijamos color
		cuboidG.SetColor(0.05f, 0.0f, 0.0f);
		//Fijamos su tamaño
		cuboidG.SetSize(0.5f);
		//fijamos su rotacion
		cuboidG.SetOrientation(0.0f, 0.0f, 0.0f);
		//fijamos su escalado
		cuboidG.SetScale(1.5f, 0.25f, 0.25f);
		
	}

	//Ver coordenadas
	inline Vector3D GetCoordinates() { return Vector3D(position.GetVectorX(), position.GetVectorY(), position.GetVectorZ()); }
	inline float GetCoordinateX() const { return this->position.GetVectorX(); }
	inline float GetCoordinateY() const { return this->position.GetVectorY(); }
	inline float GetCoordinateZ() const { return this->position.GetVectorZ(); }

	//Ver tamaño
	inline float GetSize() const { return this->size; }

	//cambiar coordenadas
	inline void SetVector(const float& x, const float& y, const float& z) { this->position.SetVector(x, y, z); }//El vector entero
	inline void SetCoordinateX(const float& coordinateXToSet) { this->position.SetVectorX(coordinateXToSet); }
	inline void SetCoordinateY(const float& coordinateYToSet) { this->position.SetVectorY(coordinateYToSet); }
	inline void SetCoordinateZ(const float& coordinateZToSet) { this->position.SetVectorZ(coordinateZToSet); }



	//cambiar tamaño
	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }
	//Funcion que hace que la clase display enseñe los numeros segun la tecla pulsada
	void displayNumber(unsigned char key);
	void Render();
};

