#include "Mover.h"

Mover::Mover(Transform& transform,
	int speed,
	int direction) :
	Component(Component::Type::MOVER, speed, false),
	transform(transform),
	speed(speed),
	direction(direction) {}
Mover::Mover(Transform& transform,
	int speed,
	int direction,
	int isMovingVertically) :
	Component(Component::Type::MOVER, speed, false),
	transform(transform),
	speed(speed),
	direction(direction),
	_is_moving_vertically(isMovingVertically) {}
Mover::Mover(Transform& transform, 
	int speed, 
	int direction,
	const bool isRemovable) : 
	Component(Component::Type::MOVER, speed, isRemovable),
	transform(transform),
	speed(speed),
	direction(direction) {}
Mover::Mover(Transform& transform,
	int speed,
	int direction,
	int isMovingVertically,
	const bool isRemovable) :
	Component(Component::Type::MOVER, speed, isRemovable),
	transform(transform),
	speed(speed),
	direction(direction),
	_is_moving_vertically(isMovingVertically) {}
Mover::~Mover() {}


void Mover::StopMoving()
{
	isMoving = false;
}
void Mover::BeginMoving()
{
	isMoving = true;
}


void Mover::Update()
{
	if (isMoving)
		if (!_is_moving_vertically)
			move();
		else
			shift();
}
void Mover::Start()
{
	BeginMoving();
}
void Mover::End()
{
	StopMoving();
}

void Mover::move()
{
	C2D::Vector2 newPosition = transform.getPosition();
	newPosition.setX(transform.getPosition().getX() + 2 * direction - 1); //// JUST FOR TESTING, I'LL USE SPEED LATER
	transform.setPosition(newPosition);
}
void Mover::shift()
{
	C2D::Vector2 newPosition = transform.getPosition();
	newPosition.setY(transform.getPosition().getY() + 2 * direction - 1);  ////// NOT NEEDED RIGHT NOW
	transform.setPosition(newPosition);
}