#pragma once
#include "IDrawable.h";
#define LIMIT 169
class Proiectil : public IDrawable
{
public:
	Proiectil(int, int);
	int getY() const { return startY; }
	int getDamage() const { return damage; }
	void draw();
	~Proiectil();
	void executeFuncion();
private:
	int damage;
};

