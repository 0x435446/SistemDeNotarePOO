#pragma once
class Zombie
{
protected:
	int viteza;
	int rezistenta;
public:
	Zombie(int, int);
	~Zombie();

	int get_rezistenta() { return this->rezistenta; }
};

