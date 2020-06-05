#include "Fruit.h"


Fruit::Fruit(float in_x, float in_y, float in_vx, float in_vy)
{
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
}

Fruit::Fruit() {
}

void Fruit::Update(float dt) {

	x += vx * dt;
	y += vy * dt;


	const float right = x + w;
	if (right >= Graphics::ScreenWidth) {
		x = (Graphics::ScreenWidth - 1) - w;
		vx = -vx;
	}
	else if (x < 0) {
		x = 0;
		vx = -vx;
	}

	const float bottom = y + h;
	if (y < 0) {
		y = 0;
		vy = -vy;
	}
	else if (bottom >= Graphics::ScreenHeight) {
		y = (Graphics::ScreenHeight - 1) - h;
		vy = -vy;
	}
}

void Fruit::DrawFruit(Graphics& gfx) const {

	int int_x = int(x);
	int int_y = int(y);

	gfx.PutPixel(14 + int_x, 0 + int_y, 138, 77, 0);
	gfx.PutPixel(7 + int_x, 1 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 1 + int_y, 138, 77, 0);
	gfx.PutPixel(20 + int_x, 1 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 2 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 2 + int_y, 138, 77, 0);
	gfx.PutPixel(20 + int_x, 2 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 3 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 4 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 4 + int_y, 138, 77, 0);
	gfx.PutPixel(21 + int_x, 4 + int_y, 138, 77, 0);
	gfx.PutPixel(7 + int_x, 5 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 5 + int_y, 138, 77, 0);
	gfx.PutPixel(21 + int_x, 5 + int_y, 138, 77, 0);
	gfx.PutPixel(7 + int_x, 6 + int_y, 138, 77, 0);
	gfx.PutPixel(20 + int_x, 6 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 7 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 7 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 7 + int_y, 51, 28, 0);
	gfx.PutPixel(20 + int_x, 7 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 8 + int_y, 51, 28, 0);
	gfx.PutPixel(13 + int_x, 8 + int_y, 51, 28, 0);
	gfx.PutPixel(14 + int_x, 8 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 9 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 9 + int_y, 51, 28, 0);
	gfx.PutPixel(12 + int_x, 9 + int_y, 102, 57, 0);
	gfx.PutPixel(13 + int_x, 9 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 9 + int_y, 138, 77, 0);
	gfx.PutPixel(15 + int_x, 9 + int_y, 51, 28, 0);
	gfx.PutPixel(21 + int_x, 9 + int_y, 138, 77, 0);
	gfx.PutPixel(10 + int_x, 10 + int_y, 51, 28, 0);
	gfx.PutPixel(11 + int_x, 10 + int_y, 51, 28, 0);
	gfx.PutPixel(12 + int_x, 10 + int_y, 102, 57, 0);
	gfx.PutPixel(13 + int_x, 10 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 10 + int_y, 138, 77, 0);
	gfx.PutPixel(15 + int_x, 10 + int_y, 51, 28, 0);
	gfx.PutPixel(20 + int_x, 10 + int_y, 138, 77, 0);
	gfx.PutPixel(9 + int_x, 11 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 11 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 11 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 11 + int_y, 51, 28, 0);
	gfx.PutPixel(13 + int_x, 11 + int_y, 51, 28, 0);
	gfx.PutPixel(14 + int_x, 11 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 11 + int_y, 51, 28, 0);
	gfx.PutPixel(16 + int_x, 11 + int_y, 51, 28, 0);
	gfx.PutPixel(9 + int_x, 12 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 12 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 12 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 12 + int_y, 111, 62, 0);
	gfx.PutPixel(13 + int_x, 12 + int_y, 102, 57, 0);
	gfx.PutPixel(14 + int_x, 12 + int_y, 102, 57, 0);
	gfx.PutPixel(15 + int_x, 12 + int_y, 102, 57, 0);
	gfx.PutPixel(16 + int_x, 12 + int_y, 51, 28, 0);
	gfx.PutPixel(9 + int_x, 13 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 13 + int_y, 109, 61, 0);
	gfx.PutPixel(11 + int_x, 13 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 13 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 13 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 13 + int_y, 138, 77, 0);
	gfx.PutPixel(15 + int_x, 13 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 13 + int_y, 51, 28, 0);
	gfx.PutPixel(5 + int_x, 14 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 14 + int_y, 51, 28, 0);
	gfx.PutPixel(8 + int_x, 14 + int_y, 51, 28, 0);
	gfx.PutPixel(9 + int_x, 14 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 14 + int_y, 51, 28, 0);
	gfx.PutPixel(11 + int_x, 14 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 14 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 14 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 14 + int_y, 138, 77, 0);
	gfx.PutPixel(15 + int_x, 14 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 14 + int_y, 51, 28, 0);
	gfx.PutPixel(4 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(5 + int_x, 15 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 15 + int_y, 116, 65, 0);
	gfx.PutPixel(8 + int_x, 15 + int_y, 138, 77, 0);
	gfx.PutPixel(9 + int_x, 15 + int_y, 138, 77, 0);
	gfx.PutPixel(10 + int_x, 15 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(12 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(13 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(14 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(16 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(17 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(18 + int_x, 15 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(2 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(3 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(4 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(5 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 16 + int_y, 116, 65, 0);
	gfx.PutPixel(8 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(9 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(10 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 16 + int_y, 109, 61, 0);
	gfx.PutPixel(14 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(17 + int_x, 16 + int_y, 138, 77, 0);
	gfx.PutPixel(18 + int_x, 16 + int_y, 123, 69, 0);
	gfx.PutPixel(19 + int_x, 16 + int_y, 51, 28, 0);
	gfx.PutPixel(0 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 17 + int_y, 87, 49, 0);
	gfx.PutPixel(2 + int_x, 17 + int_y, 87, 49, 0);
	gfx.PutPixel(3 + int_x, 17 + int_y, 87, 49, 0);
	gfx.PutPixel(4 + int_x, 17 + int_y, 87, 49, 0);
	gfx.PutPixel(5 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(6 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 17 + int_y, 43, 24, 0);
	gfx.PutPixel(8 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(9 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(11 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(12 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(13 + int_x, 17 + int_y, 40, 22, 0);
	gfx.PutPixel(14 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 17 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 17 + int_y, 138, 77, 0);
	gfx.PutPixel(17 + int_x, 17 + int_y, 138, 77, 0);
	gfx.PutPixel(18 + int_x, 17 + int_y, 123, 69, 0);
	gfx.PutPixel(19 + int_x, 17 + int_y, 51, 28, 0);
	gfx.PutPixel(0 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(2 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(3 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(4 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(5 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(6 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(8 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(9 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(11 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(12 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(13 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(14 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(17 + int_x, 18 + int_y, 138, 77, 0);
	gfx.PutPixel(18 + int_x, 18 + int_y, 123, 69, 0);
	gfx.PutPixel(19 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(20 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(21 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(22 + int_x, 18 + int_y, 51, 28, 0);
	gfx.PutPixel(0 + int_x, 19 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(2 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(3 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(4 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(5 + int_x, 19 + int_y, 51, 28, 0);
	gfx.PutPixel(6 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(7 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(8 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(9 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(10 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(15 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(17 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(18 + int_x, 19 + int_y, 123, 69, 0);
	gfx.PutPixel(19 + int_x, 19 + int_y, 51, 28, 0);
	gfx.PutPixel(20 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(21 + int_x, 19 + int_y, 138, 77, 0);
	gfx.PutPixel(22 + int_x, 19 + int_y, 65, 36, 0);
	gfx.PutPixel(23 + int_x, 19 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(2 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(3 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(4 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(5 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(6 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(7 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(8 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(9 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(10 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(11 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(12 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(13 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(14 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(15 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(16 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(17 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(18 + int_x, 20 + int_y, 123, 69, 0);
	gfx.PutPixel(19 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(20 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(21 + int_x, 20 + int_y, 138, 77, 0);
	gfx.PutPixel(22 + int_x, 20 + int_y, 65, 36, 0);
	gfx.PutPixel(23 + int_x, 20 + int_y, 51, 28, 0);
	gfx.PutPixel(0 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 21 + int_y, 138, 77, 0);
	gfx.PutPixel(2 + int_x, 21 + int_y, 138, 77, 0);
	gfx.PutPixel(3 + int_x, 21 + int_y, 138, 77, 0);
	gfx.PutPixel(4 + int_x, 21 + int_y, 138, 77, 0);
	gfx.PutPixel(5 + int_x, 21 + int_y, 138, 77, 0);
	gfx.PutPixel(6 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(7 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(8 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(9 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(10 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(11 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(12 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(13 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(14 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(15 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(16 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(17 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(18 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(20 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(21 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(22 + int_x, 21 + int_y, 51, 28, 0);
	gfx.PutPixel(0 + int_x, 22 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 22 + int_y, 65, 36, 0);
	gfx.PutPixel(2 + int_x, 22 + int_y, 65, 36, 0);
	gfx.PutPixel(3 + int_x, 22 + int_y, 65, 36, 0);
	gfx.PutPixel(4 + int_x, 22 + int_y, 65, 36, 0);
	gfx.PutPixel(5 + int_x, 22 + int_y, 65, 36, 0);
	gfx.PutPixel(6 + int_x, 22 + int_y, 51, 28, 0);
	gfx.PutPixel(1 + int_x, 23 + int_y, 51, 28, 0);
	gfx.PutPixel(2 + int_x, 23 + int_y, 51, 28, 0);
	gfx.PutPixel(3 + int_x, 23 + int_y, 51, 28, 0);
	gfx.PutPixel(4 + int_x, 23 + int_y, 51, 28, 0);
	gfx.PutPixel(5 + int_x, 23 + int_y, 51, 28, 0);
	gfx.PutPixel(6 + int_x, 23 + int_y, 51, 28, 0);

}

bool Fruit::testCollision(const Dude& dude) const{
	
	return dude.getX() + dude.getW() > x && dude.getX() + dude.getW() < x + w && dude.getY() + dude.getH() > y && dude.getY() + dude.getH() < y + h ||
		dude.getX() > x && dude.getX() < x + w && dude.getY() + dude.getH() > y && dude.getY() + dude.getH() < y + h ||
		dude.getX() > x && dude.getX() < x + w && dude.getY() > y && dude.getY() < y + h ||
		dude.getX() + dude.getW() > x && dude.getX() + dude.getW() < x + w && dude.getY() > y && dude.getY() < y + h;
}

void Fruit::setX(const float newX)
{
	x = newX;
}

void Fruit::setY(const float newY)
{
	y = newY;
}

void Fruit::setVX(const float newVX)
{
	vx = newVX;
}

void Fruit::setVY(const float newVY)
{
	vy = newVY;
}
