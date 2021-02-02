#include "Level.h"

using namespace GameMechanics;

Level::Level(int levelNo)
{
	levelGenerator(levelNo);
}


Level::~Level()
{
}


void Level::levelGenerator(int levelNo)
{
	this->levelNo = levelNo;

	switch (levelNo)
	{
	case 1:
		lanesNo = 1;
		break;
	case 2:
		lanesNo = 3;
		break;
	default:
		lanesNo = 5;
		break;
	}

	for (unsigned i = 0; i < PLANTS_ID.size(); i++)
		plantDefaultStatus[PLANTS_ID[i]] = PlantStatus::AVAILABLE;

	switch (levelNo)
	{
	case 1:
		plantDefaultStatus[EntityID::SNOWPEA] = PlantStatus::LOCKED;
		plantDefaultStatus[EntityID::WALLNUT] = PlantStatus::LOCKED;
		break;
	case 2:
		plantDefaultStatus[EntityID::SNOWPEA] = PlantStatus::LOCKED;
		break;
	default:
		break;
	}

	for (unsigned i = 0; i < ENEMIES_ID.size() - 1; i++)
		enemiesNo.push_back(ENEMIES_DEFAULT_NO[i] + levelNo / 2);
	enemiesNo.push_back(ENEMIES_DEFAULT_NO[ENEMIES_ID.size() - 1]); //SuperZombie

	wavesNo = levelNo;
	resourceRate = RESOURCE_DEFAULT_RATE - (levelNo / 2);
	resourceRate = (resourceRate < 1 ? 1 : resourceRate);
	pauseBetweenWaves = PAUSE_DEFAULT_TIME + 10 * (levelNo / 2 + 1);
}