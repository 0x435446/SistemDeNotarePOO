#include "BattleField.h"
#include "Exception.h"

void Level3BattleField(char field[37][161])
{
	for (int i = 0; i < 37; i++)
		for (int j = 0; j < 161; j++)
		{
			if (i % 6 != 0 && j % 16 != 0) field[i][j] = ' ';
			if (i % 6 == 0) field[i][j] = HORIZONTAL_LINE;
			if (j % 16 == 0) field[i][j] = VERTICAL_LINE;
			if ((i % 6 == 0) && (j % 16 == 0)) field[i][j] = INTERSECTION;
			if ((i % 6 == 0) && (j == 0)) field[i][j] = T_LEFT;
			if ((i % 6 == 0) && (j == 160)) field[i][j] = T_RIGHT;
			if ((i == 0) && (j % 16 == 0)) field[i][j] = T_UP;
			if ((i == 36) && (j % 16 == 0)) field[i][j] = T_DOWN;
		}
	field[0][0] = CORNER_LEFT_UP;
	field[0][160] = CORNER_RIGHT_UP;
	field[36][0] = CORNER_LEFT_DOWN;
	field[36][160] = CORNER_RIGHT_DOWN;
	field[1][3] = 'S'; field[1][4] = 'C'; field[1][5] = 'O'; field[1][6] = 'R'; field[1][7] = 'E';
	field[1][8] = 'B'; field[1][9] = 'O'; field[1][10] = 'A'; field[1][11] = 'R'; field[1][12] = 'D';
}

void Level1BattleField(char field[37][161])
{
	Level3BattleField(field);
	for (int i = 0; i < 37; i++)
		for (int j = 0; j < 161; j++)
		{
			if ((i > 6 && i < 18) && (j > 16)) field[i][j] = ' ';
			if ((i > 24) && (j > 16)) field[i][j] = ' ';
			if ((i == 12 || i == 30) && (j == 16)) field[i][j] = T_RIGHT;
			if ((i == 6 || i == 24) && (j % 16 == 0 && j > 16)) field[i][j] = T_DOWN;
			if ((i == 18) && (j % 16 == 0 && j > 16)) field[i][j] = T_UP;
			if (((i == 36) && (j == 16)) || ((i == 6) && (j == 160)) || ((i == 24) && (j == 160))) field[i][j] = CORNER_RIGHT_DOWN;
			if (i == 18 && j == 160) field[i][j] = CORNER_RIGHT_UP;
		}
}

void Level2BattleField(char field[37][161])
{
	Level3BattleField(field);
	for (int i = 0; i < 37; i++)
		for (int j = 0; j < 161; j++)
		{
			if ((i > 6 && i < 12) && (j > 16)) field[i][j] = ' ';
			if ((i > 30) && (j > 16)) field[i][j] = ' ';
			if ((i == 6 || i == 30) && (j % 16 == 0 && j > 16)) field[i][j] = T_DOWN;
			if ((i == 12) && (j % 16 == 0 && j > 16)) field[i][j] = T_UP;
			if (((i == 36) && (j == 16)) || ((i == 6) && (j == 160)) || ((i == 30) && (j == 160))) field[i][j] = CORNER_RIGHT_DOWN;
			if (i == 12 && j == 160) field[i][j] = CORNER_RIGHT_UP;
		}
}

BattleField* BattleField::s_instance = nullptr;

BattleField* BattleField::GetInstance()
{
	return BattleField::s_instance;
}

BattleField* BattleField::GetInstance(const Level level)
{
	if (BattleField::s_instance == nullptr)
		BattleField::s_instance = new BattleField(level);
	return BattleField::s_instance;
}

void BattleField::DeleteInstance(BattleField* instance)
{
	if (BattleField::s_instance != nullptr)
	{
		delete instance;
		BattleField::s_instance = nullptr;
	}
}

Level BattleField::GetLevel() const
{
	return this->m_level;
}

char BattleField::GetChar(const int i, const int j) const
{
	return this->m_field[i][j];
}

void BattleField::SetLevel(const Level level)
{
	this->m_level = level;
	switch (level)
	{
	case LVL2:
		Level2BattleField(this->m_field);
		break;
	case LVL3:
		Level3BattleField(this->m_field);
		break;
	}
}

