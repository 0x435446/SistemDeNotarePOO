#pragma once
#include <string>
#include "Flower.h"


class Peashooter : public Flower {
private:
	int damage;

public:
	pair<int, int> attack_pos;
	Peashooter(int, string, char, int, int, int, int, int);
	~Peashooter() = default;

	void action();
};