#include "DrawableObject.h"

DrawableObject::DrawableObject(
	std::string sprite_file, 
	C2D::Vector2 position) : 
	sprite(sprite_file, false), 
	transform(position, sprite.getSize(), false), 
	renderer(transform, sprite, false) 
{
	AddComponent<Sprite>(&sprite);
	AddComponent<Transform>(&transform);
	AddComponent<Renderer>(&renderer);
}



											   //// DRAWABLE OBJECT JUST ADDS A NEW FEATURE
											   //// IT DOES NOTHING BY ITSELF      ------ INSTEAD OF MANUALLY ADDING THESE COMPONENTS, JUST CALL IT DRAWABLE