#pragma once
#ifndef MOB
#define MOB

#include <memory>

#include "Moveable.hpp"
#include "Alive.hpp"
#include "Weapon.hpp"

class Mob : public Moveable
          , public Alive
{
protected:
    std::unique_ptr<Weapon> weapon = nullptr;
    int currentFrame_ = 0;
    const int xFrames_ = 0;
    const int yFrames_ = 0;
public:
    Mob() = delete;
    virtual ~Mob() = default;
    Mob(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile, const float speed, const int HP, const int xFrames, const int yFrames);
    Mob(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile, const float speed, const int HP);
    void control() override {move(velocity_);};
    void control(const EdgePlatforms& edgePlatforms);
    void draw(sf::RenderWindow& i_window) override;
};

enum class Direction : int
{
    LEFT = 0,
    RIGHT = 1
};

#endif
