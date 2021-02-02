#include "BucketHeadZombie.h"
#include "BattleField.h"

BucketHeadZombie::BucketHeadZombie(const int x, const int y)
{
	this->SetType(BucketHeadZombieType);
	this->SetHp(BUCKET_HEAD_ZOMBIE_HP);
	this->SetPosition(x, y);
	BattleField* battlefield = BattleField::GetInstance();
	if (!battlefield->SomethingOnBattleField(x, y))
	{
		battlefield->CreateOnBattleField(BZ, x, y);
		battlefield->AddOnZombiesList(this);
	}
}

BucketHeadZombie::~BucketHeadZombie()
{
}