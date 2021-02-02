#pragma once
#include "Zombie.h"
#include "Plant.h"
#include "Weapon.h"
#include "UsableCard.h"
#include "Explosion.h"
#include "Sun.h"
#include "Money.h"
#include "UserData.h"
enum class PremadeObjects
{
	_Null,
	_Exit,
	_Reset,
	BucketZombie, //
	CherryBomb, //
	IceShooter, //
	JumpingZombie, //
	NormalZombie, //
	PeaShooter, //
	SunFlower, //
	SuperZombie, //
	WalNut, //
	NormalBullet, //
	FrozenBullet, //
	UsableCard, //
	Explosion, //
	Sun, //
	SilverCoin, //
	PlayButton, //
	ExitButton,
	GameScene, //
	MenuScene, //
};
template <PremadeObjects mainType, PremadeObjects secondaryType = PremadeObjects::_Null>
class Prefab {};

////// RESOURCES

template<>
class Prefab<PremadeObjects::Sun> :
	public Sun
{
public:
	Prefab(std::list<InteractableObject*>& groupBoundTo,
		C2D::Vector2 position, int& inGameCurrency) :
		Sun(groupBoundTo, "Sprites/SunResource.sprite", position, 1, 25, inGameCurrency) {}
	Prefab(std::list<InteractableObject*>& groupBoundTo,
		C2D::Vector2 position,
		int steps, int& inGameCurrency) :
		Sun(groupBoundTo, "Sprites/SunResource.sprite", position, 1, steps, 25, inGameCurrency) {}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}
	void Start() override {
		Sun::Start();
	}
	void Update() override {
		Sun::Update();
	}
};

template<>
class Prefab<PremadeObjects::SilverCoin> :
	public Money
{
public:
	Prefab(std::list<InteractableObject*>& groupBoundTo,
		C2D::Vector2 position) :
		Money(groupBoundTo, "Sprites/SilverCoin.sprite", position, 50)
	{}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}
};

////// PROJECTILES
template<>
class Prefab<PremadeObjects::NormalBullet> :
	public Projectile
{
public:
	Prefab(std::list<Physical*>& groupBoundTo,
		C2D::Vector2 position,
		const std::list<Physical*>& everyZombieObject) :
		Projectile(groupBoundTo, "Sprites/NormalBullet.sprite", position, everyZombieObject, 60 /*SPEED*/, 1 /*DAMAGE*/)
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}
};
template<>
class Prefab<PremadeObjects::FrozenBullet> :
	public Projectile
{
public:
	Prefab(std::list<Physical*>& groupBoundTo,
		C2D::Vector2 position,
		const std::list<Physical*>& everyZombieObject) :
		Projectile(groupBoundTo, "Sprites/FrozenBullet.sprite", position, everyZombieObject, 60 /*SPEED*/, 1 /*DAMAGE*/)
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}
};

