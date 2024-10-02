#pragma once
#ifndef UTILS
#define UTILS

#include <random>

struct Utils
{
    Utils() = default;
    virtual ~Utils() = default;

    int randomGenerator(const int min, const int max);


};

#endif