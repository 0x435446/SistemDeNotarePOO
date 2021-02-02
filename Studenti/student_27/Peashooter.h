#pragma once
#include "Plant.h"
#include "Projectile.h"

#include<thread>

using namespace std;
class Peashooter :
	public Plant
{
private:
	Projectile* projectil;

	bool shoot;


public:
	Peashooter();
	~Peashooter();
	Peashooter(char symbol, int cost, int x, int y);

	Peashooter(char symbol, int cost, int x, int y, Projectile* project);

	int CheckForPeaShooter(int x, int y);

	void Shoot();

	int GetxPos();

	int GetyPos();

	char GetSymbol();

	Projectile* GetProjectile();

};

