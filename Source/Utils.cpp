#include "Headers/Utils.hpp"

int Utils::randomGenerator(const int min, const int max)
{
    std::random_device randDev;
    std::mt19937 generator(randDev());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}