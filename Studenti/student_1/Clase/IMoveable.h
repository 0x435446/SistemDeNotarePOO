#pragma once

namespace GameMechanics
{
	class IMoveable
	{
	protected:
		unsigned speed;
		bool isColliding;

	public:
		IMoveable();
		virtual ~IMoveable();

		virtual void move() = 0;
		unsigned getSpeed();
		void setColliding(bool);
		bool getColliding();
	};
}
