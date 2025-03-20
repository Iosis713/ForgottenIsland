#include "Headers/Platform.hpp"

Platform::Platform(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile)
    : Sprite(position, size, textureFile)
{
    sprite_.setTextureRect(sf::IntRect(std::get<0>(GreenGround), std::get<1>(GreenGround)));
    platform_.setSize({static_cast<float>(size.x), static_cast<float>(size.y/10)});
    platform_.setPosition(position.x, position.y + 3.f); //empty field offset
}
