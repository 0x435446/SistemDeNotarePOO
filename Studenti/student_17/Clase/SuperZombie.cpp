#include "SuperZombie.h"
#include "Exception.h"
#include "BattleField.h"

bool SuperZombie::s_instance = false;

SuperZombie* SuperZombie::GetInstance(const int x, const int y)
{
	if (SuperZombie::s_instance == true)
		throw Exception("SuperZombie already exists");
	else
	{
		SuperZombie::s_instance = true;
		return new SuperZombie(x, y);
	}
}

void SuperZombie::DeleteInstance(SuperZombie* instance)
{
	if (SuperZombie::s_instance == true)
	{
		delete instance;
		SuperZombie::s_instance = false;
	}
}

SuperZombie::SuperZombie(const int x, const int y) : BucketHeadZombie(x, y), PoleVaultingZombie(x, y)
{
	this->SetType(SuperZombieType);
	this->SetPosition(x, y);
	BattleField* battlefield = BattleField::GetInstance();
	if (!battlefield->SomethingOnBattleField(x, y))
	{
		battlefield->CreateOnBattleField(SZ, x, y);
		battlefield->AddOnZombiesList(this);
	}
}

SuperZombie::~SuperZombie()
{
}