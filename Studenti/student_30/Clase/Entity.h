#pragma once
#include<string>

class Entity
{
public:
	Entity();
	~Entity();

	virtual void draw() = 0;
	virtual void update(std::string) = 0;
};

