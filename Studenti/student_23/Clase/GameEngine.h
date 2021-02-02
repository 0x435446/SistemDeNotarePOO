#pragma once

#include "EntityManager.h"
#include "Projectile.h"
#include "Score.h"
#include "Players.h"
class GameEngine
{
public:
	static GameEngine& getInstance();
	static void destroyInstance();
	static void PlantVsZombies();

private:
	GameEngine();
	~GameEngine() {};

	static int level;
	static int money;
	static int nrSuns;
	static GameEngine *instance;
	static std::string gameInstance;
	static vector<Sunflower> sunflowers;
	static vector<PeaShooter> peashooters;
	static vector<WallNut> wallnuts;
	static vector<NormalZombie> zombies;
	static vector<BucketHead> bucketheads;
	static vector<Projectile> proiectile;
};

