#include "Headers/Sprite.hpp"

Sprite::Sprite(sf::Vector2f position, sf::Vector2i size)
    : size_(size)
{
    sprite_.setOrigin(size_.x/2, size.y/2);
    sprite_.setPosition(position);
}

void Sprite::draw(sf::RenderWindow& i_window)
{
    sf::Texture texture;
    texture.loadFromFile("../Source/Images/Human.png");
    texture.setSmooth(true);

    sprite_.setTexture(texture);

    std::cout << sprite_.getPosition().x << ", " << sprite_.getPosition().y << '\n';

    i_window.draw(sprite_);
}

/*************************GETTERS******************************/

const auto Sprite::getPosition() const
{
    return sprite_.getPosition();
}


/*************************SETTERS******************************/

void Sprite::setPosition(sf::Vector2f position)
{
    sprite_.setPosition(position);
}
