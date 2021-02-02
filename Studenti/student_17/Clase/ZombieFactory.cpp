#include "ZombieFactory.h"
#include "Exception.h"
#include <stdlib.h>
#include <time.h>   
#include "BattleField.h"

ZombieFactory* ZombieFactory::s_instance = nullptr;

bool ZombieFactory::s_superzombie_created = false;

ZombieFactory* ZombieFactory::GetInstance()
{
	if (ZombieFactory::s_instance == nullptr)
		ZombieFactory::s_instance = new ZombieFactory();
	return ZombieFactory::s_instance;
}

void ZombieFactory::DeleteInstance(ZombieFactory* instance)
{
	if (ZombieFactory::s_instance != nullptr)
	{
		delete instance;
		ZombieFactory::s_instance = nullptr;
	}
}

Zombie* ZombieFactory::CreateZombie()
{
	ZombieType type = ZombieType(rand() % 4 + 1);
	BattleField* battlefield = BattleField::GetInstance();
	int level = battlefield->GetLevel();
	int place;
	switch (level)
	{
	case LVL1:
		place = 19;
		break;
	case LVL2:
		srand(time(NULL));
		place = (rand() % 3 + 1) * 6 + 7;
		break;
	case LVL3:
		srand(time(NULL));
		place = (rand() % 5 + 1) * 6 + 1;
		break;
	}
	
	switch (type)
	{
	case NormalZombieType:
		return new NormalZombie(place, 145);
		break;
	case BucketHeadZombieType:
		return new BucketHeadZombie(place, 145);
		break;
	case PoleVaultingZombieType:
		return new PoleVaultingZombie(place, 145);
		break;
	case SuperZombieType:
		if (ZombieFactory::s_superzombie_created == false)
		{
			ZombieFactory::s_superzombie_created = true;
			return SuperZombie::GetInstance(place, 145);
		}
		break;
	default:
		throw Exception("No valid zombie type");
		break;
	}
}

ZombieFactory::ZombieFactory()
{
}

ZombieFactory::~ZombieFactory()
{
}