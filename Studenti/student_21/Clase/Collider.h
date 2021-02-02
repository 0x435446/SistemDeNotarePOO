#pragma once
#include "Transform.h"
#include <list>
template <class Physical>
class Collider :
	public Component
{
	Physical& parent;
	const std::list<Physical*>& objectToCollideWith;
	const Transform& parentTransform;
public:
	Collider() = delete; 
	Collider(const Collider&) = delete;
	Collider& operator=(const Collider&) = delete;
	Collider(Physical& parent,
		const std::list<Physical*>& objectsToCollideWith,
		int updateReference) :
		Component(Component::Type::COLLIDER, updateReference),
		parent(parent),
		parentTransform(parent._transform()),
		objectToCollideWith(objectsToCollideWith) {}
	Collider(Physical& parent,
		const std::list<Physical*>& objectsToCollideWith,
		int updateReference,
		bool isRemovable) :
		Component(Component::Type::COLLIDER, updateReference, isRemovable),
		parent(parent),
		parentTransform(parent._transform()),
		objectToCollideWith(objectsToCollideWith) {}
	~Collider() {}

private:
	void Start() override final {}

	void Update() override final
	{
		checkCollision();
	}
	void End() override final {}


	void checkCollision()
	{
		for(Physical* i : objectToCollideWith)
		{
			if (!i->_is_dead())
			{
				if (check(parentTransform, i->_transform()))
					parent.onCollide(*i);
				if (parent._is_dead())
					break;
			}
		}
	}
	bool check(const Transform& hostTransform, const Transform& guestTransform) const
	{
		C2D::Vector2 hostPos = hostTransform.getPosition();
		C2D::Vector2 hostSize = hostTransform.getSize();
		C2D::Vector2 guestPos = guestTransform.getPosition();
		C2D::Vector2 guestSize = guestTransform.getSize();
		if (hostPos.getX() > guestPos.getX() + guestSize.getX())
			return false;
		if (hostPos.getY() > guestPos.getY() + hostSize.getY())
			return false;
		if (guestPos.getX() > hostPos.getX() + hostSize.getX())
			return false;
		if (guestPos.getY() > hostPos.getY() + guestSize.getY())
			return false;
		return true;
	}
};

