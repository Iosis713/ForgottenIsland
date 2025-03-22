#pragma once
#ifndef UTILS
#define UTILS

#include <random>

struct Utils
{
    Utils() = default;
    virtual ~Utils() = default;

    int static randomGenerator(const int min, const int max)
    {
        std::random_device randDev;
        std::mt19937 generator(randDev());
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(generator);
    };
};

#endif