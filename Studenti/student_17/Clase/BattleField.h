#pragma once
#include <list>
#include "Plant.h"
#include "Zombie.h"
#include "Resource.h"

#define VERTICAL_LINE		179
#define T_RIGHT				180
#define CORNER_RIGHT_UP		191
#define CORNER_LEFT_DOWN	192
#define T_DOWN				193
#define T_UP				194
#define T_LEFT				195
#define HORIZONTAL_LINE		196
#define INTERSECTION		197
#define CORNER_RIGHT_DOWN	217
#define CORNER_LEFT_UP		218

enum Level
{
	LVL1 = 1, LVL2, LVL3
};

enum Creature
{
	SN = 1, NZ, BZ, PZ, SZ
};

class BattleField
{
public:
	static BattleField* GetInstance();
	static BattleField* GetInstance(const Level level);
	static void DeleteInstance(BattleField* instance);
	Level GetLevel() const;
	char GetChar(const int i, const int j) const;
	void SetLevel(const Level level);

	void CreateOnBattleField(const Creature creature, const int x, const int y);
	void DeleteOnBattleField(const int x, const int y);
	bool SomethingOnBattleField(const int x, const int y);

	void AddOnZombiesList(Zombie* zombie);
	void AddOnResourcesList(Resource* resource);
	void AddOnPlantsList(Plant* plant);

private:
	BattleField();
	BattleField(const Level level);
	~BattleField();
	static BattleField* s_instance;
	Level m_level;
	char m_field[37][161];

	std::list<Zombie*> zombies_list;
	std::list<Resource*> resources_list;
	std::list<Plant*> plants_list;
};