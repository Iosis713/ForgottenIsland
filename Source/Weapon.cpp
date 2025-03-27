#include "Headers/Weapon.hpp"
#include "Headers/Utils.hpp"

Weapon::Weapon(const int minAttPoints, const int maxAttPoints)
    : minAttackPoints_(minAttPoints)
    , maxAttackPoints_(maxAttPoints)
{};

void Weapon::updatePosition(const sf::Vector2f& position)
{
    this->range_.setPosition(position);
};

void Weapon::attack(Alive& target)
{
    if (target.isVulnerable())
    {
        target -= Utils::randomGenerator(minAttackPoints_, maxAttackPoints_);
        target.hitNow();
    }
}

HarmByTouch::HarmByTouch(const int minAttPoints, const int maxAttPoints)
    : Weapon(minAttPoints, maxAttPoints)
{
    range_.setSize({48.f, 48.f});
};

Sword::Sword(const int minAttPoints, const int maxAttPoints)
    :Weapon(minAttPoints, maxAttPoints)
{
    range_.setSize({200.f, 100.f});
};

