#pragma once
#include<GL/glut.h>
#include"Vector3D.h"
#include"Color.h"
#include "ostream"

class Solid
{

protected:
	string tag;

	Vector3D position;
	Vector3D speed;

	Vector3D orientation;
	Vector3D orientationSpeed;

	Color color;

	float size;

public:
	//Constructor vacio
	Solid() :position(0.0f, 0.0f, -2.0f), color(0.2f, 0.3f, 0.3f), orientation(0.0f, 0.0f, 0.0f), size(1.f) {}
	//Constructor que fija las coordenadas
	Solid(const float& x,const float& y,const float& z) : position(x, y, z), color(0.2f, 0.3f, 0.3f), size(1.f) {}
	Solid(Vector3D pos) : position(pos.GetVectorX(), pos.GetVectorY(), pos.GetVectorZ()) {}

	//Devolver etiqueta
	const string GetTag()const { return tag; }
	inline const bool CompareTag(string t) { return tag == t; }
	inline void SetTag(const string& t) { tag = t; }
	//Ver Coordenadas

	inline Vector3D GetPosition() const { return position; }
	//Estos metodos los hace la clase Vector 3D.
	//inline float GetCoordinateX() const { return this->position.GetVectorX(); }
	//inline float GetCoordinateY() const { return this->position.GetVectorY(); }
	//inline float GetCoordinateZ() const { return this->position.GetVectorZ(); }

	//Ver Colores
	inline Color GetColor() { return color; }
	//Estos metodos los hace la clase Color.
	//inline float GetRedComponent() const { return this->color.GetColorR(); }
	//inline float GetGreenComponent() const { return this->color.GetColorG(); }
	//inline float GetBlueComponent() const { return this->color.GetColorB(); }

	//Ver orientación
	inline Vector3D GetOrientation() { return orientation; }
	inline Vector3D GetOrientationSpeed() { return orientationSpeed; }
	//Ver tamaño
	inline float GetSize() const { return this->size; }

	//Cambiar coordenadas
	inline void SetPosition(const float& x, const float& y, const float& z) { this->position.SetVector(x, y, z); }//El vector entero
	inline void SetPosition(Vector3D pos) { this->position.SetVector(pos); }
	inline void SetPositionX(const float& coordinateXToSet) { this->position.SetVectorX(coordinateXToSet); }
	inline void SetPositionY(const float& coordinateYToSet) { this->position.SetVectorY(coordinateYToSet); }
	inline void SetPositionZ(const float& coordinateZToSet) { this->position.SetVectorZ(coordinateZToSet); }
	//Cambiar velocidad
	inline void SetSpeed(const float& x, const float& y, const float& z) { this->speed.SetVector(x, y, z); }
	inline void SetSpeed(Vector3D s) { this->speed.SetVector(s); }
	inline Vector3D GetSpeed() { return this->speed; }
	//Cambiar colores
	inline void SetColor(const float& r, const float& g, const float& b) { this->color.SetColor(r, g, b); }
	inline void SetRedComponent(const float& redComponentToSet) { this->color.SetColorR(redComponentToSet); }
	inline void SetGreenComponent(const float& greenComponentToSet) { this->color.SetColorG(greenComponentToSet); }
	inline void SetBlueComponent(const float& blueComponentToSet) { this->color.SetColorB(blueComponentToSet); }

	//cambiar orientacion
	inline void SetOrientation(const float& x, const float& y, const float& z) { this->orientation.SetVector(x, y, z); }
	inline void SetOrientation(Vector3D orient) { this->orientation.SetVector(orient); }
	//cambiar orientation speed
	inline void SetOrientationSpeed(const float& x, const float& y, const float& z) { this->orientationSpeed.SetVector(x, y, z); }
	inline void SetOrientationSpeed(Vector3D orientspeed) { this->orientationSpeed.SetVector(orientspeed); }
	//cambiar tamaño
	inline void SetSize(const float& sizeToSet) { this->size = sizeToSet; }
	void Destroy() { delete this; }
	virtual inline const int GetHealth() const { //cout << "Solid" << endl;
		return 0; }
	virtual void SetHealth(int h) {}
	void Rotate(){
		static float angle = 0.0f;
		angle = angle + 0.1f;

		orientation.SetVectorX(angle + orientation.GetVectorX());
		orientation.SetVectorY(angle + orientation.GetVectorY());
	}
	virtual Solid* Clone() const ;
	virtual bool CheckCollision(Solid* other);
	virtual void AddGameObject(Solid*& solidptr) {}
	virtual void Render()=0;
	virtual void Update(const float& TIME_INCREMENT) {

		orientation = orientation + orientationSpeed*TIME_INCREMENT;
		position = position + speed*TIME_INCREMENT;
	}
	friend ostream& operator<<(ostream& o, const Solid& s) {
		o << s.GetPosition();
		return o;
	}
};

