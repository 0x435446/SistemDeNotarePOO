#include "Plant_Wall_nut.h"

Plant_Wall_nut::Plant_Wall_nut(int Dmg, int Hp, int Jump, std::string Name, int Speed) :Entity(0, Hp, Jump, Name, Speed)
{
}

Plant_Wall_nut::~Plant_Wall_nut()
{
	std::cout << "Destructor Wall-nut" << std::endl;
}

void Plant_Wall_nut::Set_Dmg(int Dmg)
{
	this->Dmg = Dmg;
}

void Plant_Wall_nut::Set_Hp(int Hp)
{
	this->Hp = Hp;
}

void Plant_Wall_nut::Set_Jump(int Jump)
{
	this->Jump = Jump;
}

void Plant_Wall_nut::Set_Name(std::string Name)
{
	this->Name = Name;
}

void Plant_Wall_nut::Set_Speed(int Speed)
{
	this->Speed = Speed;
}

int Plant_Wall_nut::Get_Dmg()
{
	return 0;
}

int Plant_Wall_nut::Get_Hp()
{
	return this->Hp;
}

int Plant_Wall_nut::Get_Jump()
{
	return this->Jump;
}

std::string Plant_Wall_nut::Get_Name()
{
	return this->Name;
}

int Plant_Wall_nut::Get_Speed()
{
	return this->Speed;
}

void Plant_Wall_nut::Fight(Entity& E)
{
	std::string Ground = "Ground";
	if (this->Get_Name() != E.Get_Name() && E.Get_Name() != Ground)
		E.Set_Hp(E.Get_Hp() - this->Get_Dmg());
	//E.FightWith(*this);
}

