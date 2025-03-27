#pragma once
#ifndef WEAPON
#define WEAPON

#include "Alive.hpp"
#include <memory>
#include <SFML/Graphics.hpp>

class Weapon
{
protected:
    int minAttackPoints_ = 1;
    int maxAttackPoints_ = 2;
    sf::RectangleShape range_{{0.f, 0.f}};

public:
    virtual ~Weapon() = default;
    Weapon() = delete;
    Weapon(const int minAttPoints, const int maxAttPoints);
    virtual void attack(Alive& target);
    sf::RectangleShape& getRange() {return this->range_;};
    void updatePosition(const sf::Vector2f& position);
};

class HarmByTouch : public Weapon
{
protected:
public:
    HarmByTouch() = delete;
    HarmByTouch(const int minAttPoints, const int maxAttPoints);
    virtual ~HarmByTouch() = default;
};

class Sword : public Weapon
{
protected:
public:
    Sword() = delete;
    Sword(const int minAttPoints, const int maxAttPoints);
    virtual ~Sword() = default;  
};

#endif
