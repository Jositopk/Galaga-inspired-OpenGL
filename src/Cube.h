#pragma once
#include"Solid.h"
class Cube : public Solid
{
public:
	Cube(float& x, float& y,float& z) :Solid(x, y,z) {}
	Cube() {}
	void Render();
	
};

