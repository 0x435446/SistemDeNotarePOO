#include "Player.h"

Player::Player()
{
}

Player::Player(std::string Name,std::string Password)
{
	pName = Name;
	pPassword = Password;
	pScore = 0;
}

void Player::SetScore(int score)
{
	pScore = score;
}

int Player::GetScore()
{
	return pScore;
}

string Player::Return_User()
{
	string score = std::to_string(pScore);
	string str = pName;
	str = str + " ";
	str = str + pPassword;
	str = str + " ";
	str = str + score;
	return str;
}

Player::~Player()
{
}
