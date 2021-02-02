#pragma once
class Panel;
class Zombie;
class IPlant
{
public:
	//Every Plant Has A Shoot And An Ability
	virtual void Shoot(Panel&, Zombie&) = 0;
	virtual void Ability(Panel&) = 0;
};

