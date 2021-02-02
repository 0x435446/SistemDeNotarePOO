#pragma once
#include <vector>
#include "ConsoleInput.h"
#include "Zombies.h"
#include "Zombie.h"
#include "BattleField.h"
#include "Plant.h"
#include "Peashooter.h"
#include "Click.h"
class Combat
{
private:
	static Combat *instance;
	std::vector<Zombies*> zombie_vector;


public:
	Combat();
	~Combat();
	void create_zombie();
	bool fight(Click&);

	static Combat *GetInstance();
	Combat& operator=(const Combat&);
};

