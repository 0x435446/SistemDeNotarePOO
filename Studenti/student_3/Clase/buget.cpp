#include "buget.h"

buget *buget::valoare = nullptr;

buget& buget::operator= (const buget& C)
{
	if (this != &C)
	{
		this->bani = C.bani;
	}
	return *this;
}

buget & buget::getBuget()
{
	if (valoare == nullptr)
	{
		valoare = new buget;
	}
	return *valoare;
}

void buget::setBani(int i)
{
	this->bani = i;
}

int buget::getBani()
{
	if (this->valoare != nullptr)
		return this->bani;
	else
		throw 101;
}

buget buget::operator+ (int k)
{
	int result = bani + k;
	this->bani = result;
	return buget::getBuget();
}

void buget::addBani(int i)
{
	this->bani = this->bani + i;
}


