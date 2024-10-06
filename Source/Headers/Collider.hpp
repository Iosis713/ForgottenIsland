#pragma once
#ifndef COLLIDER
#define COLLIDER

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Sprite.hpp"

using spritePtr = std::shared_ptr<Sprite>;

struct Collider
{
    Collider() = default;
    ~Collider() = default;

    template <typename Source, typename Target>
    static inline bool isColliding(Source source, Target target)
    {
        if(source->getSprite().getGlobalBounds().intersects(target->getSprite().getGlobalBounds()))
            return true;
   
        else
            return false;
    }   


};

#endif
