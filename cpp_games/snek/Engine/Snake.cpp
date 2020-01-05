#include "Snake.h"



void Snake::playerInput(MainWindow& wnd) 
{
	
	bool isUp = wnd.kbd.KeyIsPressed(VK_UP);
	bool isDown = wnd.kbd.KeyIsPressed(VK_DOWN);
	bool isRight = wnd.kbd.KeyIsPressed(VK_RIGHT);
	bool isLeft = wnd.kbd.KeyIsPressed(VK_LEFT);

	// gotta make sure the queue is currently under 3 stored moves 
	// also makes sure no moves are made when two keys are pressed at the same time
	if (inputQueue.size() < 3 && !((isUp && isDown) || (isUp && isRight) || 
		(isUp && isLeft) || (isDown && isRight) || (isDown && isLeft) || (isRight && isLeft))) {

		if (isUp && lastEnteredInput != 'S' && lastEnteredInput != 'N') {
			inputQueue.push('N');
			lastEnteredInput = 'N';
		}
		else if (isDown && lastEnteredInput != 'N' && lastEnteredInput != 'S') {
			inputQueue.push('S');
			lastEnteredInput = 'S';
		}
		else if (isRight && lastEnteredInput != 'W' && lastEnteredInput != 'E') {
			inputQueue.push('E');
			lastEnteredInput = 'E';
		}
		else if (isLeft && lastEnteredInput != 'W' && lastEnteredInput != 'E') {
			inputQueue.push('W');
			lastEnteredInput = 'W';
		}
	}
}

void Snake::updateDir() {
	if (inputQueue.size() > 0) {
		headDir = inputQueue.front();
		inputQueue.pop();
	
		Location currLoc = body[0].getLoc();

		if (headDir == 'N') {
			NextHeadLoc = { currLoc.x, --currLoc.y };
		}
		else if (headDir == 'E') {
			NextHeadLoc = { ++currLoc.x, currLoc.y };
		}
		else if (headDir == 'S') {
			NextHeadLoc = { currLoc.x, ++currLoc.y };
		}
		else if (headDir == 'W') {
			NextHeadLoc = { --currLoc.x, currLoc.y };
		}
	
	
	}
}

void Snake::grow()
{
	size++;
}


void Snake::move(int brdlng, int brdhgt)
{
	

	for (int i = size - 1; i > 0; i--) {
		body[i] = body[i - 1];
	}
	body[0].setLoc(NextHeadLoc);



	if (headDir == 'N') {
		NextHeadLoc.y--;
	}
	else if (headDir == 'E') {
		NextHeadLoc.x++;
	}
	else if (headDir == 'S') {
		NextHeadLoc.y++;
	}
	else if (headDir == 'W') {
		NextHeadLoc.x--;
	}
}

void Snake::reset()
{
	size = 1;
	NextHeadLoc = { startX, startY };
	body[0].setLoc(NextHeadLoc);
	headDir = 'N';
	lastEnteredInput = 'O';
}

Snake::Snake(int length, int height)
{
	startX = length / 2;
	startY = height / 2;
	NextHeadLoc = { startX, startY };
	headDir = 'N';
	size = 1;
	body[0].setLoc(NextHeadLoc);
}

int Snake::getSize() const
{
	return size;
}

Color Snake::getColor(int index)
{
	if (index == 0) {
		return colors[0];
	}
	else {
		return colors[index % 4 + 1];
	}
}

Location Snake::getSegLoc(const int index) const
{
	return body[index].getLoc();
}

Location Snake::getNextHeadLoc() const
{
	return NextHeadLoc;
}


