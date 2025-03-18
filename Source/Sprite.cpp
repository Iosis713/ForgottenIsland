#include "Headers/Sprite.hpp"

Sprite::Sprite(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile)
    : size_(size)
{
    texture_.loadFromFile(textureFile);
    sprite_.setTexture(texture_);
    sprite_.setPosition(position);
}

void Sprite::draw(sf::RenderWindow& i_window)
{
    i_window.draw(sprite_);
}

/*************************GETTERS******************************/

const sf::Vector2f Sprite::getPosition() const
{
    return sprite_.getPosition();
}

const sf::Vector2i Sprite::getSize() const
{
    return this->size_;
}

sf::Sprite& Sprite::getSprite()
{
    return this->sprite_;
}

/*************************SETTERS******************************/

void Sprite::setPosition(const sf::Vector2f& position)
{
    sprite_.setPosition(position);
}
