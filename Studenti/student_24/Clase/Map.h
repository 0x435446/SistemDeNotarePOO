#pragma once
#include "Entity.h"
#include "Parcela.h"
#include "Shop.h"
#include <vector>
#include "Time.h"
#include "Zombie.h"
class Map : public Entity
{
private :
	int x, y;
	Time t;
	std::vector<Parcela*> teren;

public:
	static std::vector<Zombie*>zombie;
	void set(int, int);
	void create_zombie(std::string);
	void plantare(std::string action);
	Map();
	void fight();
	~Map();
	void draw();
	void uppdate(std::string);
};

