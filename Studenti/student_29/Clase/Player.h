#pragma once
#include <iostream>
#include <string>

class Player
{
	int playersMoney = 0;
	int sunflowerCost = 25;
	int peashooterCost = 50;
	int wallnutCost = 50;
	int cherrybombCost = 75;
	int snowpeaCost = 100;
	int score = 0;

public:

	Player();

	void modifyAmountOfMoney(int val)
	{
		playersMoney += val;
	}

	void modifyScore(unsigned int val)
	{
		score = val;
	}

	int returnScore()
	{
		return score;
	}

	std::string displayShop()
	{
		std::string s;
		s += "Player`s money: ";
		s += std::to_string(playersMoney);
		s += "\n(F) Sunflower cost: ";
		s += std::to_string(sunflowerCost);
		s += "\n(P) Peashooter cost: ";
		s += std::to_string(peashooterCost);
		s += "\n(W) Wallnut cost: ";
		s += std::to_string(wallnutCost);
		s += "\n(C) Cherrybomb cost: ";
		s += std::to_string(cherrybombCost);
		s += "\n(S) Snowpea cost: ";
		s += std::to_string(snowpeaCost);

		return s;
	}

	void hideShop()
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 70; j++)
			{
				std::cout << ' ';
			}
		}
	}

	char buyFromShop(int x, int y)
	{
		if (x == 5 && playersMoney >= sunflowerCost)
		{
			playersMoney -= sunflowerCost;
			return 'F';
		}
		if (x == 9 && playersMoney >= peashooterCost)
		{
			playersMoney -= peashooterCost;
			return 'P';
		}
		if (x == 13 && playersMoney >= wallnutCost)
		{
			playersMoney -= wallnutCost;
			return 'W';
		}
		if (x == 17 && playersMoney >= cherrybombCost)
		{
			playersMoney -= cherrybombCost;
			return 'C';
		}
		if (x == 21 && playersMoney >= snowpeaCost)
		{
			playersMoney -= snowpeaCost;
			return 'S';
		}
		
		return ' ';
	}
	
	~Player();
};

