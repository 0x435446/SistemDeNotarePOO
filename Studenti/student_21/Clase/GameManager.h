#pragma once
#include "Prefab.h"

class ZombieSpawner :
	public Object
{
	std::list<InteractableObject*>& pResources;
	std::list<Physical*>& pZombies;
	std::list<Physical*>& pPlants;
	int noZ = 1000;
public:
	ZombieSpawner(std::list<InteractableObject*>& pResources,
		std::list<Physical*>& pZombies,
		std::list<Physical*>& pPlants) : pZombies(pZombies), pPlants(pPlants), pResources(pResources) {}
	void Update() override final
	{
		int x = rand() % 10000;
		if (x % noZ == 1)
		{
			C2D::Vector2 newPosition = C2D::Vector2(140, (x % 5) * CELL_H);
			newPosition.snapToGrid();
			switch (x % 4)
			{
			case 0:
			{
				pZombies.push_back(new Prefab<PremadeObjects::BucketZombie>(pZombies, newPosition, pPlants, pResources));
				noZ--;
				break;
			}
			case 1:
			{
				pZombies.push_back(new Prefab<PremadeObjects::NormalZombie>(pZombies, newPosition, pPlants, pResources));
				noZ -= 2;
				break;
			}
			case 2:
			{
				pZombies.push_back(new Prefab<PremadeObjects::JumpingZombie>(pZombies, newPosition, pPlants, pResources));
				noZ -= 4;
				break;
			}
			case 3:
			{
				pZombies.push_back(new Prefab<PremadeObjects::SuperZombie>(pZombies, newPosition, pPlants, pResources));
				noZ -= 10;
				break;
			}
			}
		}
	}
	void Start() override {}
	void End() override {}
};

class ResourceSpawner :
	public Object
{
	std::list<InteractableObject*>& pResources;
public:
	ResourceSpawner(std::list<InteractableObject*>& pResources):
		pResources(pResources) {}
	void Update() override final
	{
		int x = rand() % 10000;
		if (x % 417 == 1)
		{
			C2D::Vector2 newPosition = C2D::Vector2((x%9+2)* CELL_W, 0);
			pResources.push_back(new Prefab<PremadeObjects::Sun>(pResources,newPosition, UserData::_getInGameCurrencyAccess()));
		}
	}
	void Start() override {}
	void End() override {}
};

class MapManager :
	public Object
{
	ConsoleHandlerV2& localHandler = ConsoleHandlerV2::getInstance();
	UserData& localData = UserData::getInstance();
	int& currency = localData._getCurrency();
	int& inGameCurrency = localData._getInGameCurrency();
public:
	MapManager() = default;
	~MapManager()
	{
		localHandler.releaseInstance();
		localData.releaseInstance();
	}
	void Update() override final
	{
		for (int i = 16; i < 155; i++)
		{
			localHandler.updateConsoleBuffer('_', 15, i, 6);
			localHandler.updateConsoleBuffer('_', 15, i, 14);
			localHandler.updateConsoleBuffer('_', 15, i, 22);
			localHandler.updateConsoleBuffer('_', 15, i, 30);
			localHandler.updateConsoleBuffer('_', 15, i, 38);
		}
		for (int i = 0; i < 42; i++)
		{
			//	myh(15, i) << char(176);
			localHandler.updateConsoleBuffer(char(176), 15, 15, i);
		}
		localHandler.updateConsoleBuffer('$', 14, 88, 40);
		localHandler.updateConsoleBuffer(currency / 100 + '0', 14, 90, 40);
		localHandler.updateConsoleBuffer((currency / 10) % 10 + '0', 14, 91, 40);
		localHandler.updateConsoleBuffer(currency % 10 + '0', 14, 92, 40);
		localHandler.updateConsoleBuffer(inGameCurrency / 100 + '0', 14, 2, 40);
		localHandler.updateConsoleBuffer((inGameCurrency / 10) % 10 + '0', 14, 3, 40);
		localHandler.updateConsoleBuffer(inGameCurrency % 10 + '0', 14, 4, 40);
	}
	void Start() override {}
	void End() override {}
};

