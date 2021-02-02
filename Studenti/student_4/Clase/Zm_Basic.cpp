#include "Zm_Basic.h"

Zm_Basic::Zm_Basic(int Dmg, int Hp, int Jump, std::string Name,  int Speed):Entity(Dmg,Hp,Jump,Name,Speed)
{
}

Zm_Basic::~Zm_Basic()
{
	std::cout << "Destructor Basic" << std::endl;
}

void Zm_Basic::Set_Dmg(int Dmg)
{
	this->Dmg = Dmg;
}

void Zm_Basic::Set_Hp(int Hp)
{
	this->Hp = Hp;
}

void Zm_Basic::Set_Jump(int Jump)
{
	this->Jump = Jump;
}

void Zm_Basic::Set_Name(std::string Name)
{
	this->Name = Name;
}

void Zm_Basic::Set_Speed(int Speed)
{
	this->Speed = Speed;
}

int Zm_Basic::Get_Dmg()
{
	return this->Dmg;
}

int Zm_Basic::Get_Hp()
{
	return this->Hp;
}

int Zm_Basic::Get_Jump()
{
	return this->Jump;
}

std::string Zm_Basic::Get_Name()
{
	return this->Name;
}

int Zm_Basic::Get_Speed()
{
	return this->Speed;
}

void Zm_Basic::Fight(Entity& E)
{
	std::string Ground = "Ground";
	if(this->Get_Name()!=E.Get_Name() && E.Get_Name()!=Ground)
	E.Set_Hp(E.Get_Hp() - this->Get_Dmg());
	//E.FightWith(*this);
}
