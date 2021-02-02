#pragma once
#include "GameSpecifications.h"
#include "IDrawable.h"
#include "ISerializable.h"

namespace GameMechanics
{
	class Entity :
		public UserInterface::IDrawable, public ISerializable
	{
	protected:
		EntityID ID;

	public:
		Entity(int, int);
		~Entity();

		void draw() override;
		void draw(char) override;

		EntityID getID();
	};
}
