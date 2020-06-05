#pragma once
#include <random>
#include "Location.h"
#include "Colors.h"

class Barriers {
private:
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> randX;
	std::uniform_int_distribution<int> randY;

	int numBarriers = 0;
	Location barrierArray[2500];
	Color c = { 128, 127, 226 };

public:
	Barriers(const int brdLen, const int brdHeight);

	void addBarrier(Location* snkLocs, const int snkSize, Location& goalLoc);
	void reset();

	Color getColor() const;
	int getNumBarriers() const;
	Location getLoc(int index) const;

};