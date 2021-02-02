#pragma once
#include <string>
#include "Flower.h"




class Sunflower : public Flower {

public:
	Sunflower(string, char, int, int, int, int, int);
	~Sunflower() = default;
	void action();
};