#pragma once
#ifndef COLLIDER
#define COLLIDER

#include <iostream>
#include <memory>
#include <type_traits>
#include <SFML/Graphics.hpp>

#include "Sprite.hpp"

using SpritePtr = std::shared_ptr<Sprite>;

struct Collider
{
    Collider() = default;
    ~Collider() = default;

    template <typename Source, typename Target>
    static inline bool isColliding(const Source& source, const Target& target)
    {
        sf::FloatRect targetBounds;
        if constexpr (std::is_same_v<Target, sf::RectangleShape>)
            targetBounds = target.getGlobalBounds();
        else
            targetBounds = target->getSprite().getGlobalBounds();

        sf::FloatRect sourceBounds;
        if constexpr (std::is_same_v<Source, sf::RectangleShape>)
            sourceBounds = source.getGlobalBounds();
        else
            sourceBounds = source->getSprite().getGlobalBounds();

        if(sourceBounds.intersects(targetBounds))
            return true;
        else
            return false;
    }

    template <>
    inline bool isColliding(const sf::RectangleShape& source, const sf::RectangleShape& target)
    {
        if(source.getGlobalBounds().intersects(target.getGlobalBounds()))
            return true;
        else
            return false;
    }
};

#endif
