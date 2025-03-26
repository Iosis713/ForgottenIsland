#pragma once
#ifndef MOVEABLE
#define MOVEABLE

#include "Sprite.hpp"
#include "Platform.hpp"
#include "MapCreator.hpp"
#include <memory>

using SpritePtr = std::shared_ptr<Sprite>;

class Moveable : public Sprite
{
protected:
    float speed_ = 5.f;
    sf::Vector2f velocity_{0.f, 0.f};
    bool isOnGround = false;
    bool gravityOn = true;
    sf::RectangleShape platform_{};

public:
    Moveable(const sf::Vector2f position
            , const sf::Vector2i size
            , const std::string& textureFile
            , const float speed); 
    virtual ~Moveable() = default;

    virtual void checkCollisionWithPlatform(const Platforms& platforms);
    virtual void control() = 0;
    bool IsOnGround() const { return this->isOnGround; };
    virtual void jump();
    void move(const sf::Vector2f& distnace);
    
};

#endif

