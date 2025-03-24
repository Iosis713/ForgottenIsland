#include "Headers/Weapon.hpp"
#include "Headers/Utils.hpp"

Weapon::Weapon(const int minAttPoints, const int maxAttPoints)
    : minAttackPoints_(minAttPoints)
    , maxAttackPoints_(maxAttPoints)
{};


HarmByTouch::HarmByTouch(const int minAttPoints, const int maxAttPoints)
    : Weapon(minAttPoints, maxAttPoints)
{};

void HarmByTouch::attack(Alive& target)
{
    target -= Utils::randomGenerator(minAttackPoints_, maxAttackPoints_);
}