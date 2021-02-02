#include "Ground.h"
#include<iostream>
#include "Zombie_banal.h"
using namespace std;

Ground::Ground()
{
}

Ground::Ground(int a, int b) :x(a), y(b)
{
	for (int i = 0; i < 9; i++)
	{
		vect.push_back(new Zona(x,  y+i * 8));
	}
}

Ground::~Ground()
{
}

void Ground::set_position(int a, int b)
{
	x = a;
	y = b;
}

void Ground::draw()
{
	for (auto it : vect)
		it->draw();
}

void Ground::update(std::string action) 
{
	for (auto it : vect)
		it->update(action);
}
