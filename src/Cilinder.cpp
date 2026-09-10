#include "Cilinder.h"
#include <GL/glut.h>
void Cilinder::Render() {
	GLUquadricObj* quadricTemp = gluNewQuadric();
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
	//glutSolidCylinder(this->radius,this->height,20.f,20.f);
	glTranslatef(0., 0., -height/2);
	gluCylinder(quadricTemp, radius, radius, height, 20, 20);
	glPopMatrix();
	gluDeleteQuadric(quadricTemp);
}
void Cilinder::Update(const float& TIME_INCREMENT) {
	
	orientation = orientation + orientationSpeed*TIME_INCREMENT;
	position = position + speed*TIME_INCREMENT;
	speed = speed -  speed*0.1;
}