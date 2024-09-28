#pragma once
#ifndef HARVESTABLE
#define HARVESTABLE

#include <chrono>
#include <thread>

#include "Sprite.hpp"

using Time = std::chrono::time_point<std::chrono::steady_clock>;

class Harvestable : public Sprite
{
protected:
    const unsigned growthTime_ = 2000; //ms
    unsigned deltaTime = 0;
    Time timeFromLatestHarvest;

public:
    bool isGrown_ = true;

    Harvestable(sf::Vector2f position, sf::Vector2i size, const std::string textureFile);
    virtual ~Harvestable() = default;

    void draw(sf::RenderWindow& i_window) override;
    void organize();

    void setIsGrown(bool isGrown);

};

#endif
