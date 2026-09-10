#pragma once
#include "Solid.h"
class Torus:public Solid
{

	
	public:

		Torus(float& x, float& y, float& z) :Solid(x, y, z) {}
		Torus() {}
		void Render();
		void Update();
	


};

