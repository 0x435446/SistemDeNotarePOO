#pragma once

#include <vector>
#include <map>
#include <Windows.h>

#include "Logger.h"
#include "Exception.h"

namespace GameMechanics
{
	constexpr unsigned int COLS_NO = 9;
	constexpr unsigned int ROWS_NO = 5;

	enum class EntityID {
		ZOMBIE, BUCKETHEAD, POLEVAULTING, SUPERZOMBIE, PEASHOOTER,
		SUNFLOWER, CHERRYBOMB, WALLNUT, SNOWPEA, SUN, PEA, FROZENPEA, EXPLOSION, NONE,
		TILE, BORDERS, TITLE, FLOWERS, ZOMBIES, INFO
	};

	enum class PlantStatus { LOCKED, AVAILABLE, UNAVAILABLE, NOT_ENOUGH_RESOURCES, SELECTED };
	enum class GameStatus { LEVEL_CLEAR, LOSE, ONGOING };
	enum class EffectInflicted { NONE, FROZEN };

	const std::vector<EntityID> ENTITIES_ID = { EntityID::ZOMBIE, EntityID::BUCKETHEAD, EntityID::POLEVAULTING, EntityID::SUPERZOMBIE,
												EntityID::PEASHOOTER, EntityID::SUNFLOWER, EntityID::CHERRYBOMB, EntityID::WALLNUT, EntityID::SNOWPEA,
												EntityID::PEA, EntityID::FROZENPEA, EntityID::EXPLOSION, EntityID::NONE,
												EntityID::SUN };

	const std::vector<std::string> ENTITIES_NAMES = { "Zombie", "Buckethead zombie", "Polevaulting zombie ", "Super zombie", "Peashooter",
													  "Sunflower", "Cherry bomb", "Wallnut", "Snow pea", "Pea", "Frozen pea", "Explosion", "None", "Sun" };

	const std::vector<EntityID> ENEMIES_ID = { EntityID::ZOMBIE, EntityID::BUCKETHEAD, EntityID::POLEVAULTING, EntityID::SUPERZOMBIE };
	const std::vector<EntityID> PLANTS_ID = { EntityID::PEASHOOTER, EntityID::SUNFLOWER, EntityID::CHERRYBOMB, EntityID::WALLNUT, EntityID::SNOWPEA };
	const std::vector<EntityID> PROJECTILES_ID = { EntityID::PEA, EntityID::FROZENPEA, EntityID::EXPLOSION, EntityID::NONE };
	const std::vector<EntityID> RESOURCES_ID = { EntityID::SUN };
	const std::vector<EntityID> GRAPHICS_ID = { EntityID::TILE, EntityID::BORDERS, EntityID::TITLE, EntityID::FLOWERS, EntityID::ZOMBIES, EntityID::INFO };
	const std::vector<PlantStatus> PLANTS_STATUS = { PlantStatus::LOCKED, PlantStatus::AVAILABLE, PlantStatus::UNAVAILABLE, PlantStatus::NOT_ENOUGH_RESOURCES, PlantStatus::SELECTED };
	const std::vector<EffectInflicted> EFFECTS = { EffectInflicted::NONE, EffectInflicted::FROZEN };

	const std::vector<unsigned int> PLANTS_COST = { 100, 50, 150, 50, 150 };
	const std::vector<unsigned int> PLANTS_HP = { 100, 80, 40, 400, 100 };
	const std::vector<unsigned int> PLANTS_TIMEOUT = { 5, 6, 10, 12, 8 };
	const std::vector<unsigned int> PLANTS_SHOOTING_RATE = { 18, 0, 1, 0, 18 };
	const std::vector<unsigned int> RESOURCE_POINTS = { 25 };
	const std::vector<unsigned int> ENEMIES_DAMAGE = { 20, 20, 20, 20 };
	const std::vector<unsigned int> ENEMIES_HP = { 100, 160, 100, 160 };
	const std::vector<unsigned int> PROJECTILES_DAMAGE = { 20, 20, 120, 0 };
	const std::vector<unsigned int> PROJECTILES_SPEED = { 1, 1, 0, 0 };
	const std::vector<unsigned int> ENEMIES_SPEED = { 4, 4, 2, 2 };
	const std::vector<unsigned int> ENEMIES_AWARDED_POINTS = { 50, 75 , 75, 100 };
	const std::vector<unsigned int> ENEMIES_DEFAULT_NO = { 3, 1, 1, 1 };
	const std::vector<std::string> plantsNames = { "Peashooter", "Sunflower", "Cherry Bomb", "Wallnut", "Snow Pea" };

	constexpr unsigned int EFFECT_TIME = 6;
	constexpr unsigned int RESOURCE_DEFAULT_RATE = 10;
	constexpr unsigned int PAUSE_DEFAULT_TIME = 10;
	constexpr unsigned int SPAWNING_RATE = 15;

