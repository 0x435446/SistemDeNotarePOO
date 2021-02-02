#pragma once
#include <vector>
#include "ConsoleOutput.h"
#include "ConsoleInput.h"
#include "SunField.h"
#include "BattleField.h"
#include "ExceptionHandler.h"
#include "Plant.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include "Cherrybomb.h"
#include "Potato.h"
#include "Frozen_Peashooter.h"

class Click
{
private:
	int sun_value = 0;
	std::vector<Plant*> plants_vector;

public:
	Click();
	~Click();
	void get_click(int x, int y);
	void click_sun(int poz);
	void click_plant(int nr);
	void place_plant(int plant_id);
	void put_plant(int plant_id, int x, int y);
	std::vector<Plant*> get_vector();
};

