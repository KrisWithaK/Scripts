#pragma once
#include "Graphics.h"
#include "MainWindow.h"

class Square {

private:
	int x0;
	int y0;
	int x1;
	int y1;
	void ClampXY(const MainWindow& wnd);

public:
	void Update(const MainWindow& wnd);
	void setX0(int xCoord);
	void setY0(int yCoord);
	int getX0() const;
	int getY0() const;
	void setX1(int xCoord);
	void setY1(int yCoord);
	int getX1() const;
	int getY1() const;

};