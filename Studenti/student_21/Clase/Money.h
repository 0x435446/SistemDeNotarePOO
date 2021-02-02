#pragma once
#include "CollectableObject.h"
#include "UserData.h"
class Money :
	public CollectableObject<int>
{
public:
	Money(std::list<InteractableObject*>& groupBoundTo,
		std::string sprite_file,
		C2D::Vector2 position,
		int amount) :
		CollectableObject(groupBoundTo, sprite_file, position, amount, UserData::_getCurrencyAccess()) {}
	Money() = delete;
	Money(const Money&) = delete;
	Money& operator= (const Money&) = delete;
	virtual ~Money() {}
	void Start() override {
		GameObject::Start();
	}
	void Update() override {
		GameObject::Update();
		if (_transform().getPosition().getY() > 42)
			_mark_for_death();
	}
	void End() override {

	}

	void onMouseClick() override final
	{
		CollectableObject::onMouseClick();
	}

	void tryReset() override {}
	void onClickOutOfRange() override {}
};

