#include "Headers/Platform.hpp"
#include "Headers/Global.hpp"

Platform::Platform(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile, const bool isEdgePlatform)
    : Sprite(position, size, textureFile)
    , isEdgePlatform_(isEdgePlatform)
{
    sprite_.setTextureRect(sf::IntRect(GreenGround.offset_, GreenGround.size_));
    platform_.setSize({static_cast<float>(size.x), static_cast<float>(size.y/10)});
    platform_.setPosition(position.x, position.y); //empty field offset
}

Platform::Platform(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile)
    : Platform(position, size, textureFile, false)
{}

void Platform::drawPlatform(sf::RenderTarget& target) 
{
    target.draw(sprite_);
}