#include "Plant_Snow_Pea.h"


Plant_Snow_Pea::Plant_Snow_Pea(int Dmg, int Hp, int Jump, std::string Name, int Speed) :Entity(Dmg, Hp, Jump, Name, Speed)
{
}

Plant_Snow_Pea::~Plant_Snow_Pea()
{
	std::cout << "Destructor Snow_Shooter" << std::endl;
}

void Plant_Snow_Pea::Set_Dmg(int Dmg)
{
	this->Dmg = Dmg;
}

void Plant_Snow_Pea::Set_Hp(int Hp)
{
	this->Hp = Hp;
}

void Plant_Snow_Pea::Set_Jump(int Jump)
{
	this->Jump = Jump;
}

void Plant_Snow_Pea::Set_Name(std::string Name)
{
	this->Name = Name;
}

void Plant_Snow_Pea::Set_Speed(int Speed)
{
	this->Speed = Speed;
}

int Plant_Snow_Pea::Get_Dmg()
{
	return this->Dmg;
}

int Plant_Snow_Pea::Get_Hp()
{
	return this->Hp;
}

int Plant_Snow_Pea::Get_Jump()
{
	return this->Jump;
}

std::string Plant_Snow_Pea::Get_Name()
{
	return this->Name;
}

int Plant_Snow_Pea::Get_Speed()
{
	return this->Speed;
}

void Plant_Snow_Pea::Fight(Entity& E)
{
	std::string Ground = "Ground";
	if (this->Get_Name() != E.Get_Name() && E.Get_Name() != Ground) {
		E.Set_Hp(E.Get_Hp() - this->Get_Dmg());
		if (E.Get_Speed() > 1)
			E.Set_Speed(1);
	}
	//E.FightWith(*this);
}
