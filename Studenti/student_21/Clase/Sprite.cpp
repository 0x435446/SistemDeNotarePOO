#include "Sprite.h"
#include <fstream>


Sprite::Sprite(std::string sprite_file) :
	Component(Component::Type::SPRITE, frames)
{
	LoadSprite(sprite_file);
}

Sprite::Sprite(std::string sprite_file,
	const bool isRemovable) :
	Component(Component::Type::SPRITE, frames, isRemovable)
{
	LoadSprite(sprite_file);
}

Sprite::Sprite(int flag, std::string sprite) :
	Component(Component::Type::SPRITE, 1, true)
{
	color = 15;
	defaultColor = 15;
	frames = 1;
	currentFrame = 0;
	image = new int** [1];
	image[0] = new int* [1];
	int w = sprite.length();
	int h = 1;
	size.setXY(w, h);
	image[0][0] = new int[w];
	for (int i = 0; i < w; i++)
	{
		image[0][0][i] = int(sprite[i]);
	}
}

Sprite::~Sprite()
{
	int h = size.getY();
	for (int i = 0; i < frames; i++)
	{
		for (int j = 0; j < h; j++)
		{
			delete[] image[i][j];
		}
		delete[] image[i];
	}
	delete[] image;
}

void Sprite::LoadSprite(std::string sprite_file)
{
	std::ifstream spriteFile;
	spriteFile.open(sprite_file);

	if (!spriteFile.is_open())
	{
		//// EXCEPTION
	}

	int w, h;
	spriteFile >> w;
	spriteFile >> h;

	if ((w <= 0 || w > MAX_SPRITE_SIZE) || (h <= 0 || h > MAX_SPRITE_SIZE))
	{
		//// EXCEPTION
	}

	size.setXY(w, h);

	spriteFile >> frames;

	if (frames <= 0)
	{
		//// EXCEPTION
	}

	spriteFile >> color;

	image = new int** [frames];
	for (int i = 0; i < frames; i++)
	{
		image[i] = new int* [h];
		for (int j = 0; j < h; j++)
		{
			image[i][j] = new int[w];
		}
	}
	for (int i = 0; i < frames; i++)
	{
		for (int j = h - 1; j >= 0; j--)
		{
			for (int k = 0; k < w; k++)
			{
				spriteFile >> image[i][j][k];
			}
		}
	}
	spriteFile.close();
	defaultColor = color;
}

int Sprite::getColor() const
{
	return color;
}
int Sprite::getPixel(int x, int y) const
{
	return image[currentFrame][y][x];
}

void Sprite::setColor(int newColor)
{
	color = newColor;
}

void Sprite::resetColor()
{
	color = defaultColor;
}

int Sprite::getWidth() const
{
	return size.getX();
}
int Sprite::getHeight() const
{
	return size.getY();
}

C2D::Vector2 Sprite::getSize() const
{
	return size; 
};

void Sprite::Update()  ///////// ANIMATION
{
	currentFrame++;
	if (currentFrame == frames)
		currentFrame = 0;
}
void Sprite::Start()
{

}
void Sprite::End()
{

}