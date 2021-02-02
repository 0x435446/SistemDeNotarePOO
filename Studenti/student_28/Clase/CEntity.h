#pragma once
#include"CEntities.h"
#include<time.h>

class CEntity: public CEntities
{
protected:
	int m_speed;
	int m_type;
	//CEntity(const CEntity& zomb);
public:
	CEntity(const int& speed, const int& type);
};

