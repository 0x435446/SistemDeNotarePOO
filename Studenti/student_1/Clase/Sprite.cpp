#include <fstream>

#include "Sprite.h"
#include "ConsoleOutput.h"
#include "GameSpecifications.h"

using namespace UserInterface;

Sprite::Sprite(std::vector< std::pair <std::string, int> > v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		std::ifstream file("Sprites/" + v[i].first);
		std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
		file.close();
		parts.push_back(make_pair(str, v[i].second)); //each part has a string and a color
	}
}


Sprite::~Sprite()
{
}

void Sprite::show(int row, int col)
{
	ConsoleOutput& conOut = ConsoleOutput::getInstance();
	bool setCursor = true;

	for (unsigned int sp = 0; sp < parts.size(); sp++)
	{
		int r = row, c = col;

		for (unsigned int i = 0; i < parts[sp].first.length(); i++)
		{
			if (!isspace(parts[sp].first[i]))
			{
				if (setCursor)
					conOut(r, c);
				conOut[parts[sp].second] << parts[sp].first[i];
				c++;
			}
			else if (parts[sp].first[i] == '\n')
			{
				r++;
				c = col;
				setCursor = true;
			}
			else
			{
				c++;
				setCursor = true;
			}
		}
	}
}

void UserInterface::Sprite::show(int row, int col, char overrideChar)
{
	ConsoleOutput& conOut = ConsoleOutput::getInstance();

	std::vector<int> delimitationRows;
	std::vector<int> delimitationCols;

	for (int i = 0; i < GameMechanics::ROWS_NO; i++)
		delimitationRows.push_back(BOARD_ROW_UP + i * TILE_HEIGHT);
	for (int i = 0; i < GameMechanics::COLS_NO; i++)
		delimitationCols.push_back(BOARD_COL_LEFT + i * (TILE_WIDTH - 1));

	for (unsigned int sp = 0; sp < parts.size(); sp++)
	{
		int r = row, c = col;
		bool setCursor = true;
		bool printed = false;
		conOut[parts[sp].second];

		for (unsigned int i = 0; i < parts[sp].first.length(); i++)
		{
			if (!isspace(parts[sp].first[i]))
			{
				if (setCursor)
					conOut(r, c);
				if ((parts[sp].first[i] == '!') && (std::find(delimitationCols.begin(), delimitationCols.end(), c) != delimitationCols.end()))
				{
					conOut[OliveBack | BlackFore] << "|";
					conOut[parts[sp].second];
				}
				else
					conOut << parts[sp].first[i];
				printed = true;
				c++;
			}
			else if (parts[sp].first[i] == '\n')
			{
				if (printed)
				{
					if (setCursor)
						conOut(r, c);
					if (std::find(delimitationRows.begin(), delimitationRows.end(), r) != delimitationRows.end())
					{
						if (std::find(delimitationCols.begin(), delimitationCols.end(), c) != delimitationCols.end())
							conOut[OliveBack | BlackFore] << '+';
						else
							conOut[OliveBack | BlackFore] << '-';
					}
					else
					{
						if (std::find(delimitationCols.begin(), delimitationCols.end(), c) != delimitationCols.end())
							conOut[OliveBack | BlackFore] << '|';
						else
							conOut[OliveBack | OliveFore] << overrideChar;
					}
					conOut[parts[sp].second];
				}
				r++;
				c = col;
				setCursor = true;
				printed = false;
			}
			else
			{
				c++;
				setCursor = true;
			}
		}
	}
}
