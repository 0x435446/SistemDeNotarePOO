#pragma once
class Sun
{
	int money;
	int x; 
	int y;
public:
	Sun();
	Sun(const int x, const int y);
	const int getMoney() { return this->money; }
	const int getX() { return this->x; }
	const int getY() { return this->y; }
	~Sun();
};

