#pragma once
#include "Transform.h"
#include <list>
template <class ProjectileType, class Physical>
class Weapon :
	public Component
{
	const Transform& parentTransform;
	std::list<Physical*>& ProjectileList;
	std::list<Physical*>& zombieList;
	C2D::Vector2 position;
public:
	Weapon() = delete;
	Weapon(const Weapon&) = delete;
	Weapon& operator=(const Weapon&) = delete;
	Weapon(std::list<Physical*>& ProjectileList,
		const Transform& parentTransform,
		int attackSpeed,
		std::list<Physical*>& zombieList) :
		ProjectileList(ProjectileList),
		zombieList(zombieList),
		Component(Component::Type::WEAPON, attackSpeed),
		parentTransform(parentTransform),
		position(C2D::Vector2(0, 0)) {}
	Weapon(std::list<Physical*>& ProjectileList,
		const Transform& parentTransform,
		int attackSpeed,
		bool isRemovable,
		std::list<Physical*>& zombieList) :
		ProjectileList(ProjectileList),
		zombieList(zombieList),
		Component(Component::Type::WEAPON, attackSpeed, isRemovable),
		parentTransform(parentTransform),
		position(C2D::Vector2(0, 0)) {}
	~Weapon() {}

	void _set_position(C2D::Vector2 newPosition)
	{
		position.setXY(newPosition);
		Start();
	}

private:
	void Start() override final 
	{
		position.setX(parentTransform.getPosition().getX() + parentTransform.getSize().getX());
		position.setY(parentTransform.getPosition().getY() - parentTransform.getSize().getY() / 2 - 1); //// REWORK
	}

	void Update() override final
	{
		typename std::list<Physical*>::iterator prev;
		for (auto i = zombieList.begin(); i != zombieList.end();)
		{
			prev = i++;
			if (parentTransform.getPosition().getY() == (*prev)->_transform().getPosition().getY())
			{
				shoot();
				return;
			}
		}
	}
	void End() override final {}
private:
	void shoot()
	{
		ProjectileList.push_back(new ProjectileType(ProjectileList, position, zombieList));
	}
};

