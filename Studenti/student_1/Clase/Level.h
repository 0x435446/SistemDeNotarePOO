#pragma once

#include "GameSpecifications.h"

namespace GameMechanics
{
	class Level
	{
	private:
		int levelNo;
		int wavesNo;
		int lanesNo;
		std::vector<int> enemiesNo;
		int resourceRate;
		int pauseBetweenWaves;
		std::map<EntityID, PlantStatus> plantDefaultStatus;
		bool spawnedSuper;

		void levelGenerator(int);

	public:
		Level(int);
		~Level();

		friend class GameManager;
	};
}