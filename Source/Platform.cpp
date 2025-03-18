#include "Headers/Platform.hpp"

Platform::Platform(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile)
    : Sprite(position, size, textureFile)
{
    texture_.loadFromFile(textureFile);
    sprite_.setTexture(texture_);
    sprite_.setTextureRect(sf::IntRect(std::get<0>(GreenGround), std::get<1>(GreenGround)));
    sprite_.setPosition(position);

    platform_.setFillColor(sf::Color::Red);
    platform_.setSize({static_cast<float>(size.x), static_cast<float>(size.y/5)});
    platform_.setPosition(position.x, position.y + 3.f); //empty field offset
}

void Platform::draw(sf::RenderWindow& i_window)
{
    i_window.draw(sprite_);
    i_window.draw(platform_);
}
