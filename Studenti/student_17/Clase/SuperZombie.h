#pragma once
#include "BucketHeadZombie.h"
#include "PoleVaultingZombie.h"

class SuperZombie : public BucketHeadZombie, public PoleVaultingZombie
{
public:
	static SuperZombie* GetInstance(const int x, const int y);
	static void DeleteInstance(SuperZombie* instance);
private:
	static bool s_instance;
	SuperZombie(const int x, const int y);
	~SuperZombie();
};