#include "Cuboid.h"
void Cuboid::Render(){
glPushMatrix();
//Posicion
glTranslatef(this->position.GetVectorX(), this->position.GetVectorY(), this->position.GetVectorZ());
//Color
glColor3f(this->color.GetColorR(), this->color.GetColorG(), this->color.GetColorB());
//Orientacion
glRotatef(orientation.GetVectorX(), 1.0, 0.0, 0.0);
glRotatef(orientation.GetVectorY(), 0.0, 1.0, 0.0);
glRotatef(orientation.GetVectorZ(), 0.0, 0.0, 1.0);
//Proporcion cuboid
glScalef(this->scale.GetVectorX(), this->scale.GetVectorY(), this->scale.GetVectorZ());

glutSolidCube(this->GetSize());
glPopMatrix();
}
void Cuboid::Update() {
	orientation = orientation + orientationSpeed;
}
Cuboid* Cuboid::Clone() const {
	return new Cuboid(*this);
}
bool Cuboid::CheckCollision(Solid* other) {
	

	if (((this->GetPosition() - other->GetPosition()).Magnitude() < 1.5)) {
		this->SetColor(0.5,0.5,  0.5);
		delete(this);
	}
	

	return true;
}