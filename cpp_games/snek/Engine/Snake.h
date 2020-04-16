#pragma once
#include "Location.h"
#include "Colors.h"
#include "MainWindow.h"
#include <queue>

class Snake {
private:
	class Segment {

		Location loc = { -1, -1 };

	public:
		Segment() {
			loc = { -1, -1 };
		}
		Segment(const Segment& seg2) {
			loc = seg2.getLoc();
		}
		void setLoc(const Location location) {
			loc = location;
		}
		Location getLoc() const {
			return loc;
		}
	};

	Color colors[5] = { Color(215, 255, 13), Color(56, 138, 35), Color(65, 156, 40),
							  Color(42, 143, 21), Color(34, 128, 16) };

	int startX;
	int startY;

	Location NextHeadLoc;
	char headDir = 'N';
	int size = 1;
	Segment body[2500];
	char lastEnteredInput = 'O';
	std::queue<char> inputQueue;

public:
	Snake(int length, int height);

	void playerInput(MainWindow& wnd);
	void updateDir();
	void grow();
	void move(int brdlng, int brdhgt);
	void reset();

	int getSize() const;
	Color getColor(const int index);
	Location getSegLoc(const int index) const;
	Location getNextHeadLoc() const;



};