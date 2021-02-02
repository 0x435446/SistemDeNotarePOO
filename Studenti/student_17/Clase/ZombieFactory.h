#pragma once
#include "NormalZombie.h"
#include "PoleVaultingZombie.h"
#include "BucketHeadZombie.h"
#include "SuperZombie.h"

class ZombieFactory
{
public:
	static ZombieFactory* GetInstance();
	static void DeleteInstance(ZombieFactory* instance);
	static Zombie* CreateZombie();
private:
	static ZombieFactory* s_instance;
	static bool s_superzombie_created;
	ZombieFactory();
	~ZombieFactory();
};