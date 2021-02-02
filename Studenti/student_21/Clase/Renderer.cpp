#include "Renderer.h"
#define DEFAULT_COLOR 15

Renderer::Renderer(const Transform& transform,
	const Sprite& sprite) :
	Component(Component::Type::RENDERER, 0),
	transform(transform),
	spriteToRender(sprite),
	output(ConsoleHandlerV2::getInstance()) {}
Renderer::Renderer(const Transform& transform,
	const Sprite& sprite,
	bool const isRemovable) : 
	Component(Component::Type::RENDERER, 0, isRemovable),
	transform(transform),
	spriteToRender(sprite), 
	output(ConsoleHandlerV2::getInstance()) {}
Renderer::~Renderer() {}
void Renderer::Update()
{
	print(transform.getPosition(), spriteToRender.getWidth(), spriteToRender.getHeight());
}
void Renderer::Start()
{
	print(transform.getPosition(), spriteToRender.getWidth(), spriteToRender.getHeight());
}
void Renderer::End()
{
}
void Renderer::print(const C2D::Vector2& position, int width, int height)
{
	int pixel;
	int pX = position.getX();
	int pY = position.getY();
	for (int i = height - 1; i >= 0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			pixel = spriteToRender.getPixel(j, i);
			if (pixel != 32 && ((pX + j >= 0) && (pY - i >= 0))) /// WHITE SPACE
				output.updateConsoleBuffer(pixel, spriteToRender.getColor(), pX + j,  pY - i);
		}
	}
}