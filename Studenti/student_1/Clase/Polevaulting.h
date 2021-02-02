#pragma once
#include "Zombie.h"

namespace GameMechanics
{
	class Polevaulting :
		virtual public Zombie
	{
	protected:
		bool jumped;

	public:
		Polevaulting(int, int);
		~Polevaulting();

		void move() override;
		bool hasJumped() override;
		void setJumped(bool) override;

		std::string serialize() override;
	};
}
