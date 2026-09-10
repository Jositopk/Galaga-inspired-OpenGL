#pragma once
#include "Solid.h"
#include <string>
using namespace std;
class Text:public Solid
{
private:
	string text;
	void* font;
public:
	Text(const string& t) :text(t), font(GLUT_BITMAP_TIMES_ROMAN_10) { tag = "Text"; }//si solo añadimos texto la fuente por defecto sera esta
	Text(void* f) :font(f) { tag = "Text"; }
	Text(const string& t, void* f) :text(t), font(f) { tag = "Text"; }
	Text() :text("texto por defecto"),font(GLUT_BITMAP_TIMES_ROMAN_10){ tag = "Text"; }
	inline void SetText(const string& t) { text = t; }
	void Render() {

		glPushMatrix();
		//Posicion
		glTranslatef(this->position.GetVectorX(), this->position.GetVectorY(), this->position.GetVectorZ());
		//Color
		glColor3f(this->color.GetColorR(), this->color.GetColorG(), this->color.GetColorB());
		glRasterPos3d(0, 0, 0);
		for (char c : text)
			glutBitmapCharacter(font, c);
		glPopMatrix();
	}
	
};

