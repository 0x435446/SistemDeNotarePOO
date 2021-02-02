#include "DisplayableEntity.h"

DisplayableEntity::DisplayableEntity() : m_x(0), m_y(0), m_speed(0), m_moving(false), m_direction(RIGHT)
{
}

DisplayableEntity::~DisplayableEntity()
{
}

int DisplayableEntity::GetX() const
{
	return this->m_x;
}

int DisplayableEntity::GetY() const
{
	return this->m_y;
}

int DisplayableEntity::GetSpeed() const
{
	return this->m_speed;
}

bool DisplayableEntity::GetMoving() const
{
	return this->m_moving;
}

bool DisplayableEntity::GetDirection() const
{
	return this->m_direction;
}

void DisplayableEntity::SetPosition(const int x, const int y)
{
	this->m_x = x;
	this->m_y = y;
}

void DisplayableEntity::SetSpeed(const int speed)
{
	this->m_speed = speed;
}

void DisplayableEntity::SetMoving(const bool moving)
{
	this->m_moving = moving;
}

void DisplayableEntity::SetDirection(const bool direction)
{
	this->m_direction = direction;
}