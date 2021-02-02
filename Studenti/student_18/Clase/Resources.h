#pragma once
#include"Drowable.h"
class Resources :public Drowable
{
protected:
	unsigned reward;
public:
	Resources(const unsigned& row, const unsigned& col, const std::string& shape, const unsigned& reward);
	virtual ~Resources() {}
	unsigned getReward() { return this->reward; }
	void printEntity()const;
	void clearEntity()const;
};