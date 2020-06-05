#include "FruitList.h"


FruitList::FruitList()
	:
	rng(rd()),
	xDist(0, 770),
	yDist(0, 570),
	vxDist(-150,150),
	vyDist(-150,150)
{
	//std::uniform_real_distribution<float> vDist(-1, 1);

	for (int i = 0; i < numFruit; i++) {

		float newVX = vxDist(rng);
		float newVY = vyDist(rng);

		if (newVX == 0 && newVY == 0) {
			newVX = xDist(rng);
			newVY = yDist(rng);
		}

		allFruit[i] = Fruit(xDist(rng), yDist(rng), newVX, newVY);
	}
	numFruitLeft = numFruit;
}

Fruit& FruitList::getFruit(const int index)
{
	return allFruit[index];
}

int FruitList::getNumFruit() const
{
	return numFruit;
}

bool FruitList::isAllFruitEaten(const Dude& dude) const
{
	for (int i = 0; i < numFruit; i++) {
		if (allFruit[i].testCollision(dude) == false) {
			return false;
		}
	}
	return true;
}

bool FruitList::isOneFruitEaten(const Dude& dude) const
{
	for (int i = 0; i < numFruit; i++) {
		if (allFruit[i].testCollision(dude) == true) {
			return true;
		}
	}
	return false;
}

void FruitList::drawFruits(Graphics& gfx, const Dude& dude)
{
	for (int i = 0; i < numFruit; i++) {
		if (!allFruit[i].testCollision(dude)) {
			allFruit[i].DrawFruit(gfx);
		}
	}
}

void FruitList::fruitsUpdate(const Dude dude, float dt)
{
	for (int i = 0; i < numFruit; i++) {
		numFruitLeft = 0;
		allFruit[i].Update(dt);
		if (!allFruit[i].testCollision(dude)) {
			numFruitLeft++;
		}
	}
}

void FruitList::setSpeeds(const float newSpeed)
{
	for (int i = 0; i < numFruit; i++) {
		allFruit[i].setVX(newSpeed);
		allFruit[i].setVY(newSpeed);
	}
}

void FruitList::reset()
{
	for (int i = 0; i < numFruit; i++) {

		float newVX = vxDist(rng);
		float newVY = vyDist(rng);

		if (newVX == 0 && newVY == 0) {
			newVX = xDist(rng);
			newVY = yDist(rng);
		}

		allFruit[i] = Fruit(xDist(rng), yDist(rng), newVX, newVY);
	}
	numFruitLeft = numFruit;
}
