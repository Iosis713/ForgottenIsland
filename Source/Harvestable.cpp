#include "Headers/Harvestable.hpp"

Harvestable::Harvestable(sf::Vector2f position, sf::Vector2i size, const std::string textureFile)
    : Sprite(position, size, textureFile)
{}

void Harvestable::draw(sf::RenderWindow& i_window)
{
    sf::Texture texture;

    texture.loadFromFile(textureFile_);
    sprite_.setTexture(texture);
    sprite_.setTextureRect(sf::IntRect(size_.x * static_cast<int>(isGrown_), 0, size_.x, size_.y));
    i_window.draw(sprite_);
}

void Harvestable::setIsGrown(bool isGrown)
{
    isGrown_ = isGrown;
}

/*void Harvestable::organize()
{
    
}*/

