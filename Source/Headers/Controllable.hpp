#pragma once
#ifndef CONTROLLABLE
#define CONTROLLABLE

#include "Moveable.hpp"

class Controllable : public Moveable
{
protected:

public:
    Controllable(sf::Vector2f position
                , sf::Vector2i size
                , const std::string textureFile
                , float speed);

    void control();
};

#endif
