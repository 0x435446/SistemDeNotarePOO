#pragma once
#include"Drowable.h"
class Plant :public Drowable
{
protected:
	unsigned atackSpeed, health, price;
	time_t nextThrow;
public:
	Plant(const unsigned&row, const unsigned&col, const std::string&shape, const unsigned &atackSpeed, const unsigned &health,const unsigned&price);
	unsigned getPrice() { return this->price; }
	virtual ~Plant() {}
	void printEntity() const override final;
	void clearEntity() const override final;
};

