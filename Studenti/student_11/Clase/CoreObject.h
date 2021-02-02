#pragma once
class CoreObject
{
	public:
		virtual void setPosition(int x, int y) = 0;
	protected:
		int health;
		int cost;
		int dmg=25;
		int value;
};

