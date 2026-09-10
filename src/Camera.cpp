#include "Camera.h"
void Camera:: Render() {


	
	//Posicion
	glTranslatef(-1*this->position.GetVectorX(),-1* this->position.GetVectorY(), -1*this->position.GetVectorZ());
	
	//Orientacion
	glRotatef(orientation.GetVectorX(), 1.0, 0.0, 0.0);
	glRotatef(orientation.GetVectorY(), 0.0, 1.0, 0.0);
	glRotatef(orientation.GetVectorZ(), 0.0, 0.0, 1.0);
	
	
}

void Camera::Update() {

}