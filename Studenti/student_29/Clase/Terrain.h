#pragma once
#include <vector>
#include <iostream>
#include "Sun.h"
#include "Plant.h"
#include <time.h>
#include "NormalZombie.h"
#include "Pea.h"
#include "Log.h"
#include "BucketHead.h"

class Terrain final
{
	char** matrix;

	std::vector<std::pair<int, int>> available_plant_slots;
	std::vector<std::pair<int, int>> available_sun_slots;

	std::vector<std::pair<int, int>> unavailable_plant_slots;
	std::vector<std::pair<int, int>> unavailable_sun_slots;

	std::vector<std::pair<int, int>> shop_slots;

	std::vector<Sun> suns;
	std::vector<Entity*> entity_list;
	std::vector<Pea> peas;

	UserInterface::Log* logger;

	int s[9];

	int rows;
	int columns;
	int level;
	int score = 0;

	int zombie_counter;
	int bucket_head_counter;

	static Terrain* instance;

	Terrain(const unsigned int&);
	Terrain(const Terrain&);
	~Terrain();
public:
	static Terrain& getTerrain(const unsigned int&);
	void deleteTerrain();
	void generateTerrain();

	int returnScore() const { return score; };

	void entitiesStillAlive();
	void printEntities();

	void setAvailablePlantSlots();
	void setAvailableSunSlots();
	void setShopSlots();

	int numberOfSunflowers();

	void entityAtacks();
	void generateSuns();
	void generateZombies();
	void generateBucketHeadZombies();

	void updateSunSlots(const std::string&, const Sun&, const int&);
	void updateSunSlots(const std::string&, const int&, const int&);
	void updatePlantSlots(const std::string&, Entity*);

	std::vector<Entity*> checkEntities() const { return entity_list; };
	std::vector<std::pair<int, int>> checkShopSlots() const { return shop_slots; };
	std::vector<std::pair<int, int>> checkAvailableSunSlots() const { return available_sun_slots; };
	std::vector<std::pair<int, int>> checkUnavailableSunSlots() const { return unavailable_sun_slots; };
	std::vector<std::pair<int, int>> checkAvailablePlantSlots() const { return available_plant_slots; };
	std::vector<std::pair<int, int>> checkUnavailablePlantSlots() const { return unavailable_plant_slots; };
};

