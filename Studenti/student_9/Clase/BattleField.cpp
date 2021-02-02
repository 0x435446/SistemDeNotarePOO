#include "BattleField.h"

BattleField* BattleField::instance = nullptr;

BattleField * BattleField::GetInstance() 
{
	if (instance == nullptr)
		instance = new BattleField;

	return instance;
}

BattleField::BattleField()
{
	
}


BattleField::~BattleField()
{
}

const void BattleField::print_field() const
{
	UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
	for (int i = 38; i <= 98; i++) {
		conOut(10, i) << "-";
		conOut(35, i) << "-";
		if (i % 7 == 0) {
			for (int j = 10; j <= 35; j++) {
				conOut(j, i-2) << "|";
			}
		}
	}
	for (int j = 10; j <= 35; j += 5) {
		for (int i = 38; i <= 98; i++) {
			conOut(j, i) << "-";
		}
	}
}

int BattleField::get_field_position(int x, int y)
{
	if (x >= 10 && x <= 14) {
		if (y >= 40 && y <= 46)
			return battle_field[0][1];
		if (y >= 48 && y <= 53)
			return battle_field[0][2];
		if (y >= 55 && y <= 60)
			return battle_field[0][3];
		if (y >= 62 && y <= 67)
			return battle_field[0][4];
		if (y >= 69 && y <= 74)
			return battle_field[0][5];
		if (y >= 76 && y <= 81)
			return battle_field[0][6];
		if (y >= 83 && y <= 88)
			return battle_field[0][7];
		if (y >= 90 && y <= 95)
			return battle_field[0][8];
	}
	if (x >= 16 && x <= 19) {
		if (y >= 40 && y <= 46)
			return battle_field[1][1];
		if (y >= 48 && y <= 53)
			return battle_field[1][2];
		if (y >= 55 && y <= 60)
			return battle_field[1][3];
		if (y >= 62 && y <= 67)
			return battle_field[1][4];
		if (y >= 69 && y <= 74)
			return battle_field[1][5];
		if (y >= 76 && y <= 81)
			return battle_field[1][6];
		if (y >= 83 && y <= 88)
			return battle_field[1][7];
		if (y >= 90 && y <= 95)
			return battle_field[1][8];
	}
	if (x >= 21 && x <= 24) {
		if (y >= 40 && y <= 46)
			return battle_field[2][1];
		if (y >= 48 && y <= 53)
			return battle_field[2][2];
		if (y >= 55 && y <= 60)
			return battle_field[2][3];
		if (y >= 62 && y <= 67)
			return battle_field[2][4];
		if (y >= 69 && y <= 74)
			return battle_field[2][5];
		if (y >= 76 && y <= 81)
			return battle_field[2][6];
		if (y >= 83 && y <= 88)
			return battle_field[2][7];
		if (y >= 90 && y <= 95)
			return battle_field[2][8];
	}
	if (x >= 26 && x <= 29) {
		if (y >= 40 && y <= 46)
			return battle_field[3][1];
		if (y >= 48 && y <= 53)
			return battle_field[3][2];
		if (y >= 55 && y <= 60)
			return battle_field[3][3];
		if (y >= 62 && y <= 67)
			return battle_field[3][4];
		if (y >= 69 && y <= 74)
			return battle_field[3][5];
		if (y >= 76 && y <= 81)
			return battle_field[3][6];
		if (y >= 83 && y <= 88)
			return battle_field[3][7];
		if (y >= 90 && y <= 95)
			return battle_field[3][8];
	}
	if (x >= 31 && x <= 34) {
		if (y >= 40 && y <= 46)
			return battle_field[4][1];
		if (y >= 48 && y <= 53)
			return battle_field[4][2];
		if (y >= 55 && y <= 60)
			return battle_field[4][3];
		if (y >= 62 && y <= 67)
			return battle_field[4][4];
		if (y >= 69 && y <= 74)
			return battle_field[4][5];
		if (y >= 76 && y <= 81)
			return battle_field[4][6];
		if (y >= 83 && y <= 88)
			return battle_field[4][7];
		if (y >= 90 && y <= 95)
			return battle_field[4][8];
	}
	return -1;
}

