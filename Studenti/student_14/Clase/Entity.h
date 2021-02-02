#pragma once

#include <iostream>
#include <string>

class Entity
{
 protected:
	 int damage;
	 int health;
	 std::string type;

 public:
	 Entity();
	 virtual ~Entity();
	 virtual void  attack() {}
	 virtual void set_j(int j, int i) {}
	 virtual int get_i() { return 0; }
	 virtual int get_j() { return 0; }
	 std::string get_name() { return this->type; }
	 virtual float get_speed() { return (float)0; }
	 int get_dmg() { return this->damage; }
	 int get_health() { return this->health; }
	 void set_health(int health) { this->health = health; }
};

//pentru Pea

class Pea : public Entity
{
public:
	Pea();
	~Pea();
	void attack();
	void set_j(int j, int i) { this->y = j; this->x = i; }
	int get_i() { return this->x; }
	int get_j() { return this->y; }
private:
	int y;
	int x;
};




//pentru sunflower
class Sunflower : public Entity
{
public:
	Sunflower();
	~Sunflower();
	void attack();
	void set_j(int j, int i) { this->y = j; this->x = i;}
	int get_i() { return this->x; }
	int get_j() { return this->y; }
private:
	int y;
	int x;
};

class Cherry : public Entity
{
public:
	Cherry();
	~Cherry();
	void attack();
	void set_j(int j, int i) { this->y = j; this->x = i;}
	int get_i() { return this->x; }
	int get_j() { return this->y; }
private:
	int y;
	int x;

};

class Wallnut : public Entity
{
public:
	Wallnut();
	~Wallnut();
	void attack();
	void set_j(int j, int i) { this->y = j; this->x = i;}
	int get_i() { return this->x; }
	int get_j() { return this->y; }
private:
	int y;
	int x;
};

class Snowpea : public Entity
{
public:
	Snowpea();
	~Snowpea();
	void attack();
	void set_j(int j, int i) { this->y = j; this->x = i;}
	int get_i() { return this->x; }
	int get_j() { return this->y; }
private:
	int y;
	int x;
};

class Zombie : public Entity
{
public:
	Zombie();
	~Zombie();

	void attack();
	void set_j(int j, int i){}
	float get_speed() { return this->speed; }
	int get_i() { return this->x; }
	int get_j() { return this->y; }

private:
	int y;
	int x;
	float speed;
};


class Zombie_bucket : public Entity
{
public:
	Zombie_bucket();
	~Zombie_bucket();

	void attack();
	void set_j(int j, int i) {}
	float get_speed() { return this->speed; }
	int get_i() { return this->x; }
	int get_j() { return this->y; }

private:
	int y;
	int x;
	float speed;
};

class PeaProjectile : public Entity
{
public:
	PeaProjectile();
	~PeaProjectile();

	void attack();
	void set_j(int j, int i) {}
	int get_i() { return this->x; }
	int get_j() { return this->y; }

private:
	int y;
	int x;
	float speed;
};

