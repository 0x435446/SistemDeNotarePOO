#pragma once
#include <iostream>
#include <vector>
class Entity
{
public:
	Entity();
	~Entity();
	virtual void draw() = 0;
	virtual void uppdate(std::string) = 0;



};

