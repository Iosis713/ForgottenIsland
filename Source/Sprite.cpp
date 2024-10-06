#include "Headers/Sprite.hpp"

Sprite::Sprite(sf::Vector2f position, sf::Vector2i size, const std::string textureFile)
    : size_(size)
    , textureFile_(textureFile)
{
    sprite_.setPosition(position);
}

void Sprite::draw(sf::RenderWindow& i_window)
{
    sf::Texture texture;
    texture.loadFromFile(textureFile_);

    sprite_.setTexture(texture);

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

const sf::Sprite& Sprite::getSprite() const
{
    return this->sprite_;
}

/*************************SETTERS******************************/

void Sprite::setPosition(sf::Vector2f position)
{
    sprite_.setPosition(position);
}
