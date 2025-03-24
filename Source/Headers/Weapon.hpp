#pragma once
#ifndef WEAPON
#define WEAPON

#include "Alive.hpp"
#include <memory>

class Weapon
{
protected:
    int minAttackPoints_ = 1;
    int maxAttackPoints_ = 2;

public:
    virtual ~Weapon() = default;
    Weapon() = delete;
    Weapon(const int minAttPoints, const int maxAttPoints);
    virtual void attack(Alive& target) = 0;
};

class HarmByTouch : public Weapon
{
protected:
public:
    HarmByTouch() = delete;
    HarmByTouch(const int minAttPoints, const int maxAttPoints);
    virtual ~HarmByTouch() = default;

    void attack(Alive& target) override;
};

#endif
