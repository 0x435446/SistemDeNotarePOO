#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "ConsoleInput.h"
#include "ConsoleOutput.h"
#include "Lane.h"
#include "History.h"

#define ROW_TITLE					20			
#define COL_FIRST_STAR_POSITION		75
#define COL_DISTANCE_BETWEEN_STARS	5
#define SUN_PER_COLLECTED_SUN		10

#define X 10
#define Y 12
#define SUNS_POSITION 7

// the lane ticks every 10 milliseconds
#define TICK_INTERVAL 10


using namespace std;
class Level
{
private:
	int level_number;
	vector<Lane*> lanes;
	
public:
	Level();
	Level(int level_number);
	~Level();

	vector<Lane*>& get_lanes();

	void drawSurface(int lane_num, int offset_to_right);
	void drawSurfaces(int offset_to_right);

	void tick_lanes();

	int compute_score();
	static int player_score;
};

