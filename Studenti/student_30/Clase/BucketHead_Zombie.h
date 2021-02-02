#pragma once
#include "Zombie.h"
class BucketHead_Zombie :
	public Zombie
{
private:
	int rezistenta;
	int x, y;
	int viteza;
public:
	BucketHead_Zombie();
	BucketHead_Zombie(int a, int b);
	~BucketHead_Zombie();
	void update(std::string) {}
	void draw();
	void move();
	void set(int viteza, int rezistenta);
};

