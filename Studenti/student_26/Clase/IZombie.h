#pragma once
class Panel;
class Plant;
class IZombie
{
public:
	virtual void Move(Panel&) = 0;
	virtual void Attack(Panel&, Plant&) = 0;
};

