#include "UsableCard.h"
UsableCard::UsableCard(std::list<InteractableObject*>& groupBoundTo,
    std::string sprite_file,
    C2D::Vector2 position,
    std::string content_sprite_file,
    int price) :
    InteractableObject(groupBoundTo, sprite_file, position),
    is_selected(false),
    price(price)
{
    content.AddComponent<Sprite>(new Sprite(content_sprite_file));
    Sprite& temp = dynamic_cast<Sprite&>(content.GetComponent<Component::Type::SPRITE>());
    default_content_position.setX(position.getX() + (_sprite().getWidth() - temp.getWidth()) / 2);
    default_content_position.setY(position.getY() - (_sprite().getHeight() - temp.getHeight()) / 2);
    content.AddComponent<Transform>(new Transform(default_content_position,temp.getSize()));
    content.AddComponent<Renderer>(new Renderer(dynamic_cast<Transform&>(content.GetComponent<Component::Type::TRANSFORM>()),temp));
    __content_private_renderer_access = &dynamic_cast<Renderer&>(content.GetComponent<Component::Type::RENDERER>());
    __content_private_transform_access = &dynamic_cast<Transform&>(content.GetComponent<Component::Type::TRANSFORM>());
}