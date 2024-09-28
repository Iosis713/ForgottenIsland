#include "Headers/Controllable.hpp"

Controllable::Controllable(sf::Vector2f position
                        , sf::Vector2i size
                        , const std::string textureFile
                        , float speed)
    : Moveable(position, size, textureFile, speed)
{}

void Controllable::control()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        move({speed_, 0.f});

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        move({- speed_, 0.f});
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        move({0.f, - speed_});
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        move({0.f, speed_});
}
