#pragma once
#ifndef MOVEABLE
#define MOVEABLE

#include "Sprite.hpp"
#include "Platform.hpp"
#include "MapCreator.hpp"
#include <memory>

using SpritePtr = std::shared_ptr<Sprite>;

enum class Direction : int
{
    LEFT = 0,
    RIGHT = 1
};

class Moveable : public Sprite
{
protected:
    float speed_ = 5.f;
    sf::Vector2f velocity_{0.f, 0.f};
    bool isOnGround = false;
    bool gravityOn = true;
    sf::RectangleShape platform_{};
    virtual void checkCollisionWithPlatform(const Platforms& platforms);
    Direction aimDirection = Direction::LEFT;

public:
    Moveable(const sf::Vector2f position
            , const sf::Vector2i size
            , const std::string& textureFile
            , const float speed); 
    virtual ~Moveable() = default;

    bool IsOnGround() const { return this->isOnGround; };
    virtual void jump() = 0;
    virtual void updatePosition(const Platforms& platforms);
};

#endif

