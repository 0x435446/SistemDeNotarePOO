#include "Sun.h"
#include "BattleField.h"

Sun::Sun(const int x, const int y)
{
	this->SetType(SunType);
	this->SetValue(SUN_VALUE);
	this->SetPosition(x, y);
	BattleField* battlefield = BattleField::GetInstance();
	if (!battlefield->SomethingOnBattleField(x, y))
	{
		battlefield->CreateOnBattleField(SN, x, y);
		battlefield->AddOnResourcesList(this);
	}
}

Sun::~Sun()
{
}