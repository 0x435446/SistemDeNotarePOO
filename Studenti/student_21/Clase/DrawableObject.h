#pragma once
#include "GameObject.h"
#include "Renderer.h"
class DrawableObject :
	virtual public GameObject
{
	Sprite sprite;
	Transform transform;
	Renderer renderer;
public:
	DrawableObject(std::string sprite_file, C2D::Vector2 position);
	DrawableObject() = delete;
	DrawableObject(const DrawableObject&) = delete;
	DrawableObject& operator= (const DrawableObject&) = delete;
	virtual ~DrawableObject() {}

	Transform& _transform() { return transform; }
	Sprite& _sprite() { return sprite; }

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;
};

