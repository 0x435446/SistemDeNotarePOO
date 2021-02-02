#pragma once
#include "Ability.h"
class AbMakeSun :
	public Ability
{
public:
	virtual void Use(Panel&) override {};
	//as fi facut fiecare Plana producatoare de Sun sa spawneze Sun independent in functie de un interval stabilit tinand cont de cand a fost Planta creata
	//pentru ca cerinta nu a cerut-o si din lipsa de timp, nu am implementat asta

	static bool getSunTime(int);
	//static std::chrono::time_point<std::chrono::steady_clock> Start;
};

