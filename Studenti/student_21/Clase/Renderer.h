#pragma once
#include "Transform.h"
#include "Sprite.h"
#include "NextLevelConsoleHandler.h"
class Renderer final:
	public Component
//	public Component<Renderer>
{
	ConsoleHandlerV2& output;
	const Transform& transform;
	const Sprite& spriteToRender;
public:
	Renderer() = delete;
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;
	Renderer(const Transform& transform, const Sprite& sprite);
	Renderer(const Transform& transform, const Sprite& sprite, const bool isRemovable);
	~Renderer();


private:
	void Update() override final;
	void Start() override final;
	void End() override final;

	void print(const C2D::Vector2&, int, int);
};

// std::string Component<Renderer>::_desc = "Renderer";
