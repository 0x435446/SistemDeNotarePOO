#pragma once
#include <chrono>
#include <thread>
#include "ConsoleOutput.h"
#include "BattleField.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();
	virtual const int get_health()const = 0;
	virtual const void print_entity()const = 0;
};

