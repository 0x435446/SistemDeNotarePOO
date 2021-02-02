#include "Plant_Sunflower.h"


Plant_Sunflower::Plant_Sunflower(int Dmg, int Hp, int Jump, std::string Name, int Speed) :Entity(Dmg, Hp, Jump, Name, Speed)
{
}

Plant_Sunflower::~Plant_Sunflower()
{
	std::cout << "Destructor Sunflower" << std::endl;
}

void Plant_Sunflower::Set_Dmg(int Dmg)
{
	this->Dmg = Dmg;
}

void Plant_Sunflower::Set_Hp(int Hp)
{
	this->Hp = Hp;
}

void Plant_Sunflower::Set_Jump(int Jump)
{
	this->Jump = Jump;
}

void Plant_Sunflower::Set_Name(std::string Name)
{
	this->Name = Name;
}

void Plant_Sunflower::Set_Speed(int Speed)
{
	this->Speed = Speed;
}

int Plant_Sunflower::Get_Dmg()
{
	return this->Dmg;
}

int Plant_Sunflower::Get_Hp()
{
	return this->Hp;
}

int Plant_Sunflower::Get_Jump()
{
	return this->Jump;
}

std::string Plant_Sunflower::Get_Name()
{
	return this->Name;
}

int Plant_Sunflower::Get_Speed()
{
	return this->Speed;
}

void Plant_Sunflower::Fight(Entity& E)
{
	std::string Ground = "Ground";
	if (this->Get_Name() != E.Get_Name() && E.Get_Name() != Ground)
		E.Set_Hp(E.Get_Hp() - this->Get_Dmg());
	//E.FightWith(*this);
}

