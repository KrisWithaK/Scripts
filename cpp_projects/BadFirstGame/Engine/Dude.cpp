#include "Dude.h"

Dude::Dude(float x_in, float y_in)
{
	x = x_in;
	y = y_in;
	speed = startSpeed;
}

void Dude::update(const MainWindow& wnd, float dt) {


	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		x += speed * dt;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		x -= speed * dt;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		y += speed * dt;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		y -= speed * dt;
	}



	if (x + float(w) > float(Graphics::ScreenWidth)) {
		x = float(Graphics::ScreenWidth - w);
	}
	else if (x < 0) {
		x = 0.0f;
	}

	if (y + float(h) > float(Graphics::ScreenHeight)) {
		y = float(Graphics::ScreenHeight - h);
	}
	else if (y < 0) {
		y = 0.0f;
	}
}

void Dude::DrawFace(Graphics& gfx) const {

	int int_x = int(x);
	int int_y = int(y);

	gfx.PutPixel(7 + int_x, 0 + int_y, 0, 0, 0);
	gfx.PutPixel(8 + int_x, 0 + int_y, 0, 0, 0);
	gfx.PutPixel(9 + int_x, 0 + int_y, 0, 0, 0);
	gfx.PutPixel(10 + int_x, 0 + int_y, 0, 0, 0);
	gfx.PutPixel(11 + int_x, 0 + int_y, 0, 0, 0);
	gfx.PutPixel(12 + int_x, 0 + int_y, 0, 0, 0);
	gfx.PutPixel(5 + int_x, 1 + int_y, 0, 0, 0);
	gfx.PutPixel(6 + int_x, 1 + int_y, 0, 0, 0);
	gfx.PutPixel(7 + int_x, 1 + int_y, 254, 221, 88);
	gfx.PutPixel(8 + int_x, 1 + int_y, 254, 221, 88);
	gfx.PutPixel(9 + int_x, 1 + int_y, 254, 221, 88);
	gfx.PutPixel(10 + int_x, 1 + int_y, 254, 221, 88);
	gfx.PutPixel(11 + int_x, 1 + int_y, 254, 221, 88);
	gfx.PutPixel(12 + int_x, 1 + int_y, 254, 221, 88);
	gfx.PutPixel(13 + int_x, 1 + int_y, 0, 0, 0);
	gfx.PutPixel(14 + int_x, 1 + int_y, 0, 0, 0);
	gfx.PutPixel(3 + int_x, 2 + int_y, 0, 0, 0);
	gfx.PutPixel(4 + int_x, 2 + int_y, 0, 0, 0);
	gfx.PutPixel(5 + int_x, 2 + int_y, 254, 221, 88);
	gfx.PutPixel(6 + int_x, 2 + int_y, 254, 221, 88);
	gfx.PutPixel(7 + int_x, 2 + int_y, 254, 221, 88);
	gfx.PutPixel(8 + int_x, 2 + int_y, 254, 221, 88);
	gfx.PutPixel(9 + int_x, 2 + int_y, 254, 221, 88);
	gfx.PutPixel(10 + int_x, 2 + int_y, 254, 221, 88);
	gfx.PutPixel(11 + int_x, 2 + int_y, 254, 221, 88);
	gfx.PutPixel(12 + int_x, 2 + int_y, 254, 221, 88);
	gfx.PutPixel(13 + int_x, 2 + int_y, 254, 221, 88);
	gfx.PutPixel(14 + int_x, 2 + int_y, 254, 221, 88);
	gfx.PutPixel(15 + int_x, 2 + int_y, 0, 0, 0);
	gfx.PutPixel(16 + int_x, 2 + int_y, 0, 0, 0);
	gfx.PutPixel(2 + int_x, 3 + int_y, 0, 0, 0);
	gfx.PutPixel(3 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(4 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(5 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(6 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(7 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(8 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(9 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(10 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(11 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(12 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(13 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(14 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(15 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(16 + int_x, 3 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 3 + int_y, 0, 0, 0);
	gfx.PutPixel(2 + int_x, 4 + int_y, 0, 0, 0);
	gfx.PutPixel(3 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(4 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(5 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(6 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(7 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(8 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(9 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(10 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(11 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(12 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(13 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(14 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(15 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(16 + int_x, 4 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 4 + int_y, 0, 0, 0);
	gfx.PutPixel(1 + int_x, 5 + int_y, 0, 0, 0);
	gfx.PutPixel(2 + int_x, 5 + int_y, 254, 221, 88);
	gfx.PutPixel(3 + int_x, 5 + int_y, 0, 0, 0);
	gfx.PutPixel(4 + int_x, 5 + int_y, 0, 0, 0);
	gfx.PutPixel(5 + int_x, 5 + int_y, 254, 221, 88);
	gfx.PutPixel(6 + int_x, 5 + int_y, 254, 221, 88);
	gfx.PutPixel(7 + int_x, 5 + int_y, 254, 221, 88);
	gfx.PutPixel(8 + int_x, 5 + int_y, 254, 221, 88);
	gfx.PutPixel(9 + int_x, 5 + int_y, 254, 221, 88);
	gfx.PutPixel(10 + int_x, 5 + int_y, 254, 221, 88);
	gfx.PutPixel(11 + int_x, 5 + int_y, 0, 0, 0);
	gfx.PutPixel(12 + int_x, 5 + int_y, 0, 0, 0);
	gfx.PutPixel(13 + int_x, 5 + int_y, 0, 0, 0);
	gfx.PutPixel(14 + int_x, 5 + int_y, 0, 0, 0);
	gfx.PutPixel(15 + int_x, 5 + int_y, 254, 221, 88);
	gfx.PutPixel(16 + int_x, 5 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 5 + int_y, 254, 221, 88);
	gfx.PutPixel(18 + int_x, 5 + int_y, 0, 0, 0);
	gfx.PutPixel(1 + int_x, 6 + int_y, 0, 0, 0);
	gfx.PutPixel(2 + int_x, 6 + int_y, 0, 0, 0);
	gfx.PutPixel(3 + int_x, 6 + int_y, 255, 255, 255);
	gfx.PutPixel(4 + int_x, 6 + int_y, 0, 0, 0);
	gfx.PutPixel(5 + int_x, 6 + int_y, 0, 0, 0);
	gfx.PutPixel(6 + int_x, 6 + int_y, 254, 221, 88);
	gfx.PutPixel(7 + int_x, 6 + int_y, 254, 221, 88);
	gfx.PutPixel(8 + int_x, 6 + int_y, 254, 221, 88);
	gfx.PutPixel(9 + int_x, 6 + int_y, 254, 221, 88);
	gfx.PutPixel(10 + int_x, 6 + int_y, 0, 0, 0);
	gfx.PutPixel(11 + int_x, 6 + int_y, 255, 255, 255);
	gfx.PutPixel(12 + int_x, 6 + int_y, 255, 255, 255);
	gfx.PutPixel(13 + int_x, 6 + int_y, 0, 0, 0);
	gfx.PutPixel(14 + int_x, 6 + int_y, 0, 0, 0);
	gfx.PutPixel(15 + int_x, 6 + int_y, 0, 0, 0);
	gfx.PutPixel(16 + int_x, 6 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 6 + int_y, 254, 221, 88);
	gfx.PutPixel(18 + int_x, 6 + int_y, 0, 0, 0);
	gfx.PutPixel(0 + int_x, 7 + int_y, 0, 0, 0);
	gfx.PutPixel(1 + int_x, 7 + int_y, 0, 0, 0);
	gfx.PutPixel(2 + int_x, 7 + int_y, 255, 255, 255);
	gfx.PutPixel(3 + int_x, 7 + int_y, 255, 255, 255);
	gfx.PutPixel(4 + int_x, 7 + int_y, 0, 0, 0);
	gfx.PutPixel(5 + int_x, 7 + int_y, 0, 0, 0);
	gfx.PutPixel(6 + int_x, 7 + int_y, 254, 221, 88);
	gfx.PutPixel(7 + int_x, 7 + int_y, 254, 221, 88);
	gfx.PutPixel(8 + int_x, 7 + int_y, 254, 221, 88);
	gfx.PutPixel(9 + int_x, 7 + int_y, 254, 221, 88);
	gfx.PutPixel(10 + int_x, 7 + int_y, 0, 0, 0);
	gfx.PutPixel(11 + int_x, 7 + int_y, 255, 255, 255);
	gfx.PutPixel(12 + int_x, 7 + int_y, 255, 255, 255);
	gfx.PutPixel(13 + int_x, 7 + int_y, 0, 0, 0);
	gfx.PutPixel(14 + int_x, 7 + int_y, 0, 0, 0);
	gfx.PutPixel(15 + int_x, 7 + int_y, 0, 0, 0);
	gfx.PutPixel(16 + int_x, 7 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 7 + int_y, 254, 221, 88);
	gfx.PutPixel(18 + int_x, 7 + int_y, 254, 221, 88);
	gfx.PutPixel(19 + int_x, 7 + int_y, 0, 0, 0);
	gfx.PutPixel(0 + int_x, 8 + int_y, 0, 0, 0);
	gfx.PutPixel(1 + int_x, 8 + int_y, 0, 0, 0);
	gfx.PutPixel(2 + int_x, 8 + int_y, 255, 255, 255);
	gfx.PutPixel(3 + int_x, 8 + int_y, 255, 255, 255);
	gfx.PutPixel(4 + int_x, 8 + int_y, 255, 255, 255);
	gfx.PutPixel(5 + int_x, 8 + int_y, 0, 0, 0);
	gfx.PutPixel(6 + int_x, 8 + int_y, 254, 221, 88);
	gfx.PutPixel(7 + int_x, 8 + int_y, 254, 221, 88);
	gfx.PutPixel(8 + int_x, 8 + int_y, 254, 221, 88);
	gfx.PutPixel(9 + int_x, 8 + int_y, 254, 221, 88);
	gfx.PutPixel(10 + int_x, 8 + int_y, 0, 0, 0);
	gfx.PutPixel(11 + int_x, 8 + int_y, 255, 255, 255);
	gfx.PutPixel(12 + int_x, 8 + int_y, 255, 255, 255);
	gfx.PutPixel(13 + int_x, 8 + int_y, 255, 255, 255);
	gfx.PutPixel(14 + int_x, 8 + int_y, 255, 255, 255);
	gfx.PutPixel(15 + int_x, 8 + int_y, 0, 0, 0);
	gfx.PutPixel(16 + int_x, 8 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 8 + int_y, 254, 221, 88);
	gfx.PutPixel(18 + int_x, 8 + int_y, 254, 221, 88);
	gfx.PutPixel(19 + int_x, 8 + int_y, 0, 0, 0);
	gfx.PutPixel(0 + int_x, 9 + int_y, 0, 0, 0);
	gfx.PutPixel(1 + int_x, 9 + int_y, 254, 221, 88);
	gfx.PutPixel(2 + int_x, 9 + int_y, 0, 0, 0);
	gfx.PutPixel(3 + int_x, 9 + int_y, 0, 0, 0);
	gfx.PutPixel(4 + int_x, 9 + int_y, 0, 0, 0);
	gfx.PutPixel(5 + int_x, 9 + int_y, 0, 0, 0);
	gfx.PutPixel(6 + int_x, 9 + int_y, 254, 221, 88);
	gfx.PutPixel(7 + int_x, 9 + int_y, 254, 221, 88);
	gfx.PutPixel(8 + int_x, 9 + int_y, 254, 221, 88);
	gfx.PutPixel(9 + int_x, 9 + int_y, 254, 221, 88);
	gfx.PutPixel(10 + int_x, 9 + int_y, 254, 221, 88);
	gfx.PutPixel(11 + int_x, 9 + int_y, 0, 0, 0);
	gfx.PutPixel(12 + int_x, 9 + int_y, 0, 0, 0);
	gfx.PutPixel(13 + int_x, 9 + int_y, 0, 0, 0);
	gfx.PutPixel(14 + int_x, 9 + int_y, 0, 0, 0);
	gfx.PutPixel(15 + int_x, 9 + int_y, 254, 221, 88);
	gfx.PutPixel(16 + int_x, 9 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 9 + int_y, 254, 221, 88);
	gfx.PutPixel(18 + int_x, 9 + int_y, 254, 221, 88);
	gfx.PutPixel(19 + int_x, 9 + int_y, 0, 0, 0);
	gfx.PutPixel(0 + int_x, 10 + int_y, 0, 0, 0);
	gfx.PutPixel(1 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(2 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(3 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(4 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(5 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(6 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(7 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(8 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(9 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(10 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(11 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(12 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(13 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(14 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(15 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(16 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(18 + int_x, 10 + int_y, 254, 221, 88);
	gfx.PutPixel(19 + int_x, 10 + int_y, 0, 0, 0);
	gfx.PutPixel(0 + int_x, 11 + int_y, 0, 0, 0);
	gfx.PutPixel(1 + int_x, 11 + int_y, 254, 221, 88);
	gfx.PutPixel(2 + int_x, 11 + int_y, 254, 221, 88);
	gfx.PutPixel(3 + int_x, 11 + int_y, 254, 221, 88);
	gfx.PutPixel(4 + int_x, 11 + int_y, 254, 221, 88);
	gfx.PutPixel(5 + int_x, 11 + int_y, 254, 221, 88);
	gfx.PutPixel(6 + int_x, 11 + int_y, 254, 221, 88);
	gfx.PutPixel(7 + int_x, 11 + int_y, 20, 14, 18);
	gfx.PutPixel(8 + int_x, 11 + int_y, 18, 11, 14);
	gfx.PutPixel(9 + int_x, 11 + int_y, 18, 12, 14);
	gfx.PutPixel(10 + int_x, 11 + int_y, 18, 12, 14);
	gfx.PutPixel(11 + int_x, 11 + int_y, 21, 13, 16);
	gfx.PutPixel(12 + int_x, 11 + int_y, 24, 11, 15);
	gfx.PutPixel(13 + int_x, 11 + int_y, 0, 0, 0);
	gfx.PutPixel(14 + int_x, 11 + int_y, 254, 221, 88);
	gfx.PutPixel(15 + int_x, 11 + int_y, 254, 221, 88);
	gfx.PutPixel(16 + int_x, 11 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 11 + int_y, 254, 221, 88);
	gfx.PutPixel(18 + int_x, 11 + int_y, 254, 221, 88);
	gfx.PutPixel(19 + int_x, 11 + int_y, 0, 0, 0);
	gfx.PutPixel(0 + int_x, 12 + int_y, 0, 0, 0);
	gfx.PutPixel(1 + int_x, 12 + int_y, 254, 221, 88);
	gfx.PutPixel(2 + int_x, 12 + int_y, 254, 221, 88);
	gfx.PutPixel(3 + int_x, 12 + int_y, 254, 221, 88);
	gfx.PutPixel(4 + int_x, 12 + int_y, 254, 221, 88);
	gfx.PutPixel(5 + int_x, 12 + int_y, 254, 221, 88);
	gfx.PutPixel(6 + int_x, 12 + int_y, 23, 9, 23);
	gfx.PutPixel(7 + int_x, 12 + int_y, 135, 26, 68);
	gfx.PutPixel(8 + int_x, 12 + int_y, 135, 26, 68);
	gfx.PutPixel(9 + int_x, 12 + int_y, 135, 26, 68);
	gfx.PutPixel(10 + int_x, 12 + int_y, 135, 26, 68);
	gfx.PutPixel(11 + int_x, 12 + int_y, 135, 26, 68);
	gfx.PutPixel(12 + int_x, 12 + int_y, 135, 26, 68);
	gfx.PutPixel(13 + int_x, 12 + int_y, 135, 26, 68);
	gfx.PutPixel(14 + int_x, 12 + int_y, 0, 0, 0);
	gfx.PutPixel(15 + int_x, 12 + int_y, 254, 221, 88);
	gfx.PutPixel(16 + int_x, 12 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 12 + int_y, 254, 221, 88);
	gfx.PutPixel(18 + int_x, 12 + int_y, 254, 221, 88);
	gfx.PutPixel(19 + int_x, 12 + int_y, 0, 0, 0);
	gfx.PutPixel(1 + int_x, 13 + int_y, 0, 0, 0);
	gfx.PutPixel(2 + int_x, 13 + int_y, 254, 221, 88);
	gfx.PutPixel(3 + int_x, 13 + int_y, 254, 221, 88);
	gfx.PutPixel(4 + int_x, 13 + int_y, 254, 221, 88);
	gfx.PutPixel(5 + int_x, 13 + int_y, 0, 0, 0);
	gfx.PutPixel(6 + int_x, 13 + int_y, 135, 26, 68);
	gfx.PutPixel(7 + int_x, 13 + int_y, 135, 26, 68);
	gfx.PutPixel(8 + int_x, 13 + int_y, 135, 26, 68);
	gfx.PutPixel(9 + int_x, 13 + int_y, 135, 26, 68);
	gfx.PutPixel(10 + int_x, 13 + int_y, 135, 26, 68);
	gfx.PutPixel(11 + int_x, 13 + int_y, 135, 26, 68);
	gfx.PutPixel(12 + int_x, 13 + int_y, 135, 26, 68);
	gfx.PutPixel(13 + int_x, 13 + int_y, 135, 26, 68);
	gfx.PutPixel(14 + int_x, 13 + int_y, 135, 26, 68);
	gfx.PutPixel(15 + int_x, 13 + int_y, 0, 0, 0);
	gfx.PutPixel(16 + int_x, 13 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 13 + int_y, 254, 221, 88);
	gfx.PutPixel(18 + int_x, 13 + int_y, 0, 0, 0);
	gfx.PutPixel(1 + int_x, 14 + int_y, 0, 0, 0);
	gfx.PutPixel(2 + int_x, 14 + int_y, 254, 221, 88);
	gfx.PutPixel(3 + int_x, 14 + int_y, 254, 221, 88);
	gfx.PutPixel(4 + int_x, 14 + int_y, 0, 0, 0);
	gfx.PutPixel(5 + int_x, 14 + int_y, 135, 26, 68);
	gfx.PutPixel(6 + int_x, 14 + int_y, 135, 26, 68);
	gfx.PutPixel(7 + int_x, 14 + int_y, 135, 26, 68);
	gfx.PutPixel(8 + int_x, 14 + int_y, 135, 26, 68);
	gfx.PutPixel(9 + int_x, 14 + int_y, 251, 192, 224);
	gfx.PutPixel(10 + int_x, 14 + int_y, 251, 192, 224);
	gfx.PutPixel(11 + int_x, 14 + int_y, 251, 192, 224);
	gfx.PutPixel(12 + int_x, 14 + int_y, 251, 192, 224);
	gfx.PutPixel(13 + int_x, 14 + int_y, 135, 26, 68);
	gfx.PutPixel(14 + int_x, 14 + int_y, 135, 26, 68);
	gfx.PutPixel(15 + int_x, 14 + int_y, 0, 0, 0);
	gfx.PutPixel(16 + int_x, 14 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 14 + int_y, 254, 221, 88);
	gfx.PutPixel(18 + int_x, 14 + int_y, 0, 0, 0);
	gfx.PutPixel(2 + int_x, 15 + int_y, 0, 0, 0);
	gfx.PutPixel(3 + int_x, 15 + int_y, 254, 221, 88);
	gfx.PutPixel(4 + int_x, 15 + int_y, 0, 0, 0);
	gfx.PutPixel(5 + int_x, 15 + int_y, 135, 26, 68);
	gfx.PutPixel(6 + int_x, 15 + int_y, 135, 26, 68);
	gfx.PutPixel(7 + int_x, 15 + int_y, 135, 26, 68);
	gfx.PutPixel(8 + int_x, 15 + int_y, 251, 192, 224);
	gfx.PutPixel(9 + int_x, 15 + int_y, 251, 192, 224);
	gfx.PutPixel(10 + int_x, 15 + int_y, 251, 192, 224);
	gfx.PutPixel(11 + int_x, 15 + int_y, 251, 192, 224);
	gfx.PutPixel(12 + int_x, 15 + int_y, 251, 192, 224);
	gfx.PutPixel(13 + int_x, 15 + int_y, 251, 192, 224);
	gfx.PutPixel(14 + int_x, 15 + int_y, 135, 26, 68);
	gfx.PutPixel(15 + int_x, 15 + int_y, 0, 0, 0);
	gfx.PutPixel(16 + int_x, 15 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 15 + int_y, 0, 0, 0);
	gfx.PutPixel(2 + int_x, 16 + int_y, 0, 0, 0);
	gfx.PutPixel(3 + int_x, 16 + int_y, 254, 221, 88);
	gfx.PutPixel(4 + int_x, 16 + int_y, 0, 0, 0);
	gfx.PutPixel(5 + int_x, 16 + int_y, 135, 26, 68);
	gfx.PutPixel(6 + int_x, 16 + int_y, 135, 26, 68);
	gfx.PutPixel(7 + int_x, 16 + int_y, 135, 26, 68);
	gfx.PutPixel(8 + int_x, 16 + int_y, 251, 192, 224);
	gfx.PutPixel(9 + int_x, 16 + int_y, 251, 192, 224);
	gfx.PutPixel(10 + int_x, 16 + int_y, 251, 192, 224);
	gfx.PutPixel(11 + int_x, 16 + int_y, 251, 192, 224);
	gfx.PutPixel(12 + int_x, 16 + int_y, 251, 192, 224);
	gfx.PutPixel(13 + int_x, 16 + int_y, 251, 192, 224);
	gfx.PutPixel(14 + int_x, 16 + int_y, 135, 26, 68);
	gfx.PutPixel(15 + int_x, 16 + int_y, 0, 0, 0);
	gfx.PutPixel(16 + int_x, 16 + int_y, 254, 221, 88);
	gfx.PutPixel(17 + int_x, 16 + int_y, 0, 0, 0);
	gfx.PutPixel(3 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(4 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(5 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(6 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(7 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(8 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(9 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(10 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(11 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(12 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(13 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(14 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(15 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(16 + int_x, 17 + int_y, 0, 0, 0);
	gfx.PutPixel(5 + int_x, 18 + int_y, 0, 0, 0);
	gfx.PutPixel(6 + int_x, 18 + int_y, 0, 0, 0);
	gfx.PutPixel(7 + int_x, 18 + int_y, 254, 221, 88);
	gfx.PutPixel(8 + int_x, 18 + int_y, 254, 221, 88);
	gfx.PutPixel(9 + int_x, 18 + int_y, 254, 221, 88);
	gfx.PutPixel(10 + int_x, 18 + int_y, 254, 221, 88);
	gfx.PutPixel(11 + int_x, 18 + int_y, 254, 221, 88);
	gfx.PutPixel(12 + int_x, 18 + int_y, 254, 221, 88);
	gfx.PutPixel(13 + int_x, 18 + int_y, 0, 0, 0);
	gfx.PutPixel(14 + int_x, 18 + int_y, 0, 0, 0);
	gfx.PutPixel(7 + int_x, 19 + int_y, 0, 0, 0);
	gfx.PutPixel(8 + int_x, 19 + int_y, 0, 0, 0);
	gfx.PutPixel(9 + int_x, 19 + int_y, 0, 0, 0);
	gfx.PutPixel(10 + int_x, 19 + int_y, 0, 0, 0);
	gfx.PutPixel(11 + int_x, 19 + int_y, 0, 0, 0);
	gfx.PutPixel(12 + int_x, 19 + int_y, 0, 0, 0);

}

void Dude::setSpeed(const float newSpeed)
{
	speed = newSpeed;
}

float Dude::getX() const
{
	return x;
}

float Dude::getY() const
{
	return y;
}

int Dude::getW() const
{
	return w;
}

int Dude::getH() const
{
	return h;
}

void Dude::reset()
{
	x = 200.0f;
	y = 300.0f;
	speed = startSpeed;
}
