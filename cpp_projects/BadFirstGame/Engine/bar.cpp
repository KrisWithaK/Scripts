#include "bar.h"



void Bar::update()
{
	count++;
}

void Bar::draw(Graphics& gfx)
{
	for (int i = x; i < unitSize * count + x; i++) {
		for (int j = y; j < unitSize + y; j++) {
			gfx.PutPixel(i, j, c);
		}
	}
}

void Bar::reset()
{
	count = 0;
}
