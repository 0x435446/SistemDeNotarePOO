#pragma once
#include "Entity.h"
class Plant : public Entity
{
public:
	Plant(const unsigned int&, const unsigned int&, char);
	void move() override;
	~Plant();
};

