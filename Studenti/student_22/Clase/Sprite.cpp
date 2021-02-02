#include "Sprite.h"



Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}

void Sprite::loadSprite(std::string name) {
	std::ifstream inFile;
	try {
		inFile.open(name);
	}
	catch (std::exception e) {
		std::cout << e.what();
	}
	char x;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++) {
			inFile >> x;
			if (x == '0') {
				pixels[i][j].colour = NULL;
				pixels[i][j].glyph = NULL;
			}
			else if (x == 'v') {
				pixels[i][j].colour = FG_DARK_GREEN;
				pixels[i][j].glyph = PIXEL_SOLID;
			}
			else if (x == 'V') {
				pixels[i][j].colour = FG_GREEN;
				pixels[i][j].glyph = PIXEL_SOLID;
			}
			else if (x == 'n') {
				pixels[i][j].colour = FG_BLACK;
				pixels[i][j].glyph = PIXEL_SOLID;
			}
			else if (x == 'a') {
				pixels[i][j].colour = FG_WHITE;
				pixels[i][j].glyph = PIXEL_SOLID;
			}
			else if (x == 'g') {
				pixels[i][j].colour = FG_DARK_YELLOW;
				pixels[i][j].glyph = PIXEL_SOLID;
			}
			else if (x == 'G') {
				pixels[i][j].colour = FG_YELLOW;
				pixels[i][j].glyph = PIXEL_SOLID;
			}
			else if (x == 'y') {
				pixels[i][j].colour = FG_GREY;
				pixels[i][j].glyph = PIXEL_SOLID;
			}
			else if (x == 'Y') {
				pixels[i][j].colour = FG_DARK_GREY;
				pixels[i][j].glyph = PIXEL_SOLID;
			}
			else if(x == 'r') {
				pixels[i][j].colour = FG_DARK_RED;
				pixels[i][j].glyph = PIXEL_SOLID;
			}
			else if (x == 'b') {
				pixels[i][j].colour = FG_DARK_BLUE;
				pixels[i][j].glyph = PIXEL_SOLID;
			}
			else if (x == 'B') {
				pixels[i][j].colour = FG_BLUE;
				pixels[i][j].glyph = PIXEL_SOLID;
			}
		}

}