void BattleField::CreateOnBattleField(const Creature creature, const int x, const int y)
{
	switch (creature)
	{
	case SN:
		this->m_field[x][y] = 'S';
		this->m_field[x][y+1] = 'U';
		this->m_field[x][y+2] = 'N';
		break;
	case NZ:
		this->m_field[x][y] = 'N';
		this->m_field[x][y + 1] = 'O';
		this->m_field[x][y + 2] = 'R';
		this->m_field[x][y + 3] = 'M';
		this->m_field[x][y + 4] = 'A';
		this->m_field[x][y + 5] = 'L';

		this->m_field[x + 1][y] = 'Z';
		this->m_field[x + 1][y + 1] = 'O';
		this->m_field[x + 1][y + 2] = 'M';
		this->m_field[x + 1][y + 3] = 'B';
		this->m_field[x + 1][y + 4] = 'I';
		this->m_field[x + 1][y + 5] = 'E';
		break;
	case PZ:
		this->m_field[x][y] = 'P';
		this->m_field[x][y + 1] = 'O';
		this->m_field[x][y + 2] = 'L';
		this->m_field[x][y + 3] = 'E';
		this->m_field[x][y + 4] = 'V';
		this->m_field[x][y + 5] = 'A';
		this->m_field[x][y + 6] = 'U';
		this->m_field[x][y + 7] = 'L';
		this->m_field[x][y + 8] = 'T';
		this->m_field[x][y + 9] = 'I';
		this->m_field[x][y + 10] = 'N';
		this->m_field[x][y + 11] = 'G';

		this->m_field[x + 1][y] = 'Z';
		this->m_field[x + 1][y + 1] = 'O';
		this->m_field[x + 1][y + 2] = 'M';
		this->m_field[x + 1][y + 3] = 'B';
		this->m_field[x + 1][y + 4] = 'I';
		this->m_field[x + 1][y + 5] = 'E';
		break;
	case BZ:
		this->m_field[x][y] = 'B';
		this->m_field[x][y + 1] = 'U';
		this->m_field[x][y + 2] = 'C';
		this->m_field[x][y + 3] = 'K';
		this->m_field[x][y + 4] = 'E';
		this->m_field[x][y + 5] = 'T';
		this->m_field[x][y + 6] = 'H';
		this->m_field[x][y + 7] = 'E';
		this->m_field[x][y + 8] = 'A';
		this->m_field[x][y + 9] = 'D';

		this->m_field[x + 1][y] = 'Z';
		this->m_field[x + 1][y + 1] = 'O';
		this->m_field[x + 1][y + 2] = 'M';
		this->m_field[x + 1][y + 3] = 'B';
		this->m_field[x + 1][y + 4] = 'I';
		this->m_field[x + 1][y + 5] = 'E';
		break;
	case SZ:
		this->m_field[x][y] = 'S';
		this->m_field[x][y + 1] = 'U';
		this->m_field[x][y + 2] = 'P';
		this->m_field[x][y + 3] = 'E';
		this->m_field[x][y + 4] = 'R';

		this->m_field[x + 1][y] = 'Z';
		this->m_field[x + 1][y + 1] = 'O';
		this->m_field[x + 1][y + 2] = 'M';
		this->m_field[x + 1][y + 3] = 'B';
		this->m_field[x + 1][y + 4] = 'I';
		this->m_field[x + 1][y + 5] = 'E';
		break;
	}
}

void BattleField::DeleteOnBattleField(const int x, const int y)
{
	for (int i = x; i < x + 5; i++)
		for (int j = y; j < y + 15; j++)
			this->m_field[i][j] = ' ';
}

bool BattleField::SomethingOnBattleField(const int x, const int y)
{
	bool isSomething = false;
	for (int i = x; i < x + 5; i++)
	{
		for (int j = y; j < y + 15; j++)
			if (this->m_field[i][j] != ' ')
			{
				isSomething = true;
				break;
			}
		if (isSomething == true)
			break;
	}
		
	return isSomething;
}

void BattleField::AddOnZombiesList(Zombie* zombie)
{
	this->zombies_list.push_back(zombie);
}

void BattleField::AddOnResourcesList(Resource* resource)
{
	this->resources_list.push_back(resource);
}

void BattleField::AddOnPlantsList(Plant* plant)
{
	this->plants_list.push_back(plant);
}

BattleField::BattleField(const Level level) : m_level(level)
{
	switch (level)
	{
	case LVL1:
		Level1BattleField(this->m_field);
		break;
	case LVL2:
		Level2BattleField(this->m_field);
		break;
	case LVL3:
		Level3BattleField(this->m_field);
		break;
	}
}

BattleField::~BattleField()
{
}