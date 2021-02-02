#include "Zm_Super.h"

Zm_Super::Zm_Super(int Dmg, int Hp, int Jump, std::string Name, int Speed) :Entity(Dmg,Hp,Jump,Name,Speed),Zm_PoleVaulting(Dmg, Hp, Jump, Name, Speed),Zm_BucketHead(Dmg,Hp,Jump,Name,Speed)
{
}

Zm_Super::~Zm_Super()
{
	std::cout << "Destructor Superc" << std::endl;
}

void Zm_Super::Set_Dmg(int Dmg)
{
	this->Dmg = Dmg;
}

void Zm_Super::Set_Hp(int Hp)
{
	this->Hp = Hp;
}

void Zm_Super::Set_Jump(int Jump)
{
	this->Jump = Jump;
}

void Zm_Super::Set_Name(std::string Name)
{
	this->Name = Name;
}

void Zm_Super::Set_Speed(int Speed)
{
	this->Speed = Speed;
}

int Zm_Super::Get_Dmg()
{
	return this->Dmg;
}

int Zm_Super::Get_Hp()
{
	return this->Hp;
}

int Zm_Super::Get_Jump()
{
	return this->Jump;
}

std::string Zm_Super::Get_Name()
{
	return this->Name;
}

int Zm_Super::Get_Speed()
{
	return this->Speed;
}

void Zm_Super::Fight(Entity& E)
{
	std::string Ground = "Ground";
	if (this->Get_Name() != E.Get_Name() && E.Get_Name() != Ground)
		E.Set_Hp(E.Get_Hp() - this->Get_Dmg());
	//E.FightWith(*this);
}