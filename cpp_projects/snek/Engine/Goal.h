#pragma once
#include "Location.h"
#include "Colors.h"
#include <random>

class Goal {
private:
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> randX;
	std::uniform_int_distribution<int> randY;

	Location loc;
	Color c = { 0, 0, 255 };
	bool isEaten = false;

	bool brighter = 1;
	int flashSpeed = 4;
	Color cFlash = Color(255, 255, 255);
	Color cDark;

public:
	Goal(const int brdLen, const int brdHeight);

	void randomizeLoc(Location* snkLoc, const int snkSize, Location* barrLoc, const int numBarrs);
	void colorPulse();

	Location getLoc() const;
	Color getColor() const;
	bool getIsEaten() const;
	void setIsEaten(const bool newIsEaten);


};