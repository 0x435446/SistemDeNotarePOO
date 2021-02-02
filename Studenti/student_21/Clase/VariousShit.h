#pragma once
#define CELL_W 15
#define CELL_H 8
namespace C2D
{
	class Vector2
	{
		int X;
		int Y;
	public:
		Vector2() : X(0), Y(0) {}
		Vector2(int X, int Y) : X(X), Y(Y) {}
		Vector2(const Vector2& copy) : X(copy.X), Y(copy.Y) {}
		Vector2& operator=(const Vector2&) = delete; // no need for this
		~Vector2() {}

		int getX() const { return X; }
		int getY() const { return Y; }

		void snapToGrid()
		{
			setX((getX() / CELL_W) * CELL_W + CELL_W / 3);
			setY((getY() / CELL_H) * CELL_H + CELL_H / 2 + 1); // whatever
		}

		void setX(int x) { X = x; }
		void setY(int y) { Y = y; }
		void setXY(int x, int y) { X = x; Y = y; }
		void setXY(const Vector2& copy) { X = copy.X; Y = copy.Y; }
	};
	
}
