#pragma once
#include "CollectableObject.h"
#include "MoveableObject.h"
class Sun :
	public CollectableObject<int>,
	public MoveableObject
{
	int steps = 0;
	bool limitMove = false;
public:
	Sun(std::list<InteractableObject*>& groupBoundTo,
		std::string sprite_file,
		C2D::Vector2 position,
		int speed,
		int amount,
		int& inGameCurrency) :
		CollectableObject(groupBoundTo, sprite_file, position, amount, inGameCurrency),
		MoveableObject(_transform(), speed, 1, 1)
	{}
	Sun(std::list<InteractableObject*>& groupBoundTo,
		std::string sprite_file,
		C2D::Vector2 position,
		int speed,
		int steps,
		int amount,
		int& inGameCurrency) :
		CollectableObject(groupBoundTo, sprite_file, position, amount, inGameCurrency),
		MoveableObject(_transform(), speed, 1, 1),
		steps(steps),
		limitMove(true)
	{}
	Sun() = delete;
	Sun(const Sun&) = delete;
	Sun& operator= (const Sun&) = delete;
	virtual ~Sun() {}
	void Start() override {
		GameObject::Start();
	}
	void Update() override {
		if (limitMove)
		{
			--steps;
			if (steps == 0)
				RemoveComponent<Component::Type::MOVER>();
		}
		/*if (_fX || _fY)
		{
			auto set_next_point = [&]()
			{
				if (int(_fX) != int(_dX))
					_fX += _xDir * _ref_division;
				if (int(_fY) != int(_dY))
					_fY += _yDir;
			};
			set_next_point();
			if ((int)_fX == (int)_dX && (int)_fY == (int)_dY)
			{
				_mark_for_death();
			}
			_transform().setPosition(int(_fX), int(_fY));
		}*/
		GameObject::Update();
		if (_transform().getPosition().getY() > 42)
			_mark_for_death();
	}
	void End() override {

	}

	void onMouseClick() override final
	{
		CollectableObject::onMouseClick();
		//if (!_fX && !_fY)
		//{
		//	RemoveComponent < Component::Type::MOVER>();
		//	_fX = (float)_transform().getPosition().getX();
		//	_fY = (float)_transform().getPosition().getX();
		//	_xDir = _fX > _dX ? -1 : 1;
		//	_yDir = _fY > _dY ? -1 : 1;
		//	_ref_division = ((_fX - _dX) / (_fY - _dY)) * (_xDir * _yDir);
		//}
	}

	void tryReset() override {}
	void onClickOutOfRange() override {}
};

