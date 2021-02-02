#pragma once
#include "IDrawable.h"
#include "BattleTile.h"
#include "Zombie.h"
#include "PoleVaultingZombie.h"
#include "BucketHeadZombie.h"
class BattleLine :public IDrawable
{
public:
	BattleLine(int, int);
	~BattleLine() { ; }
	int pressedOnTile(int, int);
	bool addPlant(int, Plant*);
	bool getSuns(int x, int y);
	int getLife() { return life; }
	void addZombie(std::string);
	void drawHeart();
	int executeFunction();
	void draw();
private:
	vector<BattleTile*> plantTiles;
	vector<Zombie*> enemies;
	int life = 2;
};

