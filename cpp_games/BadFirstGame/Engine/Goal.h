#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "Dude.h"
#include <random>
#include "bar.h"

class Goal {

private:

	int a = 25;
	int x = 30;
	int y = 30;
	Color c = Color(255, 0, 0);

	bool brighter = 1;
	int flashSpeed = 4;
	Color cFlash = Color(255, 255, 255);
	Color cDark;

	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> RandX;
	std::uniform_int_distribution<int> RandY;

	bool hasCollision(const Dude& dude) const;
	void randomizeCoord();
	void flash();

public:
	Goal();

	void drawGoal(Graphics& gfx) const;
	void update(const Dude& dude, Bar& bar);
	void reset();





};