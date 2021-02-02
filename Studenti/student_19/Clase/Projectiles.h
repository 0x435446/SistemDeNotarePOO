#pragma once
#include <iostream>
#include "ConsoleOutput.h"
#include <Windows.h>
#include "Plants.h"
#include <conio.h>
#include <chrono>

#define DamagePeaProjectile 1
#define DamageFrozenPeaProjectile 2
#define FrozenPeaValueAbility 250
#define PeaProjectileFrequency 500
#define FrozenPeaProjectileFrequency 500

class Projectiles 
{
	int x; 
	int y;
	int damage;
	int frequency;
	std::chrono::steady_clock::time_point lastShot;
	int ability;
public:
	Projectiles();
	Projectiles(const int x, const int y, const int damage, const int frequency, const int ability);
	void modifyX(const int value) { this->x += value; }
	void move();
	bool testTime()
	{
		auto shotTime = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::milliseconds>(shotTime - lastShot).count() > this->frequency)
		{
			lastShot = shotTime;
			return true;
		}
		return false;
	}
	const int getX() { return this->x; }
	const int getY() { return this->y; }
	const int getDamage() { return this->damage; }
	const int getFrequency() { return this->frequency; }
	const int getAbility() { return this->ability; }
	~Projectiles();
};

