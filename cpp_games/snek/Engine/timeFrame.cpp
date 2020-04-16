#include "timeFrame.h"

TimeFrame::TimeFrame()
{
	last = std::chrono::steady_clock::now();
}

float TimeFrame::timeStamp()
{
	const auto old = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> runtime = last - old;

	return runtime.count();
}
