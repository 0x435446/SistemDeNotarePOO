#include "AbMakeSun.h"
using namespace std::chrono;

bool AbMakeSun::getSunTime(int time)
{
	static auto Start = high_resolution_clock::now();
	auto End = high_resolution_clock::now();
	if (duration_cast<milliseconds>((End - Start)).count() > time)
	{
		Start = End;
		return 1;
	}
	return 0;
}
