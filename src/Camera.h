#pragma once
#include "Solid.h"
class Camera:public Solid
{
public:
	Camera() :Solid(0.f, 0.f, 16.f) {}
	Camera(const float& x, const float& y,const float& z) :Solid(x, y, z) {}
	Camera(Vector3D pos) :Solid(pos) {}
	void Render();
	void Update();
};

