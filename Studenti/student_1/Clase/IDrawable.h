#pragma once

namespace UserInterface
{
	class IDrawable
	{
	protected:
		unsigned rowUp;
		unsigned colLeft;
		unsigned width;

	public:
		IDrawable(int, int);
		virtual ~IDrawable();

		virtual void draw() = 0;
		virtual void draw(char) = 0;
		unsigned getRowUp();
		unsigned getColLeft();
		unsigned getWidth();
	};
}
