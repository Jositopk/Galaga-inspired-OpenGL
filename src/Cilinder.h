#pragma once
#include "Solid.h"
class Cilinder:public Solid
{
private:
	float radius;
	float height;
public:
	Cilinder() :radius(1.f), height(7.f) {}
	Cilinder(const float& x, const float& y, const float& z) :Solid(x, y, z), radius(1.f), height(5.f) {}

	inline float GetHeight() { return height; }
	void SetHeight(const float& h) { height = h; }

	inline float GetRadius() { return radius; }
	void SetRadius(const float& r) { radius = r; }

	void Render();
	void Update(const float& TIME_INCREMENT);


};

