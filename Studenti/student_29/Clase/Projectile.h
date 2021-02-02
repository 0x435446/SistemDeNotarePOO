#pragma once

class Projectile
{
protected:
	double dmg;
	int move_speed;
	int x;
	int y;
	char ch;

public:
	void move();
	int posX() const { return x; };
	int posY() const { return y; };
	double dealtDamage() const { return dmg; };
	Projectile(const int&, const int&, const char&);
	~Projectile();
};

