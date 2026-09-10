#include "Sphere.h"
#include"Cuboid.h"
#include"Cilinder.h"
#include <iostream>
void Sphere::Render(){
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
	glutSolidSphere(this->GetSize(), 15, 15);//radio,slice,stack

	glPopMatrix();
	bool hitbox = false;
	if (hitbox) {
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 100; i++) {
			float theta = 2.0f * 3.1415926f * float(i) / float(100);
			float xPos = size * cosf(theta);
			float yPos = size * sinf(theta);

			glVertex2f(this->GetPosition().GetVectorX() + xPos, this->GetPosition().GetVectorY() + yPos);
		}
		glEnd();
	}
}
void Sphere::Update() {
	orientation = orientation + orientationSpeed;
	position = position + speed;
}
Sphere* Sphere::Clone() const {
	return   new Sphere(*this);
}

