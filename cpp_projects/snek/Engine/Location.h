#pragma once

struct Location {

	int x;
	int y;

	bool operator==(const Location& loc) const{
		if (loc.x == x && loc.y == y) {
			return true;
		}
		else {
			return false;
		}
	}
};