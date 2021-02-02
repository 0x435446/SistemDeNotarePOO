#pragma once
#include "Transform.h"
class Mover :
	public Component
{
	Transform& transform;
	int speed;
	int direction;
	bool isMoving = true;
	int _is_moving_vertically = false;
public:
	Mover() = delete;
	Mover(const Mover&) = delete;
	Mover& operator=(const Mover&) = delete;
	Mover(Transform& transform, int speed, int direction);
	Mover(Transform& transform, int speed, int direction, int isMovingVertically);
	Mover(Transform& transform, int speed, int direction, const bool isRemovable);
	Mover(Transform& transform, int speed, int direction, int isMovingVertically, const bool isRemovable);
	~Mover();


	void StopMoving();
	void BeginMoving();


private:
	void Update() override final;
	void Start() override final;
	void End() override final;

	void move();
	void shift();
};

