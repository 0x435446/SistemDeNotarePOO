#include "Zm_BucketHead.h"

Zm_BucketHead::Zm_BucketHead(int Dmg, int Hp, int Jump, std::string Name, int Speed):Entity(Dmg,Hp,Jump,Name,Speed)
{
}

Zm_BucketHead::~Zm_BucketHead()
{
	std::cout << "Destructor BucketHead" << std::endl;
}

void Zm_BucketHead::Set_Dmg(int Dmg)
{
	this->Dmg = Dmg;
}

void Zm_BucketHead::Set_Hp(int Hp)
{
	this->Hp = Hp;
}

void Zm_BucketHead::Set_Jump(int Jump)
{
	this->Jump = Jump;
}

void Zm_BucketHead::Set_Name(std::string Name)
{
	this->Name = Name;
}

void Zm_BucketHead::Set_Speed(int Speed)
{
	this->Speed = Speed;
}

int Zm_BucketHead::Get_Dmg()
{
	return this->Dmg;
}

int Zm_BucketHead::Get_Hp()
{
	return this->Hp;
}

int Zm_BucketHead::Get_Jump()
{
	return this->Jump;
}

std::string Zm_BucketHead::Get_Name()
{
	return this->Name;
}

int Zm_BucketHead::Get_Speed()
{
	return this->Speed;
}

void Zm_BucketHead::Fight(Entity& E)
{
	std::string Ground = "Ground";
	if (this->Get_Name() != E.Get_Name() && E.Get_Name() != Ground)
		E.Set_Hp(E.Get_Hp() - this->Get_Dmg());
}
