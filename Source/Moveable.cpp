#include "Headers/Moveable.hpp"

Moveable::Moveable(sf::Vector2f position
                , sf::Vector2i size
                , const std::string textureFile
                , float speed)
    : Sprite(position, size, textureFile)
    , speed_(speed)
{}

void Moveable::move(const sf::Vector2f& distance)
{
    sprite_.move(distance);

}