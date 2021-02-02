#pragma once
#include"CField.h"

using namespace UserInterface;
class IPlant
{
public:
	IPlant() { ; }
	IPlant(int difficulty, UserInterface::CField& game, int line, int column, char type) { ; }
	virtual ~IPlant() { ; }
	virtual void destroyPlant(int line, int column, UserInterface::CField& game)=0;
	virtual void taking_damage(int damage, UserInterface::CField& game)=0;
	virtual void shoot(UserInterface::CField& game) = 0;
	virtual int get_line() = 0;
	virtual int get_column() = 0;
	virtual int get_damage() = 0;
	virtual char get_type() = 0;
};

