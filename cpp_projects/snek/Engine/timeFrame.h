#pragma once
#include <chrono>



class TimeFrame {
private:
	std::chrono::steady_clock::time_point last;

public:
	TimeFrame();
	float timeStamp(); // returns the duration since the last timeStam


};