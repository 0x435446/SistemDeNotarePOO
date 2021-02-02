#include "Zombie.h"
Zombie::Zombie(std::list<Physical*>& groupBoundTo,
	std::string sprite_file,
	C2D::Vector2 position,
	const std::list<Physical*>& everyLifeFormObject,
	std::list<InteractableObject*>& pCurrency,
	int damage,
	int speed,
	int direction,
	int healthPoints,
	int baseHpRegen) :
	LifeForm(groupBoundTo, sprite_file, position, everyLifeFormObject, healthPoints, baseHpRegen, speed),
	MoveableObject(_transform(), speed, direction),
	damage(damage),
	pCurrency(pCurrency) {}
Zombie::Zombie(std::list<Physical*>& groupBoundTo,
	std::string sprite_file,
	C2D::Vector2 position,
	const std::list<Physical*>& everyLifeFormObject,
	std::list<InteractableObject*>& pCurrency,
	int damage,
	int speed,
	int direction,
	int healthPoints) :
	LifeForm(groupBoundTo, sprite_file, position, everyLifeFormObject, healthPoints, speed),
	MoveableObject(_transform(), speed, direction),
	damage(damage),
	pCurrency(pCurrency) {}

void Zombie::do_damage(LifeForm& lifeForm)
{
	lifeForm.takeDamage(damage);
}


void Zombie::Start()
{
	BeginMoving();
	GameObject::Start();
	C2D::Vector2 newPos = _transform().getPosition();
	newPos.snapToGrid();
	_transform().setPosition(newPos);
}
void Zombie::Update()
{
	if (_transform().getPosition().getX() <= 15)
		_mark_for_death();
	BeginMoving();
	GameObject::Update();
}
void Zombie::End() {}

void Zombie::onCollide(Physical& physicalObject)
{
	StopMoving();
	if (physicalObject.getType() == Physical::Type::LIFEFORM) /// meh
	{
		do_damage(dynamic_cast<LifeForm&>(physicalObject));
	}
}