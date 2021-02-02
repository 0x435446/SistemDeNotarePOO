#include "PoleVaultingZombie.h"
#include "BattleField.h"

PoleVaultingZombie::PoleVaultingZombie(const int x, const int y) : m_usedAbility(false)
{
	this->SetType(PoleVaultingZombieType);
	this->SetSpeed(ZOMBIE_SPEED * 3 / 2);
	this->SetPosition(x, y);
	BattleField* battlefield = BattleField::GetInstance();
	if (!battlefield->SomethingOnBattleField(x, y))
	{
		battlefield->CreateOnBattleField(PZ, x, y);
		battlefield->AddOnZombiesList(this);
	}
}

PoleVaultingZombie::~PoleVaultingZombie()
{
}

void PoleVaultingZombie::SetOnUsedAbility()
{
	this->m_usedAbility = true;
}

bool PoleVaultingZombie::GetUsedAbility() const
{
	return this->m_usedAbility;
}