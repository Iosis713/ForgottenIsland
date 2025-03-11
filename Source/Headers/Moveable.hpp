#pragma once
#ifndef MOVEABLE
#define MOVEABLE

#include "Sprite.hpp"

class Moveable : public Sprite
{
protected:
    float speed_ = 5.f;

public:
    Moveable(sf::Vector2f position
            , sf::Vector2i size
            , const std::string textureFile
            , float speed); 
    virtual ~Moveable() = default;

    void move(const sf::Vector2f& distnace);
};

#endif

