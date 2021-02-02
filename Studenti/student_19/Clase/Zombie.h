#pragma once
#include <iostream>
#include <chrono>
#include <time.h>
#include <Windows.h>
#include "ConsoleOutput.h"

#define ZombieHealth 5
#define BucketHeadZombieHealth 15
#define PoleVaultingZombieHealth 10
#define SuperZombieHealth 15
#define ZombieDamage 2
#define BucketHeadZombieDamage 3
#define PoleVaultingZombieDamage 4
#define SuperZombieDamage 5
#define ZombieSpeed 2000
#define BucketHeadZombieSpeed 2000
#define PoleVaultingZombieSpeed 2000
#define SuperZombieSpeed 1000

class Zombie
{
	int health;
	std::string name;
	int speed;
	int damage;
	int x;
	int y;
	int special_ability;
	std::chrono::steady_clock::time_point lastMovement;
public:
	Zombie();
	Zombie(const int health, const int speed, const int damage, const std::string name, const int x, const int y);
	Zombie(const int health, const int speed, const int damage, const std::string name, const int x, const int y, const int special_ability);
	bool testTime()
	{
		auto moveTime = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::milliseconds>(moveTime - lastMovement).count() > speed)
		{
			lastMovement = moveTime;
			return true;
		}
		return false;
	}
	void move();
	void takeDamage(const int damageValue);
	void modifyX(int value);
	const int getHealth() { return this->health; }
	const int getDamage() { return this->damage; }
	const std::string getName() { return this->name; }
	const int getSpeed() { return this->speed; }
	const int getX() { return this->x; }
	const int getY() { return this->y; }
	virtual const int getAbilityCharges();
	void decreaseCharges();
	void slowMovement(const int value);
	virtual ~Zombie();
};

