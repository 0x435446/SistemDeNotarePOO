#pragma once

#include <string>
#include <time.h>
#include <chrono>
#include <Windows.h>
#include "Entity.h"

class Action
{
private:

	Entity *matrix[9][5]; //matricea care memoreza obiectele
	static Action *instance;

public:

	static Action & getInstance(void);

	int place_plants(std::string action_one,int score, int level);
	void plants_attack();
	
	int end_game();
	int attack_zombie();

	int spawn_zobie(std::string type, int level, int previous_spawn);
	void move_zombie();

	float get_time(int i, int j) { return matrix[i][j]->get_speed(); }
	void equal(Entity* zombie_gol, Entity* zombie_vechi);
	WORD GetConsoleTextAttribute(HANDLE hCon);

	friend class Afisare;
private:
	Action();
	~Action();
};