////// ZOMBIES
template<>
class Prefab<PremadeObjects::BucketZombie> :
	public virtual Zombie
{
public:
	Prefab(std::list<Physical*>& groupBoundTo,
		C2D::Vector2 position,
		const std::list<Physical*>& everyPlant,
		std::list<InteractableObject*>& pCurrency) :
		Zombie(groupBoundTo, "Sprites/BucketZombie.sprite", position, everyPlant, pCurrency, 2 /* DAMAGE */, 2 /* SPEED */, 0 /* DIRECTION = LEFT */, 30 /* HP */)
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Zombie&) = delete;
	Prefab& operator= (const Zombie&) = delete;
	virtual ~Prefab() 
	{
		int random = rand() % 1000;
		random = 1;
		if (random == 1)
			pCurrency.push_back(new Prefab<PremadeObjects::SilverCoin>(pCurrency, _transform().getPosition()));
	}
};
template<>
class Prefab<PremadeObjects::JumpingZombie> :
	public virtual Zombie
{
	bool hasJumped;
public:
	Prefab(std::list<Physical*>& groupBoundTo,
		C2D::Vector2 position,
		const std::list<Physical*>& everyPlant,
		std::list<InteractableObject*>& pCurrency) :
		Zombie(groupBoundTo, "Sprites/JumpingZombie.sprite", position, everyPlant, pCurrency, 1 /* DAMAGE */, 16 /* SPEED */, 0 /* DIRECTION = LEFT */, 8 /* HP */),
		hasJumped(false)
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Zombie&) = delete;
	Prefab& operator= (const Zombie&) = delete;
	virtual ~Prefab() 
	{
		int random = rand() % 1000;
		random = 1;
		if (random == 1)
			pCurrency.push_back(new Prefab<PremadeObjects::SilverCoin>(pCurrency, _transform().getPosition()));
	}

	void onCollide(Physical& object) override final
	{
		if (hasJumped)
		{
			Zombie::onCollide(object);
		}
		else
		{
			hasJumped = true;
			C2D::Vector2 newPosition = _transform().getPosition();
			newPosition.setX(_transform().getPosition().getX() - _transform().getSize().getX() - object._transform().getSize().getX());
			_transform().setPosition(newPosition);
		}
	}
};
template<>
class Prefab<PremadeObjects::NormalZombie> :
	public virtual Zombie
{
public:
	Prefab(std::list<Physical*>& groupBoundTo,
		C2D::Vector2 position,
		const std::list<Physical*>& everyPlant,
		std::list<InteractableObject*>& pCurrency) :
		Zombie(groupBoundTo, "Sprites/NormalZombie.sprite", position, everyPlant, pCurrency, 1 /* DAMAGE */, 3 /* SPEED */, 0 /* DIRECTION = LEFT */, 10 /* HP */)
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Zombie&) = delete;
	Prefab& operator= (const Zombie&) = delete;
	virtual ~Prefab() 
	{
		int random = rand() % 1000;
		random = 1;
		if (random == 1)
			pCurrency.push_back(new Prefab<PremadeObjects::SilverCoin>(pCurrency, _transform().getPosition()));
	}
};
template<>
class Prefab<PremadeObjects::SuperZombie> :
	public virtual Prefab<PremadeObjects::BucketZombie>,
	public virtual Prefab<PremadeObjects::JumpingZombie>
{
public:
	Prefab(std::list<Physical*>& groupBoundTo,
		C2D::Vector2 position,
		const std::list<Physical*>& everyPlant,
		std::list<InteractableObject*>& pCurrency) :
		Prefab<PremadeObjects::BucketZombie>(groupBoundTo, position, everyPlant, pCurrency),
		Prefab<PremadeObjects::JumpingZombie>(groupBoundTo, position, everyPlant, pCurrency),
		Zombie(groupBoundTo, "Sprites/SuperZombie.sprite", position, everyPlant, pCurrency, 3 /* DAMAGE */, 6 /* SPEED */, 0 /* DIRECTION = LEFT */, 30 /* HP */)
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Zombie&) = delete;
	Prefab& operator= (const Zombie&) = delete;
	virtual ~Prefab() 
	{
		int random = rand() % 1000;
		random = 1;
		if (random == 1)
			pCurrency.push_back(new Prefab<PremadeObjects::SilverCoin>(pCurrency, _transform().getPosition()));
	}
};
////// EXPLOSIONS
template<>
class Prefab<PremadeObjects::Explosion> :
	public Explosion
{
public:
	Prefab(std::list<Physical*>& groupBoundTo,
		C2D::Vector2 position,
		const std::list<Physical*>& everyZombieObject) : 
		Explosion(groupBoundTo, "Sprites/Explosion.sprite", position, everyZombieObject, 0, 30) {}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() = default;
};
////// PLANTS
template<>
class Prefab<PremadeObjects::CherryBomb> :
	public Plant
{
	int timer = 50;
	std::list<Physical*>& explosions;
	std::list<Physical*>& __zombies;
public:
	Prefab(std::list<Physical*>& groupBoundTo,
		C2D::Vector2 position,
		std::list<Physical*>& zombieList,
		std::list<Physical*>& explosions) :
		Plant(groupBoundTo, "Sprites/CherryBomb.sprite", position, zombieList, 3),
		explosions(explosions),
		__zombies(zombieList)
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}
	void Update() override final
	{
		if (timer < 0)
		{
			_mark_for_death();
			explode();
		}
		--timer;
		Plant::Update();
	}
