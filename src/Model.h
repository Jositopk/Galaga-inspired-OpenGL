#pragma once
#include "Solid.h"
#include "Triangle.h"
#include <vector>
using namespace std;
typedef Triangle* TrianglePtr;
class Model :public Solid
{
protected:
	vector<Triangle> triangleList;

public:
	Model() {}
	void AddTriangle(Triangle triangle) {

		triangleList.push_back(triangle);
	}
	
	void	PaintColor(Color newColor) {
		for (Triangle &t : triangleList) {
			t.SetColor(newColor);
	}
	}
	void Clear() {
		for (Triangle t : triangleList) {
			delete(&t);
		}
	}
	
	vector<Triangle> GetTrianglesList() { return triangleList; }
		void Render() {
		glPushMatrix();
		
		glTranslatef(position.GetVectorX(), position.GetVectorY(), position.GetVectorZ());
			glColor3f(color.GetColorR(), color.GetColorG(),color.GetColorB());
			glRotatef(orientation.GetVectorX(), 1.0, 0.0, 0.0);
			glRotatef(orientation.GetVectorY(), 0.0, 1.0, 0.0);
			glRotatef(orientation.GetVectorZ(), 0.0, 0.0, 1.0);
			for (Triangle t : triangleList) {
			//Por cada(Triangulo t en tri�ngulos) 
			t.Render();
		}
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
};

