#pragma once
#include"Solid.h"

class Teapot:public Solid
{
public:
	Teapot(float& x,float& y,float& z):Solid(x, y, z) {}
	Teapot() {}
	void Render();
	void Update();
};

