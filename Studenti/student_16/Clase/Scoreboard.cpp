#include "Scoreboard.h"
#include <algorithm>
Scoreboard* Scoreboard::instance = nullptr;
Scoreboard::Scoreboard()
	:count(0)
{
	begin = steady_clock::now();
	startX = 0;
	startY = 0;
	blinked = false;
}
bool compare(user* a, user* b)
{
	return a->score > b->score;
}
int Scoreboard::getMaxScore()
{
	std::ifstream fin("score.txt");
	std::string user;
	int score;
	fin >> user >> score;
	fin.close();
	return score;
}
void Scoreboard::updateScore(std::string username)
{
	std::ifstream fin("score.txt");
	std::vector<user*> utilizatori;
	std::string name;
	int score;
	int i = 0;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> name >> score;
			utilizatori.push_back(new user);
			utilizatori[i]->name = name;
			if (name == username)
			{
				if (this->count > score)
				{
					utilizatori[i]->score = count;
				}
			}
			else
			{
				utilizatori[i]->score = score;
			}
			++i;

		}
	}
	sort(utilizatori.begin(), utilizatori.end(), compare);
	fin.close();
	std::ofstream fout("score.txt");
	for (int i = 0; i < utilizatori.size(); ++i)
	{
		fout << utilizatori[i]->name << " " << utilizatori[i]->score;
		if (i + 1 < utilizatori.size())
		{
			fout << "\n";
		}
	}
	fout.close();
}
void Scoreboard::draw()
{
	UserInterface::ConsoleOutput& conOut = UserInterface::ConsoleOutput::getInstance();
	conOut(startX, startY) << (unsigned char)TL
	conOut(startX, startY + TILE_WIDTH) << (unsigned char)TR;
	conOut(startX+TILE_HEIGHT, startY) << (unsigned char)BL;
	conOut(startX + TILE_HEIGHT, startY + TILE_WIDTH) << (unsigned char)BR;
	conOut(startX + 1, startY + (TILE_WIDTH - 8) / 2) << "Scoreboard";
	conOut(startX + 2, startY + (TILE_WIDTH-3) / 2) << count;
	if (count >= Scoreboard::getInstance().getMaxScore())
	{
		auto end = steady_clock::now();
		if (duration_cast<milliseconds>(end - begin).count() > 200)
		{
			begin = end;
			if (!blinked)
			{
				conOut(startX + 4, startY + (TILE_WIDTH - 8) / 2) << "HIGHSCORE";
			}
			else
			{
				conOut(startX + 4, startY + (TILE_WIDTH - 8) / 2) << "         ";
			}
			blinked = !blinked;
		}
	}
}
Scoreboard& Scoreboard::getInstance()
{
	if (!Scoreboard::instance)
	{
		Scoreboard::instance = new Scoreboard;
	}
	return *Scoreboard::instance;
}
void Scoreboard::modifyCount(int amount)
{
	count += amount;
}