private:
	void explode()
	{
		C2D::Vector2 newPos = _transform().getPosition();
		newPos.setX(newPos.getX() - CELL_W);
		newPos.setY(newPos.getY() + CELL_H);
		newPos.snapToGrid();
		explosions.push_back(new Prefab<PremadeObjects::Explosion>(explosions, newPos, __zombies));
	}
};
template<>
class Prefab<PremadeObjects::IceShooter> :
	public Plant
{
	Weapon<Prefab<PremadeObjects::FrozenBullet>, Physical> localWeapon;
public:
	Prefab(std::list<Physical*>& groupBoundTo,
		C2D::Vector2 position,
		std::list<Physical*>& zombieList,
		std::list<Physical*>& bulletList) :
		Plant(groupBoundTo, "Sprites/IceShooter.sprite", position, zombieList, 10),
		localWeapon(bulletList, _transform(), 1, zombieList) 
	{
		localWeapon._set_position(_transform().getPosition());
		AddComponent<Weapon<Prefab<PremadeObjects::FrozenBullet>, Physical>>(&localWeapon);
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}
};
template<>
class Prefab<PremadeObjects::PeaShooter> :
	public Plant
{
	Weapon<Prefab<PremadeObjects::NormalBullet>, Physical> localWeapon;
public:
	Prefab(std::list<Physical*>& groupBoundTo,
		C2D::Vector2 position,
		std::list<Physical*>& zombieList,
		std::list<Physical*>& bulletList):
		Plant(groupBoundTo, "Sprites/PeaShooter.sprite", position, zombieList, 10),
		localWeapon(bulletList, _transform(), 1, zombieList)
	{
		localWeapon._set_position(_transform().getPosition());
		AddComponent <Weapon<Prefab<PremadeObjects::NormalBullet>, Physical>>(&localWeapon);
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}
};
template<>
class Prefab<PremadeObjects::SunFlower> :
	public Plant
{
	std::list<InteractableObject*>& resourceList;
	int spawnDelay;
	int& inGameCurrency;
public:
	Prefab(std::list<Physical*>& groupBoundTo,
		C2D::Vector2 position,
		std::list<Physical*>& zombieList,
		std::list<InteractableObject*>& resourceList,
		int& inGameCurrency) :
		Plant(groupBoundTo, "Sprites/SunFlower.sprite", position, zombieList, 6),
		spawnDelay(1000),
		resourceList(resourceList),
		inGameCurrency(inGameCurrency)
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}

	void Update() override final
	{
		--spawnDelay;
		if (spawnDelay == 0)
		{
			spawnDelay = 1000;
			resourceList.push_back(new Prefab<PremadeObjects::Sun>(resourceList, 
					C2D::Vector2(_transform().getPosition().getX() + _transform().getSize().getX(), 
					_transform().getPosition().getY() - 2), 
					400, 
					inGameCurrency));
		}
		Plant::Update();
	}
private:
	void spawnSun()
	{

	}
};
template<>
class Prefab<PremadeObjects::WalNut> :
	public Plant
{
public:
	Prefab(std::list<Physical*>& groupBoundTo,
		C2D::Vector2 position,
		std::list<Physical*>& zombieList) :
		Plant(groupBoundTo, "Sprites/WalNut.sprite", position, zombieList, 40)
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}
};

////// USABLE CARDS

template<>
class Prefab<PremadeObjects::UsableCard, PremadeObjects::CherryBomb> :
	public UsableCard
{
	std::list<Physical*>& plants;
	std::list<Physical*>& zombies;
	std::list<Physical*>& explosions;
public:
	Prefab(std::list<InteractableObject*>& groupBoundTo,
		std::list<Physical*>& plants,
		std::list<Physical*>& zombies,
		std::list<Physical*>& explosions,
		C2D::Vector2 position) :
		UsableCard(groupBoundTo, "Sprites/CardFrame.sprite", 
			position, 
			"Sprites/CherryBomb.sprite", 150),
		plants(plants),
		zombies(zombies),
		explosions(explosions)
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}
	void onClickOutOfRange() override final
	{
		if (is_selected)
		{
			C2D::Vector2 pos = _get_mouse_position();
			pos.snapToGrid();
			if (pos.getX() >= 15 && pos.getX() < 150 && pos.getY() < 40 && checkTile<Physical>(pos, plants))
			{
				buy();
				plants.push_back(new Prefab<PremadeObjects::CherryBomb>(plants, pos, zombies, explosions));
			}
		}
		UsableCard::onClickOutOfRange();
	}
};

