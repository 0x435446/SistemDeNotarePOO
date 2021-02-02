#include "BucketHead_Zombie.h"



BucketHead_Zombie::BucketHead_Zombie()
{
}

BucketHead_Zombie::BucketHead_Zombie(int a, int b)
{
	x = a;
	y = b;
}

BucketHead_Zombie::~BucketHead_Zombie()
{
}

void BucketHead_Zombie::draw()
{
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	out(x, y - 1) << "**";
	out(x + 1, y - 1) << "(";
	out(x + 1, y) << "BZ";
	out(x + 1, y + 1) << ")";
}

void BucketHead_Zombie::move()
{
	UserInterface::ConsoleOutput out = UserInterface::ConsoleOutput::getInstance();
	out(x, y + 1) << " ";
	BucketHead_Zombie::draw();
	y--;
}

void BucketHead_Zombie::set(int viteza, int rezistenta)
{
	this->viteza = viteza;
	this->rezistenta = rezistenta;
}


