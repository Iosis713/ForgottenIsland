#include "Headers/Mob.hpp"

Mob::Mob(const sf::Vector2f position
         , const sf::Vector2i size
         , const std::string& textureFile
         , const float speed
         , const int HP)
    : Moveable(position, size, textureFile, speed)
    , Alive(HP)
{};
