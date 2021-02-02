#pragma once
#include "Zombie.h"

class PoleVaultingZombie : virtual public Zombie
{
public:
	PoleVaultingZombie(const int x, const int y);
	virtual ~PoleVaultingZombie();
	bool GetUsedAbility() const;
protected:
	void SetOnUsedAbility();
private:
	bool m_usedAbility;
};