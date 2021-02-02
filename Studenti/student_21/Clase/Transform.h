#pragma once
#include "Component.h"
#include "VariousShit.h"
class Transform final:
	public Component
//	public Component<Transform>
{
	C2D::Vector2 position;
	C2D::Vector2 size;
public:
	Transform() = delete;
	Transform(int X, int Y, int Width, int Height);
	Transform(C2D::Vector2 position, C2D::Vector2 size);
	Transform(int X, int Y, int Width, int Height, const bool isRemovable);
	Transform(C2D::Vector2 position, C2D::Vector2 size, const bool isRemovable);
	Transform& operator= (const Transform&) = delete;
	~Transform();


	const C2D::Vector2& getPosition() const;
	const C2D::Vector2& getSize() const;

	void setPosition(C2D::Vector2&);
	void setPosition(int X, int Y);

private:
	void Start() override final;
	void Update() override final;
	void End() override final;

};
// std::string Component<Transform>::_desc = "Transform";
