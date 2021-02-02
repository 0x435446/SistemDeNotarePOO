#pragma once

namespace GameMechanics
{
	class IDamaging
	{
	protected:
		unsigned damage;

	public:
		IDamaging();
		~IDamaging();

		unsigned causeDamage();
	};
}

