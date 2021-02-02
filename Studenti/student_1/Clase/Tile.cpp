#include "Tile.h"

using namespace GameMechanics;

Tile::Tile(int rowUp, int colLeft): Graphics (rowUp, colLeft)
{
	this->ID = EntityID::TILE;
	this->width = UserInterface::TILE_WIDTH;
}


Tile::~Tile()
{
}