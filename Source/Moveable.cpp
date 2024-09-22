#include "Headers/Moveable.hpp"

Moveable::Moveable(sf::Vector2f position, sf::Vector2i size, const std::string textureFile)
    : Sprite(position, size, textureFile)
{}
/*
{
    sprite_.setOrigin(size_.x/2, size.y/2);
    sprite_.setPosition(position);
}*/

void Moveable::move(sf::Vector2f distance)
{
    sprite_.move(distance);

}