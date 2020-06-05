#include "Goal.h"

void Goal::randomizeLoc(Location* snkLoc, const int snkSize, Location* barrLoc, const int numBarrs)
{
	bool snkBarrOverlap = true;
	while (snkBarrOverlap) {
		snkBarrOverlap = false;
		loc.x = randX(rng);
		loc.y = randY(rng);

		for (int i = 0; i < snkSize; i++) {
			if (snkLoc[i] == loc) {
				snkBarrOverlap = true;
			}
		}

		for (int i = 0; i < numBarrs; i++) {
			if (barrLoc[i] == loc) {
				snkBarrOverlap = true;
			}
		}
	}
}

void Goal::colorPulse()
{
	if (brighter) {
		if (c.GetR() < cFlash.GetR()) {
			if (c.GetR() + flashSpeed > cFlash.GetR()) {
				c = Color(cFlash.GetR(), c.GetG(), c.GetB());
			}
			else {
				c = Color(c.GetR() + flashSpeed, c.GetG(), c.GetB());
			}
		}
		if (c.GetG() < cFlash.GetG()) {
			if (c.GetG() + flashSpeed > cFlash.GetG()) {
				c = Color(c.GetR(), cFlash.GetG(), c.GetB());
			}
			else {
				c = Color(c.GetR(), c.GetG() + flashSpeed, c.GetB());
			}
		}
		if (c.GetB() < cFlash.GetB()) {
			if (c.GetB() + flashSpeed > cFlash.GetB()) {
				c = Color(c.GetR(), c.GetG(), cFlash.GetB());
			}
			else {
				c = Color(c.GetR(), c.GetG(), c.GetB() + flashSpeed);
			}

		}
		if (c.GetR() == cFlash.GetR() && c.GetG() == cFlash.GetG() && c.GetB() == cFlash.GetB()) {
			brighter = 0;
		}
	}
	else {
		if (c.GetR() > cDark.GetR()) {
			if (c.GetR() - flashSpeed < cDark.GetR()) {
				c = Color(cDark.GetR(), c.GetG(), c.GetB());
			}
			else {
				c = Color(c.GetR() - flashSpeed, c.GetG(), c.GetB());
			}
		}
		if (c.GetG() > cDark.GetG()) {
			if (c.GetG() - flashSpeed < cDark.GetG()) {
				c = Color(c.GetR(), cDark.GetG(), c.GetB());
			}
			else {
				c = Color(c.GetR(), c.GetG() - flashSpeed, c.GetB());
			}
		}
		if (c.GetB() > cDark.GetB()) {
			if (c.GetB() - flashSpeed < cDark.GetB()) {
				c = Color(c.GetR(), c.GetG(), cDark.GetB());
			}
			else {
				c = Color(c.GetR(), c.GetG(), c.GetB() - flashSpeed);
			}
		}
		if (c.GetR() == cDark.GetR() && c.GetG() == cDark.GetG() && c.GetB() == cDark.GetB()) {
			brighter = 1;
		}
	}
}

Goal::Goal(const int brdLen, const int brdHeight)
	:
	rng(rd()),
	randX(0, brdLen - 1),
	randY(0, brdHeight - 1)
{
	loc.x = randX(rng);
	loc.y = randY(rng);
	c = { 0, 0, 255 };
	cDark = c;
}

Location Goal::getLoc() const
{
	return loc;
}

Color Goal::getColor() const
{
	return c;
}

bool Goal::getIsEaten() const
{
	return isEaten;
}

void Goal::setIsEaten(const bool newIsEaten)
{
	isEaten = newIsEaten;
}