void BattleField::set_field_position(int x, int y, char c)
{
	if (x >= 10 && x <= 14) {
		if (y >= 40 && y <= 46)
			if (c == 'p')
				battle_field[0][1] = 1;
			else if (c == 'z')
				battle_field[0][1] = 2;
			else if (c == '0')
				battle_field[0][1] = 0;
			
		if (y >= 48 && y <= 53)
			if (c == 'p')
				battle_field[0][2] = 1;
			else if (c == 'z')
				battle_field[0][2] = 2;
			else if (c == '0')
				battle_field[0][2] = 0;

		if (y >= 55 && y <= 60)
			if (c == 'p')
				battle_field[0][3] = 1;
			else if (c == 'z')
				battle_field[0][3] = 2;
			else if (c == '0')
				battle_field[0][3] = 0;

		if (y >= 62 && y <= 67)
			if (c == 'p')
				battle_field[0][4] = 1;
			else if (c == 'z')
				battle_field[0][4] = 2;
			else if (c == '0')
				battle_field[0][4] = 0;

		if (y >= 69 && y <= 74)
			if (c == 'p')
				battle_field[0][5] = 1;
			else if (c == 'z')
				battle_field[0][5] = 2;
			else if (c == '0')
				battle_field[0][5] = 0;
		if (y >= 76 && y <= 81)
			if (c == 'p')
				battle_field[0][6] = 1;
			else if (c == 'z')
				battle_field[0][6] = 2;
			else if (c == '0')
				battle_field[0][6] = 0;
		if (y >= 83 && y <= 88)
			if (c == 'p')
				battle_field[0][7] = 1;
			else if (c == 'z')
				battle_field[0][7] = 2;
			else if (c == '0')
				battle_field[0][7] = 0;
		if (y >= 90 && y <= 95)
			if (c == 'p')
				battle_field[0][8] = 1;
			else if (c == 'z')
				battle_field[0][8] = 2;
			else if (c == '0')
				battle_field[0][8] = 0;
	}
	if (x >= 16 && x <= 19) {
		if (y >= 40 && y <= 46)
			if (c == 'p')
				battle_field[1][1] = 1;
			else if (c == 'z')
				battle_field[1][1] = 2;
			else if (c == '0')
				battle_field[1][1] = 0;
		if (y >= 48 && y <= 53)
			if (c == 'p')
				battle_field[1][2] = 1;
			else if (c == 'z')
				battle_field[1][2] = 2;
			else if (c == '0')
				battle_field[1][2] = 0;

		if (y >= 55 && y <= 60)
			if (c == 'p')
				battle_field[1][3] = 1;
			else if (c == 'z')
				battle_field[1][3] = 2;
			else if (c == '0')
				battle_field[1][3] = 0;

		if (y >= 62 && y <= 67)
			if (c == 'p')
				battle_field[1][4] = 1;
			else if (c == 'z')
				battle_field[1][4] = 2;
			else if (c == '0')
				battle_field[1][4] = 0;

		if (y >= 69 && y <= 74)
			if (c == 'p')
				battle_field[1][5] = 1;
			else if (c == 'z')
				battle_field[1][5] = 2;
			else if (c == '0')
				battle_field[1][5] = 0;

		if (y >= 76 && y <= 81)
			if (c == 'p')
				battle_field[1][6] = 1;
			else if (c == 'z')
				battle_field[1][6] = 2;
			else if (c == '0')
				battle_field[1][6] = 0;
		
		if (y >= 83 && y <= 88)
			if (c == 'p')
				battle_field[1][7] = 1;
			else if (c == 'z')
				battle_field[1][7] = 2;
			else if (c == '0')
				battle_field[1][7] = 0;

		if (y >= 90 && y <= 95)
			if (c == 'p')
				battle_field[1][8] = 1;
			else if (c == 'z')
				battle_field[1][8] = 2;
			else if (c == '0')
				battle_field[1][8] = 0;
	}
	if (x >= 21 && x <= 24) {
		if (y >= 40 && y <= 46)
			if (c == 'p')
				battle_field[2][1] = 1;
			else if (c == 'z')
				battle_field[2][1] = 2;
			else if (c == '0')
				battle_field[2][1] = 0;

		if (y >= 48 && y <= 53)
			if (c == 'p')
				battle_field[2][2] = 1;
			else if (c == 'z')
				battle_field[2][2] = 2;
			else if (c == '0')
				battle_field[2][2] = 0;

		if (y >= 55 && y <= 60)
			if (c == 'p')
				battle_field[2][3] = 1;
			else if (c == 'z')
				battle_field[2][3] = 2;
			else if (c == '0')
				battle_field[2][3] = 0;

		if (y >= 62 && y <= 67)
			if (c == 'p')
				battle_field[2][4] = 1;
			else if (c == 'z')
				battle_field[2][4] = 2;
			else if (c == '0')
				battle_field[2][4] = 0;

		if (y >= 69 && y <= 74)
			if (c == 'p')
				battle_field[2][5] = 1;
			else if (c == 'z')
				battle_field[2][5] = 2;
			else if (c == '0')
				battle_field[2][5] = 0;

		if (y >= 76 && y <= 81)
			if (c == 'p')
				battle_field[2][6] = 1;
			else if (c == 'z')
				battle_field[2][6] = 2;
			else if (c == '0')
				battle_field[2][6] = 0;

		if (y >= 83 && y <= 88)
			if (c == 'p')
				battle_field[2][7] = 1;
			else if (c == 'z')
				battle_field[2][7] = 2;
			else if (c == '0')
				battle_field[2][7] = 0;

		if (y >= 90 && y <= 95)
			if (c == 'p')
				battle_field[2][8] = 1;
			else if (c == 'z')
				battle_field[2][8] = 2;
			else if (c == '0')
				battle_field[2][8] = 0;

	}
	if (x >= 26 && x <= 29) {
		if (y >= 40 && y <= 46)
			if (c == 'p')
				battle_field[3][1] = 1;
			else if (c == 'z')
				battle_field[3][1] = 2;
			else if (c == '0')
				battle_field[3][1] = 0;

		if (y >= 48 && y <= 53)
			if (c == 'p')
				battle_field[3][2] = 1;
			else if (c == 'z')
				battle_field[3][2] = 2;
			else if (c == '0')
				battle_field[3][2] = 0;

		if (y >= 55 && y <= 60)
			if (c == 'p')
				battle_field[3][3] = 1;
			else if (c == 'z')
				battle_field[3][3] = 2;
			else if (c == '0')
				battle_field[3][3] = 0;

		if (y >= 62 && y <= 67)
			if (c == 'p')
				battle_field[3][4] = 1;
			else if (c == 'z')
				battle_field[3][4] = 2;
			else if (c == '0')
				battle_field[3][4] = 0;

		if (y >= 69 && y <= 74)
			if (c == 'p')
				battle_field[3][5] = 1;
			else if (c == 'z')
				battle_field[3][5] = 2;
			else if (c == '0')
				battle_field[3][5] = 0;

		if (y >= 76 && y <= 81)
			if (c == 'p')
				battle_field[3][6] = 1;
			else if (c == 'z')
				battle_field[3][6] = 2;
			else if (c == '0')
				battle_field[3][6] = 0;

		if (y >= 83 && y <= 88)
			if (c == 'p')
				battle_field[3][7] = 1;
			else if (c == 'z')
				battle_field[3][7] = 2;
			else if (c == '0')
				battle_field[3][7] = 0;

		if (y >= 90 && y <= 95)
			if (c == 'p')
				battle_field[3][8] = 1;
			else if (c == 'z')
				battle_field[3][8] = 2;
			else if (c == '0')
				battle_field[3][8] = 0;

	}
	if (x >= 31 && x <= 34) {
		if (y >= 40 && y <= 46)
			if (c == 'p')
				battle_field[4][1] = 1;
			else if (c == 'z')
				battle_field[4][1] = 2;
			else if (c == '0')
				battle_field[4][1] = 0;

		if (y >= 48 && y <= 53)
			if (c == 'p')
				battle_field[4][2] = 1;
			else if (c == 'z')
				battle_field[4][2] = 2;
			else if (c == '0')
				battle_field[4][2] = 0;

		if (y >= 55 && y <= 60)
			if (c == 'p')
				battle_field[4][3] = 1;
			else if (c == 'z')
				battle_field[4][3] = 2;
			else if (c == '0')
				battle_field[4][3] = 0;

		if (y >= 62 && y <= 67)
			if (c == 'p')
				battle_field[4][4] = 1;
			else if (c == 'z')
				battle_field[4][4] = 2;
			else if (c == '0')
				battle_field[4][4] = 0;

		if (y >= 69 && y <= 74)
			if (c == 'p')
				battle_field[4][5] = 1;
			else if (c == 'z')
				battle_field[4][5] = 2;
			else if (c == '0')
				battle_field[4][5] = 0;

		if (y >= 76 && y <= 81)
			if (c == 'p')
				battle_field[4][6] = 1;
			else if (c == 'z')
				battle_field[4][6] = 2;
			else if (c == '0')
				battle_field[4][6] = 0;

		if (y >= 83 && y <= 88)
			if (c == 'p')
				battle_field[4][7] = 1;
			else if (c == 'z')
				battle_field[4][7] = 2;
			else if (c == '0')
				battle_field[4][7] = 0;

		if (y >= 90 && y <= 95)
			if (c == 'p')
				battle_field[4][8] = 1;
			else if (c == 'z')
				battle_field[4][8] = 2;
			else if (c == '0')
				battle_field[4][8] = 0;

	}
}
