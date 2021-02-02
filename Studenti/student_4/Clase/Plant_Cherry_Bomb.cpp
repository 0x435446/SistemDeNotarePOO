#include "Plant_Cherry_Bomb.h"


Plant_Cherry_Bomb::Plant_Cherry_Bomb(int Dmg, int Hp, int Jump, std::string Name, int Speed) :Entity(Dmg, Hp, Jump, Name, Speed)
{
}

Plant_Cherry_Bomb::~Plant_Cherry_Bomb()
{
	std::cout << "Destructor Cherry_Bomb" << std::endl;
}

void Plant_Cherry_Bomb::Set_Dmg(int Dmg)
{
	this->Dmg = Dmg;
}

void Plant_Cherry_Bomb::Set_Hp(int Hp)
{
	this->Hp = Hp;
}

void Plant_Cherry_Bomb::Set_Jump(int Jump)
{
	this->Jump = Jump;
}

void Plant_Cherry_Bomb::Set_Name(std::string Name)
{
	this->Name = Name;
}

void Plant_Cherry_Bomb::Set_Speed(int Speed)
{
	this->Speed = Speed;
}

int Plant_Cherry_Bomb::Get_Dmg()
{
	return this->Dmg;
}

int Plant_Cherry_Bomb::Get_Hp()
{
	return this->Hp;
}

int Plant_Cherry_Bomb::Get_Jump()
{
	return this->Jump;
}

std::string Plant_Cherry_Bomb::Get_Name()
{
	return this->Name;
}

int Plant_Cherry_Bomb::Get_Speed()
{
	return this->Speed;
}

void Plant_Cherry_Bomb::Fight(Entity& E)
{
	std::string Ground = "Ground";
	if (this->Get_Name() != E.Get_Name() && E.Get_Name() != Ground) {
		E.Set_Hp(E.Get_Hp() - this->Get_Dmg());
		this->Set_Hp(0);
	}
	//E.FightWith(*this);
}

