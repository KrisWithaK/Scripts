#include "square.h"


void Square::ClampXY(const MainWindow& wnd)
{
	if (x0 < 0) {
		x0 = 0;
		x1 = x1 + 1;
	}
	if (y0 < 0) {
		y0 = 0;
		y1 = y1 + 1;
	}
//	if (w < 1) {
//		w = 1;
//	}
//	if (h < 1) {
//		h = 1;
//	}
	if (x1 > Graphics::ScreenWidth) {
//		if (wnd.kbd.KeyIsPressed('D')) {
//			w = w - 1;
//		}
		x1 = Graphics::ScreenWidth;
		x0 = x0 - 1;
	}
	if (y1 > Graphics::ScreenHeight) {
//		if (wnd.kbd.KeyIsPressed('S')) {
//			h = h - 1;
//		}
		y1 = Graphics::ScreenHeight;
		y0 = y0 - 1;
	}
}

void Square::Update(const MainWindow& wnd)
{
	if (wnd.kbd.KeyIsPressed( VK_UP )) {
		y0--;
		y1--;
	}

	if (wnd.kbd.KeyIsPressed( VK_LEFT )) {
		x0--;
		x1--;
	}

	if (wnd.kbd.KeyIsPressed( VK_DOWN )) {
		y0++;
		y1++;
	}

	if (wnd.kbd.KeyIsPressed( VK_RIGHT )) {
		x0++;
		x1++;
	}

	if (wnd.kbd.KeyIsPressed('W')) {
		y0--;
	}

	if (wnd.kbd.KeyIsPressed('A')) {
		x0--;
	}

	if (wnd.kbd.KeyIsPressed('S')) {
		y0++;
	}

	if (wnd.kbd.KeyIsPressed('D')) {
		x0++;
	}

	if (wnd.mouse.LeftIsPressed()) {
		y1 = wnd.mouse.GetPosY();
	}

	if (wnd.mouse.LeftIsPressed()) {
		x1 = wnd.mouse.GetPosX();
	}

	ClampXY(wnd);
}

void Square::setX0(int xCoord)
{
	x0 = xCoord;
}

void Square::setY0(int yCoord)
{
	y0 = yCoord;
}

void Square::setX1(int xCoord)
{
	x1 = xCoord;
}

void Square::setY1(int yCoord)
{
	y1 = yCoord;
}

int Square::getX0() const {
	return x0;
}
int Square::getY0() const {
	return y0;
}
int Square::getX1() const {
	return x1;
}
int Square::getY1() const {
	return y1;
}



