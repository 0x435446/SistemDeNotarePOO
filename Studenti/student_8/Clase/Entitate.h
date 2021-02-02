#pragma once
class Sunflower;
class PeaShooter;
class Proiectil;
class Zombie;
class ZombieB;
class Entitate
{
protected :
	Entitate();
public:
	
	virtual void Fight(Entitate &E) = 0;
	virtual void FightWith(Zombie &z) = 0;
	virtual void FightWith(Sunflower &S) = 0;
	virtual void FightWith(ZombieB &Z) = 0;
	virtual void FightWith(PeaShooter &P) = 0;
	virtual void FightWith(Proiectil &Pr) = 0;
	~Entitate();
};

