#include "Board.h"

Board::Board()
	:
	snk(length, height),
	goal(length, height),
	barr(length, height)
{
	c = { 148, 147, 146 };
}

void Board::drawBrd(Graphics& gfx)
{
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < height; j++) {
			for (int k = x + i * cellDim; k < x + i * cellDim + cellDim; k++) {
				for(int m = y + j * cellDim; m < y + j * cellDim + cellDim; m++) {
					if (k == x + i * cellDim ||
						m == y + j * cellDim){
						gfx.PutPixel(0, 0, 0);
					}
					else {
						gfx.PutPixel(k, m, c);
					}
				}
			}
		}
	}

	drawGoal(gfx);
	drawBarriers(gfx);
	drawSnk(gfx);
}

void Board::drawSnk(Graphics& gfx)
{
	for (int i = 0; i < snk.getSize(); i++) {
		for (int j = snk.getSegLoc(i).x * cellDim + x; j < snk.getSegLoc(i).x * cellDim + x + cellDim; j++) {
			for (int k = snk.getSegLoc(i).y * cellDim + y; k < snk.getSegLoc(i).y * cellDim + y + cellDim; k++) {
				if (j == snk.getSegLoc(i).x * cellDim + x || j == snk.getSegLoc(i).x * cellDim + x + cellDim - 1 ||
					k == snk.getSegLoc(i).y * cellDim + y || k == snk.getSegLoc(i).y * cellDim + y + cellDim - 1) {
					gfx.PutPixel(j, k, Color(0, 0, 0));
				}
				else {
					gfx.PutPixel(j, k, snk.getColor(i));
				}
			}
		}
	}

	////for debugging purposes. shows the next head location
	//for (int i = snk.getNextHeadLoc().x * cellDim + x; i < snk.getNextHeadLoc().x * cellDim + x + cellDim; i++) {
	//	for (int j = snk.getNextHeadLoc().y * cellDim + y; j < snk.getNextHeadLoc().y * cellDim + y + cellDim; j++) {
	//		if (i == snk.getNextHeadLoc().x * cellDim + x || i == snk.getNextHeadLoc().x * cellDim + x + cellDim - 1 ||
	//			j == snk.getNextHeadLoc().y * cellDim + y || j == snk.getNextHeadLoc().y * cellDim + y + cellDim - 1) {
	//			gfx.PutPixel(i, j, Color(255, 0, 0));
	//		}
	//	}
	//}
}

void Board::drawGoal(Graphics& gfx)
{
	Location loc = goal.getLoc();

	for (int i = loc.x * cellDim + x; i < loc.x * cellDim + x + cellDim; i++) {
		for (int j = loc.y * cellDim + y; j < loc.y * cellDim + y + cellDim; j++) {
			if (i == loc.x * cellDim + x || i == loc.x * cellDim + x + cellDim - 1 ||
				j == loc.y * cellDim + y || j == loc.y * cellDim + y + cellDim - 1) {
				gfx.PutPixel(i, j, Color(0, 0, 0));
			}
			else {
				gfx.PutPixel(i, j, goal.getColor());
			}
		}
	}

	goal.colorPulse();
}

void Board::drawBarriers(Graphics& gfx)
{
	for (int i = 0; i < barr.getNumBarriers(); i++) {
		for (int m = barr.getLoc(i).x * cellDim + x; m < barr.getLoc(i).x * cellDim + x + cellDim; m++) {
			for (int n = barr.getLoc(i).y * cellDim + y; n < barr.getLoc(i).y * cellDim + y + cellDim; n++) {
				gfx.PutPixel(m, n, barr.getColor());
			}
		}
	}
}

void Board::snkCollisionCheck() {
	// border check
	if (snk.getNextHeadLoc().x < 0) {
		gameOver = true;
	}
	if (snk.getNextHeadLoc().x >= length) {
		gameOver = true;
	}
	if (snk.getNextHeadLoc().y < 0) {
		gameOver = true;
	}
	if (snk.getNextHeadLoc().y >= height) {
		gameOver = true;
	}


	//self collision check
	for (int i = 1; i < snk.getSize() - 1; i++) {
		if (snk.getSegLoc(i) == snk.getNextHeadLoc()) {
			gameOver = true;
			break;
		}
	}

	//barrier collision check
	for (int i = 0; i < barr.getNumBarriers(); i++) {
		if (snk.getNextHeadLoc() == barr.getLoc(i)) {
			gameOver = true;
			break;
		}
	}

}

void Board::updateSnk(MainWindow& wnd)
{
	
	snk.playerInput(wnd);

	if (count >= updateCounter) {

		snk.updateDir();

		snkCollisionCheck();
		
		if (goal.getIsEaten()) {
			snk.grow();
			goal.setIsEaten(false);
		}

		if (!gameOver) {
			snk.move(length, height);
		}
		count = 0.0f;
	}
	count += dt;
}

void Board::updateGoal()
{
	if (snk.getSegLoc(0) == goal.getLoc()) {
		goal.setIsEaten(true);

		
		if (barr.getNumBarriers() > 0) {
			barrLocs[barr.getNumBarriers() - 1] = barr.getLoc(barr.getNumBarriers() - 1);
		}

		
		for (int i = 0; i < snk.getSize(); i++) {
			snkLocs[i] = snk.getSegLoc(i);
		}

		goal.randomizeLoc(snkLocs, snk.getSize(), barrLocs, barr.getNumBarriers());

		if (snk.getSize() % 2 == 0) {
			barr.addBarrier(snkLocs, snk.getSize(), goal.getLoc());
			speedChanged = false;
		}
	}
}

void Board::updateSpeed() {
	if (barr.getNumBarriers() % 2 == 0 && !speedChanged) {
		updateCounter *= .9;
		speedChanged = true;
	}
}

void Board::update(MainWindow& wnd, float newDt)
{
	dt = newDt;
	updateGoal();
	updateSnk(wnd);
	updateSpeed();
}

void Board::reset()
{
	snk.reset();
	barr.reset();
	updateCounter = 0.1;


	for (int i = 0; i < barr.getNumBarriers(); i++) {
		barrLocs[i] = barr.getLoc(i);
	}

	for (int i = 0; i < snk.getSize(); i++) {
		snkLocs[i] = snk.getSegLoc(i);
	}

	goal.randomizeLoc(snkLocs, snk.getSize(), barrLocs, barr.getNumBarriers());
	gameOver = false;
}

bool Board::getGameOver() const
{
	return gameOver;
}
