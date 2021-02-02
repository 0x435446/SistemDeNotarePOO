#pragma once
#include "GameObject.h"
#include "Mover.h"
class MoveableObject :
	virtual public GameObject
{
	Mover mover;
public:
	MoveableObject(Transform& transform, int speed, int direction);
	MoveableObject(Transform& transform, int speed, int direction, int _is_moving_vertically);
	MoveableObject() = delete;
	MoveableObject(const MoveableObject&) = delete;
	MoveableObject& operator= (const MoveableObject&) = delete;
	virtual ~MoveableObject() {}

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;

	void BeginMoving()
	{
		mover.BeginMoving();
	}
	void StopMoving()
	{
		mover.StopMoving();
	}
};