template<>
class Prefab<PremadeObjects::UsableCard, PremadeObjects::IceShooter> :
	public UsableCard
{
	std::list<Physical*>& plants;
	std::list<Physical*>& zombies;
	std::list<Physical*>& bullets;
public:
	Prefab(std::list<InteractableObject*>& groupBoundTo,
		std::list<Physical*>& plants,
		std::list<Physical*>& zombies,
		std::list<Physical*>& bullets,
		C2D::Vector2 position) :
		UsableCard(groupBoundTo, "Sprites/CardFrame.sprite",
			position,
			"Sprites/IceShooter.sprite", 175),
		plants(plants),
		zombies(zombies), 
		bullets(bullets)
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}
	void onClickOutOfRange() override final
	{
		if (is_selected)
		{
			C2D::Vector2 pos = _get_mouse_position();
			pos.snapToGrid();
			if (pos.getX() >= 15 && pos.getX() < 150 && pos.getY() < 40 && checkTile<Physical>(pos, plants))
			{
				buy();
				plants.push_back(new Prefab<PremadeObjects::IceShooter>(plants, pos, zombies, bullets));
			}
		}
		UsableCard::onClickOutOfRange();
	}
};

template<>
class Prefab<PremadeObjects::UsableCard, PremadeObjects::PeaShooter> :
	public UsableCard
{
	std::list<Physical*>& plants;
	std::list<Physical*>& zombies;
	std::list<Physical*>& bullets;
public:
	Prefab(std::list<InteractableObject*>& groupBoundTo,
		std::list<Physical*>& plants,
		std::list<Physical*>& zombies,
		std::list<Physical*>& bullets,
		C2D::Vector2 position) :
		UsableCard(groupBoundTo, "Sprites/CardFrame.sprite",
			position,
			"Sprites/PeaShooter.sprite", 100),
		plants(plants),
		zombies(zombies), 
		bullets(bullets)
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}
	void onClickOutOfRange() override final
	{
		if (is_selected)
		{
			C2D::Vector2 pos = _get_mouse_position();
			pos.snapToGrid();
			if (pos.getX() >= 15 && pos.getX() < 150 && pos.getY() < 40 && checkTile<Physical>(pos, plants))
			{
				buy();
				plants.push_back(new Prefab<PremadeObjects::PeaShooter>(plants, pos, zombies, bullets));
			}
		}
		UsableCard::onClickOutOfRange();
	}
};

template<>
class Prefab<PremadeObjects::UsableCard, PremadeObjects::SunFlower> :
	public UsableCard
{
	std::list<Physical*>& plants;
	std::list<Physical*>& zombies;
	std::list<InteractableObject*>& resourceList;
	int& inGameCurrency;
public:
	Prefab(std::list<InteractableObject*>& groupBoundTo,
		std::list<Physical*>& plants,
		std::list<Physical*>& zombies,
		std::list<InteractableObject*>& resourceList,
		C2D::Vector2 position,
		int& inGameCurrency) :
		UsableCard(groupBoundTo, "Sprites/CardFrame.sprite",
			position,
			"Sprites/SunFlower.sprite", 50),
		plants(plants),
		zombies(zombies),
		resourceList(resourceList),
		inGameCurrency(inGameCurrency)
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}
	void onClickOutOfRange() override final
	{
		if (is_selected)
		{
			C2D::Vector2 pos = _get_mouse_position();
			pos.snapToGrid();
			if (pos.getX() >= 15 && pos.getX() < 150 && pos.getY() < 40 && checkTile<Physical>(pos, plants))
			{
				buy();
				plants.push_back(new Prefab<PremadeObjects::SunFlower>(plants, pos, zombies, resourceList, inGameCurrency));
			}
		}
		UsableCard::onClickOutOfRange();
	}
};

template<>
class Prefab<PremadeObjects::UsableCard, PremadeObjects::WalNut> :
	public UsableCard
{
	std::list<Physical*>& plants;
	std::list<Physical*>& zombies;
public:
	Prefab(std::list<InteractableObject*>& groupBoundTo,
		std::list<Physical*>& plants,
		std::list<Physical*>& zombies,
		C2D::Vector2 position) :
		UsableCard(groupBoundTo, "Sprites/CardFrame.sprite",
			position,
			"Sprites/WalNut.sprite", 75),
		plants(plants),
		zombies(zombies) 
	{
		Prefab::Start();
	}
	Prefab() = delete;
	Prefab(const Prefab&) = delete;
	Prefab& operator= (const Prefab&) = delete;
	virtual ~Prefab() {}
	void onClickOutOfRange() override final
	{
		if (is_selected)
		{
			C2D::Vector2 pos = _get_mouse_position();
			pos.snapToGrid();
			if (pos.getX() >= 15 && pos.getX() < 150 && pos.getY() < 40 && checkTile<Physical>(pos, plants))
			{
				buy();
				plants.push_back(new Prefab<PremadeObjects::WalNut>(plants, pos, zombies));
			}
		}
		UsableCard::onClickOutOfRange();
	}
};

