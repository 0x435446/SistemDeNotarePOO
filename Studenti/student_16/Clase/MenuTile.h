#pragma once
#include <string>
#include <vector>
using namespace std;
#define TILE_ROWS 3
#define TILE_COLS 14
class MenuTile
{
public:
	MenuTile(std::string, int, int, int, int);
	void draw();
	void hide();
	bool isPressed(int, int);
	std::string getFunc() const { return func; }
private:

	bool isVisible;
	std::string func;
	vector<vector<unsigned char>> mat;
	int startX, startY;
	int rows, cols;
	bool shown;
};
