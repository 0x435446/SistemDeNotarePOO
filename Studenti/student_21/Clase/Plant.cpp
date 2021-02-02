#include "Plant.h"
Plant::Plant(std::list<Physical*>& groupBoundTo,
	std::string sprite_file,
	C2D::Vector2 position,
	std::list<Physical*>& everyLifeFormObject,
	int healthPoints,
	int baseHpRegen) :
	LifeForm(groupBoundTo, sprite_file, position, everyLifeFormObject, healthPoints, baseHpRegen, 1)
{

}
Plant::Plant(std::list<Physical*>& groupBoundTo,
	std::string sprite_file,
	C2D::Vector2 position,
	std::list<Physical*>& everyLifeFormObject,
	int healthPoints) :
	LifeForm(groupBoundTo, sprite_file, position, everyLifeFormObject, healthPoints, 1)
{

}

void Plant::onCollide(Physical& physicalObject)
{
	///// it actually does nothing but we might add zombie eater ;)
}

void Plant::Start()
{
	GameObject::Start();
}
void Plant::Update()
{
	GameObject::Update();
}
void Plant::End()
{

}