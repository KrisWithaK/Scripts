#include "Goal.h"





Goal::Goal()
	:
	rng(rd()),
	RandX(0, Graphics::ScreenWidth - a),
	RandY(0, Graphics::ScreenHeight - a)
{
	x = RandX(rng);
	y = RandY(rng);

	cDark = Color(c.GetR(), c.GetG(), c.GetB());
}

void Goal::drawGoal(Graphics& gfx) const
{
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			gfx.PutPixel(x + i, y + j, c);
		}
	}
}

void Goal::update(const Dude& dude, Bar& bar)
{
	if (hasCollision(dude)) {
		randomizeCoord();
		bar.update();
	}

	flash();

}

void Goal::reset()
{
	randomizeCoord();
}

bool Goal::hasCollision(const Dude& dude) const
{
	return dude.getX() > x && dude.getX() < x + a && dude.getY() > y && dude.getY() < y + a ||
		dude.getX() + dude.getW() > x && dude.getX() + dude.getW() < x + a && dude.getY() > y && dude.getY() < y + a ||
		dude.getX() > x && dude.getX() < x + a && dude.getY() + dude.getH() > y && dude.getY() + dude.getH() < y + a ||
		dude.getX() + dude.getW() > x && dude.getX() + dude.getW() < x + a && dude.getY() + dude.getH() > y && dude.getY() + dude.getH() < y + a;
}

void Goal::randomizeCoord()
{
	x = RandX(rng);
	y = RandY(rng);
}

void Goal::flash()
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
