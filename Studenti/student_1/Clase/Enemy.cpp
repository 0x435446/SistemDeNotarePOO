#include "Enemy.h"

using namespace GameMechanics;

Enemy::Enemy(int rowUp, int colLeft) : Entity(rowUp, colLeft)
{
	effect = EffectInflicted::NONE;
	timeInflicted = 0;
}


Enemy::~Enemy()
{
}

void GameMechanics::Enemy::move()
{
	if (isColliding)
		return;
	switch (effect)
	{
	case EffectInflicted::NONE:
	{
		this->colLeft--;
		break;
	}
	case EffectInflicted::FROZEN:
	{
		if (timeInflicted % 2 == 0) //moving with half the speed
			this->colLeft --;
		timeInflicted++;
		if (timeInflicted > EFFECT_TIME)
		{
			effect = EffectInflicted::NONE;
			timeInflicted = 0;
		}
	}
	default:
		break;
	}
}

void GameMechanics::Enemy::receiveEffect(EffectInflicted e)
{
	if (e == EffectInflicted::NONE)
		return;
	effect = e;
	timeInflicted = 0;
}

void GameMechanics::Enemy::setTimeInflicted(int t)
{
	timeInflicted = t;
}

int GameMechanics::Enemy::getPoints()
{
	return points;
}
