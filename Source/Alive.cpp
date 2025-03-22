#include "Headers/Alive.hpp"

Alive::Alive(const int HP)
    : HP_(HP)
{};

Alive& Alive::operator-=(const int value)
{
    this->HP_ -= value;
    return *this;
};

Alive& Alive::operator+=(const int value)
{
    this->HP_ += value;
    return *this;
};