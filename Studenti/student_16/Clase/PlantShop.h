#pragma once
#include "IDrawable.h"
#include "Avatar.h"
#include "AvatarTile.h"
#include <stdlib.h>
class PlantShop :public IDrawable
{
public:
	static PlantShop& getInstance();
	~PlantShop() { ; }
	void draw();
	void executeFunction();
	int getAvatarIndex(vector<int>);
	std::string getAvatarName(int index) { return tiles[index]->getAvatar()->getName(); }
	int getAvatarCost(int index);
	void removeAvatar(int);
private:
	int delaySunflower;
	int delayPeaShooter;
	int delayWallNut;
	int delayCherryBomb;
	static PlantShop* instance;
	std::vector<AvatarTile*> tiles;
	PlantShop();
	steady_clock::time_point genSunflower;
	steady_clock::time_point genPeaShooter;
	steady_clock::time_point genWallNut;
	steady_clock::time_point genCherryBomb;
};

