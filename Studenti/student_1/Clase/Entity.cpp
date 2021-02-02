#include "Entity.h"
#include "GUI.h"

using namespace GameMechanics;

Entity::Entity(int rowUp, int colLeft): IDrawable(rowUp, colLeft)
{
}


Entity::~Entity()
{
}

void Entity::draw()
{
	UserInterface::GUI::getInstance().getSprite(this->ID)->show(rowUp, colLeft);
}

void Entity::draw(char overrideChar)
{
	UserInterface::GUI::getInstance().getSprite(this->ID)->show(rowUp, colLeft, overrideChar);
}

EntityID GameMechanics::Entity::getID()
{
	return ID;
}
