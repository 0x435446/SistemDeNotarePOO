#include "Player.h"
#include "Exception.h"

Player::Player(std::string username) : m_resources(DEFAULT_RESOURCES), m_score(0)
{
}

Player::~Player()
{
}

std::string Player::GetUsername() const
{
	return std::string(this->m_username);
}

int Player::GetResources() const
{
	return this->m_resources;
}

int Player::GetScore() const
{
	return this->m_score;
}

void Player::CollectResources(Resource& resource)
{
	this->m_resources += resource.GetValue();
}

void Player::PlantThis(Plant& plant)
{
	if (this->m_resources < plant.GetCost())
		throw Exception("Not enough resources");
	else
		this->m_resources -= plant.GetCost();
}
