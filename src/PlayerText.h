#pragma once
#include "Text.h"


#include <sstream>

class PlayerText :public Text
{
	
private:

	int health;

public:
	PlayerText(const int& h):Text("Salud x3", GLUT_BITMAP_9_BY_15) { health=h; //this->SetPosition(-4.1, 3.1, 10); 
	this->SetPosition(0.f,0.f,0.f);
	}
	PlayerText() :Text("Salud x3", GLUT_BITMAP_9_BY_15) { health = 3; this->SetPosition(-4.1, 3.1, 10);
	}
	

	void SetHealth(const int& h) {
		health = h;
	}

	//En el Update mira la salud del jugador, si cambia, el valor se actualiza
	void Update(const float& TIME_INCREMENT) override {
		std::ostringstream stream;
		stream << "Salud x:" << health;
		SetText(stream.str());



	}
	//El metodo Render es exactamente el mismo
	
};