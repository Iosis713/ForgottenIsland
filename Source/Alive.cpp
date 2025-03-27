#include "Headers/Alive.hpp"

Alive::Alive(const int HP)
    : HP_(HP)
    , previousHit_(std::chrono::steady_clock::now())
{};

Alive& Alive::operator-=(const int value)
{
    this->HP_ -= value;
    makeInvulnerable();
    return *this;
};

Alive& Alive::operator+=(const int value)
{
    this->HP_ += value;
    return *this;
};

void Alive::update()
{
    if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - previousHit_).count() >= invulnerabilityTime_)
        makeVulnerable();
}