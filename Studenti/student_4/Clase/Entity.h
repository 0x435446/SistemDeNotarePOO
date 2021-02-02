#pragma once
#include <iostream>
#include <string>

// Zombies
class Zm_Basic;
class Zm_BucketHead;
class Zm_PoleVaulting;
class Zm_Super;

// Plants
class Plant_Cherry_Bomb;
class Plant_Peashooter;
class Plant_Snow_Pea;
class Plant_Sunflower;
class Plant_Wallnut;

class Entity
{
protected:
	
	int Dmg;
	int Hp;
	int Jump;
	std::string Name;
	int Speed;
	Entity(int Dmg, int Hp, int Jump,std::string Name, int Speed);
public:
	//		DESTRUCTOR VIRTUAL
	virtual ~Entity();
	//			 SET
	virtual void Set_Dmg(int Dmg)=0;
	virtual void Set_Hp(int Hp)=0;
	virtual void Set_Jump(int Jump)=0;
	virtual void Set_Name(std::string Name) = 0;
	virtual void Set_Speed(int Speed)=0;
	
	//			GET
	virtual	int Get_Dmg()=0;
	virtual	int Get_Hp()=0;
	virtual	int Get_Jump()=0;
	virtual std::string Get_Name() = 0;
	virtual	int Get_Speed()=0;

	//			 FIGHT
	virtual void Fight(Entity& E) = 0;
};

