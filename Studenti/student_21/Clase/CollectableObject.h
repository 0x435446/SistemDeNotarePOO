#pragma once
#include "InteractableObject.h"
template <class myType>
class CollectableObject :
	public InteractableObject
{
	myType stuffToCollect;
	myType& whereToCollect;
public:
	CollectableObject(std::list<InteractableObject*>& groupBoundTo,
		std::string sprite_file,
		C2D::Vector2 position,
		myType stuffToCollect,
		myType& whereToCollect) :
		InteractableObject(groupBoundTo, sprite_file, position),
		stuffToCollect(stuffToCollect),
		whereToCollect(whereToCollect) {}
	CollectableObject() = delete;
	CollectableObject(const CollectableObject&) = delete;
	CollectableObject& operator= (const CollectableObject&) = delete;
	virtual ~CollectableObject() {}

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;

	virtual void onMouseHover() override
	{
	}
	virtual void onMouseClick() override
	{
		_collectThis();
	}
	virtual void onMouseDoubleClick() override {}
private:
	void _collectThis()
	{
		whereToCollect += stuffToCollect;
		_mark_for_death();
	}
};

