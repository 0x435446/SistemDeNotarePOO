#pragma once
#include "Component.h"
#include "VariousShit.h"
#define MAX_SPRITE_SIZE 8
class Sprite final:
	public Component
//	public Component<Sprite>
{
	//// int heading; ---------- should have had heading, but since we have no hypno-shroom, we don't need it for the moment
	C2D::Vector2 size;
	int color;
	int defaultColor;
	int*** image;
	int currentFrame = 0;
	int frames;
public:
	Sprite() = delete;
	Sprite(const Sprite&) = delete;
	Sprite& operator=(const Sprite&) = delete;
	Sprite(std::string sprite_file);
	Sprite(int flag, std::string sprite);
	Sprite(std::string sprite_file, const bool isRemovable);
	~Sprite();

	int getColor() const;
	int getPixel(int, int) const;

	void setColor(int newColor);
	void resetColor();

	C2D::Vector2 getSize() const;

	int getWidth() const;
	int getHeight() const;

private:
	void Update() override final; 
	void Start() override final;
	void End() override final;

	void LoadSprite(std::string);
};
// std::string Component<Sprite>::_desc = "Sprite";