	template<class T>
	unsigned getIndex(std::vector<T> v, T obj)
	{
		auto it = std::find(v.begin(), v.end(), obj);
		if (it == v.end())
			throw Debugging::Exception(__func__, __FILE__, __LINE__, Debugging::OUT_OF_BOUNDS);
		return (unsigned)(it - v.begin());
	}
}

namespace UserInterface
{
	constexpr unsigned int AREA_COL_LEFT = 0;
	constexpr unsigned int AREA_ROW_UP = 0;
	constexpr unsigned int AREA_WIDTH = 209;
	constexpr unsigned int AREA_HEIGHT = 50;

	constexpr unsigned int TITLE_ROW_UP = 18;
	constexpr unsigned int TITLE_COL_LEFT = 1;

	constexpr unsigned int TILE_WIDTH = 14;
	constexpr unsigned int TILE_HEIGHT = 8;

	constexpr unsigned int ZOMBIE_WIDTH = 9;
	constexpr unsigned int SUNFLOWER_WIDTH = 9;
	constexpr unsigned int PEASHOOTER_WIDTH = 11;
	constexpr unsigned int WALLNUT_WIDTH = 11;
	constexpr unsigned int CHERRYBOMB_WIDTH = 12;
	constexpr unsigned int PEA_WIDTH = 10;
	constexpr unsigned int SUN_WIDTH = 12;
	constexpr unsigned int EXPLOSION_WIDTH = 12;

	constexpr unsigned int SPACE_DIST = 2;

	constexpr unsigned int RESOURCE_AREA_ROW_UP = 1;
	constexpr unsigned int BOARD_ROW_UP = 10;
	constexpr unsigned int PLANT_AREA_ROW_UP = BOARD_ROW_UP;
	constexpr unsigned int BOARD_COL_LEFT = 69;
	constexpr unsigned int RESOURCE_AREA_COL_LEFT = BOARD_COL_LEFT;
	constexpr unsigned int PLANT_AREA_COL_LEFT = 52;

	constexpr unsigned int SAVE_ROW_UP = 33;
	constexpr unsigned int LOAD_ROW_UP = SAVE_ROW_UP;
	constexpr unsigned int SAVE_COL_LEFT = 6;
	constexpr unsigned int LOAD_COL_LEFT = 18;
	constexpr unsigned int SAVE_WIDTH = 4;
	constexpr unsigned int LOAD_WIDTH = SAVE_WIDTH;

	constexpr unsigned int PLANT_INFO_COL_LEFT = 36;
	constexpr unsigned int PLANT_INFO_ROW_UP = 12;

	constexpr unsigned int BORDER_FLOWERS_COL_LEFT = 1;
	constexpr unsigned int BORDER_FLOWERS_ROW_UP = 2;
	constexpr unsigned int BORDER_ZOMBIES_COL_LEFT = BORDER_FLOWERS_COL_LEFT;
	constexpr unsigned int BORDER_ZOMBIES_ROW_UP = 40;

	constexpr unsigned int SCORE_INFO_COL_LEFT = 31;
	constexpr unsigned int SCORE_INFO_ROW_UP = 2;

	constexpr unsigned int LEVEL_INFO_COL_LEFT = 11;
	constexpr unsigned int LEVEL_INFO_ROW_UP = 14;

	constexpr unsigned int PLAYER_INFO_COL_LEFT = 3;
	constexpr unsigned int PLAYER_INFO_ROW_UP = 26;

	constexpr unsigned int LOGIN_COL_LEFT = 100;
	constexpr unsigned int LOGIN_ROW_UP = 20;

	enum ConsoleColors
	{
		BlackFore = 0,
		MaroonFore = FOREGROUND_RED,
		GreenFore = FOREGROUND_GREEN,
		NavyFore = FOREGROUND_BLUE,
		TealFore = FOREGROUND_GREEN | FOREGROUND_BLUE,
		OliveFore = FOREGROUND_RED | FOREGROUND_GREEN,
		PurpleFore = FOREGROUND_RED | FOREGROUND_BLUE,
		GrayFore = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		SilverFore = FOREGROUND_INTENSITY,
		RedFore = FOREGROUND_INTENSITY | FOREGROUND_RED,
		LimeFore = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
		BlueFore = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
		AquaFore = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
		YellowFore = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
		FuchsiaFore = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
		WhiteFore = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,

		BlackBack = 0,
		MaroonBack = BACKGROUND_RED,
		GreenBack = BACKGROUND_GREEN,
		NavyBack = BACKGROUND_BLUE,
		TealBack = BACKGROUND_GREEN | BACKGROUND_BLUE,
		OliveBack = BACKGROUND_RED | BACKGROUND_GREEN,
		PurpleBack = BACKGROUND_RED | BACKGROUND_BLUE,
		GrayBack = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
		SilverBack = BACKGROUND_INTENSITY,
		RedBack = BACKGROUND_INTENSITY | BACKGROUND_RED,
		LimeBack = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
		BlueBack = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
		AquaBack = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
		YellowBack = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
		FuchsiaBack = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
		WhiteBack = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
	};
}