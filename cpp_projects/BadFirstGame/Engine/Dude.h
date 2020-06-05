#pragma once

#include "MainWindow.h"
#include "Graphics.h"

class Dude {
private:
	static constexpr float startSpeed = 150.0f;

	float x;
	float y;
	float speed;
	static constexpr int w = 20;
	static constexpr int h = 20;
	
public:
	Dude(float x_in, float y_in);
	void update(const MainWindow& wnd, float dt);
	void DrawFace(Graphics& gfx) const;
	void setSpeed(const float newSpeed);
	float getX() const;
	float getY() const;
	int getW() const;
	int getH() const;
	void reset();
};