#pragma once
#include <iostream>
#include <chrono>
#include <time.h>
#include <Windows.h>

#define CherryBombDamage 10
#define PeaShooterDamage 1
#define FronzenPeaShooterDamage 2
#define CherryBombHealth 1
#define WallNutHealth 10
#define PeaShooterHealth 3
#define FrozenPeaShooterHealth 4
#define SunFlowerHealth 1
#define PeaShooterTime 3000
#define FrozenPeaShooterTime 2000


class Plants
{
	int health;
	std::string name;
	int x;
	int y;
	int shootTime;
	std::chrono::steady_clock::time_point lastShot;
public:
	Plants();
	Plants(const int health, const std::string name);
	Plants(const int health, const std::string name, const int shootTime);
	void setXY(const int x, const int y);
	bool testTime()
	{
		auto shotTime = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::milliseconds>(shotTime - lastShot).count() > shootTime)
		{
			lastShot = shotTime;
			return true;
		}
		return false;
	}
	virtual const int getDamage();
	void takeDamage(const int damageValue);
	const std::string getName() { return this->name; }
	const int getHealth() { return this->health; }
	const int getX() { return this->x; }
	const int getY() { return this->y; }
	virtual ~Plants();
};

