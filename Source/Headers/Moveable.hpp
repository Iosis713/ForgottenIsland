#pragma once
#ifndef MOVEABLE
#define MOVEABLE

#include "Sprite.hpp"

class Moveable : public Sprite
{
protected:

public:
    Moveable(sf::Vector2f position, sf::Vector2i size, const std::string textureFile); 
    virtual ~Moveable() = default;

    void move(sf::Vector2f distnace);
};

#endif

