#pragma once
#include "Entity.h"

class Plant_Peashooter:public Entity
{
public:
	// CONSTRUCTOR SI DESTRUCTOR VIRTUAL
	Plant_Peashooter(int Dmg, int Hp, int Jump,std::string Name, int Speed);
	~Plant_Peashooter();
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