class GameManager:
	public Object
{
	std::list<InteractableObject*> pCards;
	std::list<InteractableObject*> pResources;
	std::list<Physical*> pZombies;
	std::list<Physical*> pPlants;
	std::list<Physical*> pBullets;
	std::list<Physical*> pExplosions;
	MapManager mapManager;
	ZombieSpawner zombieSpawner;
	ResourceSpawner resourceSpawner;
	UserData& localData = UserData::getInstance();
public:
	GameManager() : zombieSpawner(pResources, pZombies, pPlants), resourceSpawner(pResources)
	{
		Init();
	}
	~GameManager()
	{
		localData.releaseInstance();
	}
	void Update() override final
	{
		std::list<InteractableObject*>::iterator prev;
		std::list<Physical*>::iterator prew; /// u didn't see this coming
		mapManager.Update();
		zombieSpawner.Update();
		resourceSpawner.Update();
		for (auto i = pCards.begin(); i != pCards.end();)
		{
			prev = i++;
			(*prev)->Update();
		}
		for (auto i = pResources.begin(); i != pResources.end();)
		{
			prev = i++;
			(*prev)->Update();
		}
		for (auto i = pZombies.begin(); i != pZombies.end();)
		{
			prew = i++;
			(*prew)->Update();
		}
		for (auto i = pPlants.begin(); i != pPlants.end();)
		{
			prew = i++;
			(*prew)->Update();
		}
		for (auto i = pBullets.begin(); i != pBullets.end();)
		{
			prew = i++;
			(*prew)->Update();
		}
		for (auto i = pExplosions.begin(); i != pExplosions.end();)
		{
			prew = i++;
			(*prew)->Update();
		}
	}
	void Start() override final
	{
		std::list<InteractableObject*>::iterator prev;
		std::list<Physical*>::iterator prew; /// u didn't see this coming aswell
		for (auto i = pCards.begin(); i != pCards.end();)
		{
			prev = i++;
			(*prev)->Start();
		}
		for (auto i = pResources.begin(); i != pResources.end();)
		{
			prev = i++;
			(*prev)->Start();
		}
		for (auto i = pZombies.begin(); i != pZombies.end();)
		{
			prew = i++;
			(*prew)->Start();
		}
		for (auto i = pPlants.begin(); i != pPlants.end();)
		{
			prew = i++;
			(*prew)->Start();
		}
		for (auto i = pBullets.begin(); i != pBullets.end();)
		{
			prew = i++;
			(*prew)->Start();
		}
		for (auto i = pExplosions.begin(); i != pExplosions.end();)
		{
			prew = i++;
			(*prew)->Start();
		}
	}
	void End() override final
	{

	}
private:
	void Init()
	{
		pCards.push_back(new Prefab <PremadeObjects::UsableCard, PremadeObjects::SunFlower>(pCards, pPlants, pZombies, pResources, C2D::Vector2(0, 7), localData._getInGameCurrency()));
		pCards.push_back(new Prefab <PremadeObjects::UsableCard, PremadeObjects::PeaShooter>(pCards, pPlants, pZombies, pBullets, C2D::Vector2(0, 15)));
		pCards.push_back(new Prefab <PremadeObjects::UsableCard, PremadeObjects::WalNut>(pCards, pPlants, pZombies, C2D::Vector2(0, 23)));
		pCards.push_back(new Prefab <PremadeObjects::UsableCard, PremadeObjects::IceShooter>(pCards, pPlants, pZombies, pBullets, C2D::Vector2(0, 31)));
		pCards.push_back(new Prefab <PremadeObjects::UsableCard, PremadeObjects::CherryBomb>(pCards, pPlants, pZombies, pExplosions, C2D::Vector2(0, 39)));
	}
};

