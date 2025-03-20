#include "Headers/Controllable.hpp"

Controllable::Controllable(sf::Vector2f position
                        , sf::Vector2i size
                        , const std::string textureFile
                        , float speed)
    : Moveable(position, size, textureFile, speed)
{}

void Controllable::control()
{
    velocity_.x = 0.f;
    if (!isOnGround)
        velocity_.y = 2.f;
    else
        velocity_.y = 0.f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity_.x = speed_;

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocity_.x = -speed_;
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        velocity_.y = -speed_;
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and !isOnGround)
        velocity_.y = speed_;

    move(velocity_);
}
