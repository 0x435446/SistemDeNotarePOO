#pragma once
#include <string>
#include "Resource.h"
#include "Plant.h"

#define DEFAULT_RESOURCES 500

class Player
{
public:
	Player(std::string username);
	~Player();
	std::string GetUsername() const;
	int GetResources() const;
	int GetScore() const;

	void CollectResources(Resource& resource);
	void PlantThis(Plant& plant);
private:
	std::string m_username;
	int m_resources;
	int m_score;
};