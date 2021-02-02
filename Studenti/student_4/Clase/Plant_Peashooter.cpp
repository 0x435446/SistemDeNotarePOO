#include "Plant_Peashooter.h"

Plant_Peashooter::Plant_Peashooter(int Dmg, int Hp, int Jump, std::string Name, int Speed):Entity(Dmg,Hp,Jump,Name,Speed)
{
}

Plant_Peashooter::~Plant_Peashooter()
{
	std::cout << "Destructor Shooter"<<std::endl;
}

void Plant_Peashooter::Set_Dmg(int Dmg)
{
	this->Dmg = Dmg;
}

void Plant_Peashooter::Set_Hp(int Hp)
{
	this->Hp = Hp;
}

void Plant_Peashooter::Set_Jump(int Jump)
{
	this->Jump = Jump;
}

void Plant_Peashooter::Set_Name(std::string Name)
{
	this->Name = Name;
}

void Plant_Peashooter::Set_Speed(int Speed)
{
	this->Speed = Speed;
}

int Plant_Peashooter::Get_Dmg()
{
	return this->Dmg;
}

int Plant_Peashooter::Get_Hp()
{
	return this->Hp;
}

int Plant_Peashooter::Get_Jump()
{
	return this->Jump;
}

std::string Plant_Peashooter::Get_Name()
{
	return this->Name;
}

int Plant_Peashooter::Get_Speed()
{
	return this->Speed;
}

void Plant_Peashooter::Fight(Entity& E)
{
	std::string Ground = "Ground";
	if(this->Get_Name()!=E.Get_Name() && E.Get_Name() != Ground)
	E.Set_Hp(E.Get_Hp() - this->Get_Dmg());
	//E.FightWith(*this);
}
