#include "Zm_PoleVaulting.h"


Zm_PoleVaulting::Zm_PoleVaulting(int Dmg, int Hp, int Jump, std::string Name, int Speed) :Entity(Dmg, Hp, Jump, Name, Speed)
{
}

Zm_PoleVaulting::~Zm_PoleVaulting()
{
	std::cout << "Destructor PoleVaulting" << std::endl;
}

void Zm_PoleVaulting::Set_Dmg(int Dmg)
{
	this->Dmg = Dmg;
}

void Zm_PoleVaulting::Set_Hp(int Hp)
{
	this->Hp = Hp;
}

void Zm_PoleVaulting::Set_Jump(int Jump)
{
	this->Jump = Jump;
}

void Zm_PoleVaulting::Set_Name(std::string Name)
{
	this->Name = Name;
}

void Zm_PoleVaulting::Set_Speed(int Speed)
{
	this->Speed = Speed;
}

int Zm_PoleVaulting::Get_Dmg()
{
	return this->Dmg;
}

int Zm_PoleVaulting::Get_Hp()
{
	return this->Hp;
}

int Zm_PoleVaulting::Get_Jump()
{
	return this->Jump;
}

std::string Zm_PoleVaulting::Get_Name()
{
	return this->Name;
}

int Zm_PoleVaulting::Get_Speed()
{
	return this->Speed;
}

void Zm_PoleVaulting::Fight(Entity& E)
{
	std::string Ground = "Ground";
	if (this->Get_Name() != E.Get_Name() && E.Get_Name() != Ground)
		E.Set_Hp(E.Get_Hp() - this->Get_Dmg());
	//E.FightWith(*this);
}