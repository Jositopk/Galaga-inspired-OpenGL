#include "Cube.h"

void Cube::Render() {
	glPushMatrix();
	//Posicion
	glTranslatef(this->position.GetVectorX(), this->position.GetVectorY(), this->position.GetVectorZ());
	//Color
	glColor3f(this->color.GetColorR(), this->color.GetColorG(), this->color.GetColorB());
	//Orientacion
	glRotatef(orientation.GetVectorX(), 1.0, 0.0, 0.0);
	glRotatef(orientation.GetVectorY(), 0.0, 1.0, 0.0);
	glRotatef(orientation.GetVectorZ(), 0.0, 0.0, 1.0);
	//Tamaño
	glutSolidCube(this->GetSize());
	glPopMatrix();
}


