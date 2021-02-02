#pragma once
#include "Entity.h"

class Zm_PoleVaulting: virtual public Entity
{
public:
	//	CONSTRUCTOR SI DESTRUCTOR VIRTUAL
	Zm_PoleVaulting(int Dmg, int Hp, int Jump, std::string Name, int Speed);
	virtual	~Zm_PoleVaulting();
	//			 SET
	virtual void Set_Dmg(int Dmg) override;
	virtual void Set_Hp(int Hp)override;
	virtual void Set_Jump(int Jump) override;
	virtual void Set_Name(std::string Name)override;
	virtual void Set_Speed(int Speed) override;

	//			GET
	virtual	int Get_Dmg() override;
	virtual	int Get_Hp() override;
	virtual	int Get_Jump() override;
	virtual std::string Get_Name()override;
	virtual	int Get_Speed() override;

	//			 FIGHT
	virtual void Fight(Entity& E)override;
};

