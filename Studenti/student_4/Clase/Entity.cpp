#include "Entity.h"

Entity::Entity(int Dmg, int Hp, int Jump,std::string Name, int Speed)
{
	this->Dmg = Dmg;
	this->Hp = Hp;
	this->Jump = Jump;
	this->Name = Name;
	this->Speed = Speed;
}

Entity::~Entity()
{
	std::cout << "Destruct Entity" << std::endl;
}
