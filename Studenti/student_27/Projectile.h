#pragma once
#include<iostream>

using namespace std;
class Projectile
{
private:
	char Symbol;

	int xPos;
	int yPos;

	int Damage;
public:
	Projectile();
	~Projectile();

	Projectile(char symbol);

	Projectile(char symbol, int x, int y,int damage);

	char GetSymbol();

	int GetxPos();

	int GetyPos();

	void SetyPos();

	void SetyPos(int y);

	int GetDamage();
};

