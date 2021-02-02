#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <time.h>
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#define TILE_WIDTH 19
#define TILE_HEIGHT 6
#define TL  201;
#define TR  187;
#define BL  200;
#define BR  188;
using namespace std;
using namespace std::chrono;

class IDrawable
{
	virtual void draw() = 0;
protected:
	steady_clock::time_point begin;
	int startX, startY;
};

