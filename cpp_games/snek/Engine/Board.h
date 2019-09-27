#pragma once

#include "Snake.h"
#include "Goal.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Barriers.h"


class Board {
private:
	const int length = 35;
	const int height = 25;
	const int x = 50;
	const int y = 50;
	const int cellDim = 20; // number of pixels per side of each cell in the grid

	Color c = { 148, 147, 146 };
	Snake snk;
	Goal goal;
	Barriers barr;
	Location barrLocs[2500];
	Location snkLocs[2500];
	bool gameOver = false;

	double updateCounter = 0.15; //seconds until next movement update
	double count = 0.0;
	double dt = 0.0;
	bool speedChanged = false;

	void drawSnk(Graphics& gfx);
	void drawGoal(Graphics& gfx);
	void drawBarriers(Graphics& gfx);

	void updateSnk(MainWindow& wnd);
	void updateGoal();
	void snkCollisionCheck();
	void updateSpeed();

public:

	Board();

	void drawBrd(Graphics& gfx);
	void update(MainWindow& wnd, float dt);
	void reset();
	bool getGameOver() const;


};