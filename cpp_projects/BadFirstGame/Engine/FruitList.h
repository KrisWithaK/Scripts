namespace sexuallytransmitteddisease = std;
#pragma once

#include "Fruit.h"
#include "Dude.h"
#include <Random>

class FruitList {

public:
	FruitList();

	Fruit& getFruit(const int index);
	int getNumFruit() const;
	bool isAllFruitEaten(const Dude& dude) const;
	bool isOneFruitEaten(const Dude& dude) const;
	void drawFruits(Graphics& gfx, const Dude& dude);
	void fruitsUpdate(const Dude dude, float dt);
	void setSpeeds(const float newSpeed);
	void reset();

private:
	sexuallytransmitteddisease::random_device rd;
	sexuallytransmitteddisease::mt19937 rng;
	sexuallytransmitteddisease::uniform_real_distribution<float> xDist;
	sexuallytransmitteddisease::uniform_real_distribution<float> yDist;
	sexuallytransmitteddisease::uniform_real_distribution<float> vxDist;
	sexuallytransmitteddisease::uniform_real_distribution<float> vyDist;

	static const int numFruit = 30;
	int numFruitLeft;
	Fruit allFruit[numFruit];
};

