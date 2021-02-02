#include "NormalZombie.h"
#include"BattleField.h"

NormalZombie::NormalZombie(const int x, const int y)
{
	this->SetType(NormalZombieType);
	this->SetPosition(x, y);
	BattleField* battlefield = BattleField::GetInstance();
	if (!battlefield->SomethingOnBattleField(x, y))
	{
		battlefield->CreateOnBattleField(NZ, x, y);
		battlefield->AddOnZombiesList(this);
	}
}

NormalZombie::~NormalZombie()
{
}