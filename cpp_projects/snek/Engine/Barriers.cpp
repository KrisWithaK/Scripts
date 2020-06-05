#include "Barriers.h"

Barriers::Barriers(const int brdLen, const int brdHeight)
	:
	rng(rd()),
	randX(0, brdLen - 1),
	randY(0, brdHeight - 1)
{
	numBarriers = 0;
	c = { 50, 50, 50 };
	for (int i = 0; i < 2500; i++) {
		barrierArray[i] = { -1,-1 };
	}
}

void Barriers::addBarrier(Location* snkLocs, const int snkSize, Location& goalLoc)
{
	bool snkOrGoalOrBarrierOverlap = true;
	while (snkOrGoalOrBarrierOverlap) {
		snkOrGoalOrBarrierOverlap = false;
		barrierArray[numBarriers] = { randX(rng), randY(rng) };

		for (int i = 0; i < snkSize; i++) {
			if (snkLocs[i] == barrierArray[numBarriers]) {
				snkOrGoalOrBarrierOverlap = true;
				break;
			}
		}

		for (int i = 0; i < numBarriers; i++) {
			if (barrierArray[i] == barrierArray[numBarriers]) {
				snkOrGoalOrBarrierOverlap = true;
				break;
			}
		}

		if (goalLoc == barrierArray[numBarriers]) {
			snkOrGoalOrBarrierOverlap = true;
		}
	}
	numBarriers++;
}

void Barriers::reset()
{
	numBarriers = 0;
}

Color Barriers::getColor() const
{
	return c;
}

int Barriers::getNumBarriers() const
{
	return numBarriers;
}

Location Barriers::getLoc(int index) const
{
	return barrierArray[index];
}
