#pragma once

#include <vector>

namespace UserInterface
{
	class Sprite
	{
	private:
		std::vector< std::pair <std::string, int> > parts;
		Sprite(Sprite&);

	public:
		Sprite(std::vector< std::pair <std::string, int> >);
		~Sprite();

		void show(int row, int col);
		void show(int row, int col, char overrideChar);
	};
}
