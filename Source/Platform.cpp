#include "Headers/Platform.hpp"
#include "Headers/Global.hpp"

Platform::Platform(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile)
    : Sprite(position, size, textureFile)
{
    sprite_.setTextureRect(sf::IntRect(GreenGround.offset_, GreenGround.size_));
    platform_.setSize({static_cast<float>(size.x), static_cast<float>(size.y/10)});
    platform_.setPosition(position.x, position.y); //empty field offset
}
