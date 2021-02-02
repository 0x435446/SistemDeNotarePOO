#pragma once
#include <vector>
#include "Sunflower.h"
#include "PeaShooter.h"
#include "WallNut.h"
#include "NormalZombie.h"
#include "BucketHead.h"
#include "Map.h"
class EntityManager
{
public:
	EntityManager();

private:
	std::vector<Sunflower*> sunflowers;
	std::vector<PeaShooter*> peashooter;
	std::vector<WallNut*> wallnut;
	std::vector<NormalZombie*> zombie;
	std::vector<BucketHead*> buckethead;
};

