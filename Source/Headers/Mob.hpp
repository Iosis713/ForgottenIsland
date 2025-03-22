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

public:
    Mob() = delete;
    virtual ~Mob() = default;
    Mob(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile, const float speed, const int HP);

};

#endif
