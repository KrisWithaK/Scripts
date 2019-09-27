#pragma once
#include "Colors.h"
#include "Graphics.h"


class Bar {
private:

	int unitSize = 5;
	int x = 10;
	int y = 10;
	int count = 0;
	Color c = Colors::Blue;



public:
	void update();
	void draw(Graphics& gfx);
	void reset();
};

