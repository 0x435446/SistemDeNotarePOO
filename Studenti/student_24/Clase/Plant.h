#pragma once
#include "Entity.h"
class Plant : public Entity
{
	
public:
	virtual void ability() = 0;
	Plant();
	virtual void set(int price, int resistance, int grow_time)=0;
	virtual void draw() = 0;
	virtual void uppdate(std::string) = 0;
	~Plant();
	
};

