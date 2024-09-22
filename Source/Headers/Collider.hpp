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

    static bool isColliding(spritePtr source, spritePtr target);

};

#endif
