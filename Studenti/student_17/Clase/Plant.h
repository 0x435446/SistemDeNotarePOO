#pragma once
#include "DisplayableEntity.h"

#define MAX_BITES 2

enum PlantType
{
	NoPlantType = 0, PeaShooterType, SnowPeaShooterType, SunFlowerType, WallNutType, CherryBombType
};

class Plant : public DisplayableEntity
{
public:
	Plant();
	virtual ~Plant();
	PlantType GetType() const;
	int GetCurrentBites() const;
	int GetMaxBites() const;
	int GetCost() const;

	void GetBitten();
protected:
	void SetType(const PlantType type);
	void SetMaxBites(const int max_bites);
	void SetCost(const int cost);
private:
	static unsigned int s_plantsIdCounter;
	unsigned int m_plantId;
	PlantType m_type;
	int m_currentBites;
	int m_maxBites;
	int m_cost;
};