#pragma once

#include <chrono>
#include <sstream>

#include "Exception.h"
#include "GUI.h"
#include "Logger.h"
#include "ISerializable.h"
#include "PlayerManager.h"
#include "Level.h"
#include "Resource.h"
#include "IDrawable.h"
#include "Damageable.h"
#include "IDamaging.h"
#include "IMoveable.h"

#include "Entity.h"
#include "Player.h"
#include "Sun.h"
#include "Tile.h"
#include "Wallnut.h"
#include "Sunflower.h"
#include "CherryBomb.h"
#include "Peashooter.h"
#include "SnowPea.h"
#include "Pea.h"
#include "FrozenPea.h"
#include "Explosion.h"
#include "Zombie.h"
#include "SuperZombie.h"
#include "Polevaulting.h"
#include "Buckethead.h"

namespace GameMechanics
{
	class GameManager :
		public ISerializable
	{
	private:
		GameManager();
		GameManager(GameManager&);
		~GameManager();

		static GameManager* instance;
		UserInterface::GUI& GUI;
		Debugging::Logger& logger;
		PlayerManager& playerManager;
		Player* currentPlayer;
		Level* level;
		GameStatus status;
		std::vector<int> toSpawnNo;
		std::vector<Enemy*> enemies;
		std::vector<Plant*> plants;
		std::vector<Projectile*> projectiles;
		std::vector<Resource*> resources;
		std::map<EntityID, PlantStatus> plantsStatus;

		std::chrono::time_point<std::chrono::steady_clock> timeAtLevelStart;
		unsigned currentScore;
		unsigned currentResources;
		int currentLevel;
		int currentWave;
		int timeElapsed;
		int timePaused;
		bool isPaused;
		bool isAPlantSelected;
		EntityID currentPlantSelection;
		std::vector<int> timeSinceLastSpawn;

		template<class T>
		void clearEntities(std::vector<T*>&);
		template<class T>
		void serializeVector(std::vector<T*>&, std::string&);

		void loginPlayer();
		void initialiseScene();
		void playGame();
		void updatePlayerInfo();
		void initialiseLevel();
		void endLevel();
		void initialiseWave();
		void clearTile(unsigned, unsigned);
		void displayEntity(UserInterface::IDrawable*);
		void calculateTimeElapsed();
		void updatePositions();
		void checkResourceSpawning();
		void checkEnemySpawning();
		void checkProjectileSpawning();
		void updatePlantStatuses();
		void checkMouseEvent();
		void checkIfPaused();
		void checkEndOfWave();
		void checkForCollisions();
		void checkForDeaths();

		std::string logSpawn(Entity*);
		std::string logDespawn(Entity*);

		void spawnResource(EntityID);
		void spawnEnemy(EntityID);
		void spawnPlant(int, int);

		void saveGame();
		void loadGame();

		std::string serialize() override;

		void deserializeEnemies(std::istringstream &s);
		void deserializePlants(std::istringstream &s);
		void deserializeResources(std::istringstream &s);
		void deserializeProjectiles(std::istringstream &s);


	public:
		static GameManager& getInstance();
		static void destroyInstance();

		void startGame();
	};

	template<class T>
	void GameManager::clearEntities(std::vector<T*>& v)
	{
		for (auto e : v)
		{
			clearTile(e->getRowUp(), e->getColLeft());
			delete e;
		}
		v.clear();
	}

	template<class T>
	void GameManager::serializeVector(std::vector<T*>& v, std::string &s)
	{
		s += std::to_string(v.size());
		s += "\n";
		for (auto el : v)
			s += el->serialize();
	}

}
