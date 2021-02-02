#include "Transform.h"
Transform::Transform(int X, int Y, 
	int Width, int Height) : 
	Component(Component::Type::TRANSFORM, 1), 
	position(X, Y), size(Width, Height) {}
Transform::Transform(C2D::Vector2 position, 
	C2D::Vector2 size) : 
	Component(Component::Type::TRANSFORM, 1), 
	position(position), size(size) {}
Transform::Transform(int X, int Y, 
	int Width, int Height,
	const bool isRemovable) : 
	Component(Component::Type::TRANSFORM, 1, isRemovable), 
	position(X, Y), size(Width, Height) {}
Transform::Transform(C2D::Vector2 position, 
	C2D::Vector2 size,
	const bool isRemovable) :
	Component(Component::Type::TRANSFORM, 1, isRemovable), 
	position(position), size(size) {}
Transform::~Transform() {}

void Transform::Start() {}
void Transform::Update() {}
void Transform::End() {}

const C2D::Vector2& Transform::getPosition() const
{
	return position;
}

const C2D::Vector2& Transform::getSize() const
{
	return size;
}

void Transform::setPosition(C2D::Vector2& newPosition)
{
	position.setXY(newPosition);
}
void Transform::setPosition(int X, int Y)
{
	position.setX(X);
	position.setY(Y);
}