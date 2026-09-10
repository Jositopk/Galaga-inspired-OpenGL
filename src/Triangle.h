#pragma once
#include "Vector3D.h"
#include"Color.h"
#include<GL/glut.h>
class Triangle

{
private:
	Vector3D vertex0;
	Color color0;
	Vector3D normal0;

	Vector3D vertex1;
	Color color1;
	Vector3D normal1;

	Vector3D vertex2;
	Color color2;
	Vector3D normal2;
public:
	Triangle(Vector3D pos0,

		Vector3D norm0,

		Vector3D pos1,

		Vector3D norm1,

		Vector3D pos2,

		Vector3D norm2) :vertex0(pos0),color0(1.f), normal0(norm0), vertex1(pos1), color1(0.f), normal1(norm1), vertex2(pos2), color2(0.f), normal2(norm2) {}
	//metodo para cambiar de color
	void SetColor(Color newColor) { this->color0.SetColor(newColor);
	this->color1.SetColor(newColor);
	this->color2.SetColor(newColor);
	}
	~Triangle() {}

	//Getter de vertices
	inline Vector3D GetVertex0() const { return vertex0; }
	inline Vector3D GetVertex1() const { return vertex1; }
	inline Vector3D GetVertex2() const { return vertex2; }
	//Getter de normales
	inline Vector3D GetNormal0() const { return normal0; }
	inline Vector3D GetNormal1() const { return normal1; }
	inline Vector3D GetNormal2() const { return normal2; }

	void Render() {

		glBegin(GL_TRIANGLES);
		//v�rtice 1
		glColor3f(color0.GetColorR(), color0.GetColorG(), color0.GetColorB());
		glNormal3f(normal0.GetVectorX(), normal0.GetVectorY(), normal0.GetVectorZ());
		glVertex3f(vertex0.GetVectorX(), vertex0.GetVectorY(),vertex0.GetVectorZ());
		//v�rtice 2
		glColor3f(color1.GetColorR(), color1.GetColorG(), color1.GetColorB());
		glNormal3f(normal1.GetVectorX(), normal1.GetVectorY(), normal1.GetVectorZ());
		glVertex3f(vertex1.GetVectorX(), vertex1.GetVectorY(), vertex1.GetVectorZ());
		//v�rtice 3
		glColor3f(color2.GetColorR(), color2.GetColorG(), color2.GetColorB());
		glNormal3f(normal2.GetVectorX(), normal2.GetVectorY(), normal2.GetVectorZ());
		glVertex3f(vertex2.GetVectorX(), vertex2.GetVectorY(), vertex2.GetVectorZ());
		glEnd();

	}
};

