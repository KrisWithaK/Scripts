#pragma once

#include "Graphics.h"
#include "Dude.h"

class Fruit {
private:
	float x = 0;
	float y = 0;
	float vx;
	float vy;
	static constexpr int h = 24;
	static constexpr int w = 24;
	bool Eaten = false;
public:
	Fruit(float x, float y, float vx, float vy);
	Fruit();
	void Update(float dt);
	void DrawFruit(Graphics& gfx) const;
	bool testCollision(const Dude& dude) const;

	void setX(const float newX);
	void setY(const float newY);
	void setVX(const float newVX);
	void setVY(const float newVY);

};