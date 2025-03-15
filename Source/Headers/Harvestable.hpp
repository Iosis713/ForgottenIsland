#pragma once
#ifndef HARVESTABLE
#define HARVESTABLE

#include <chrono>
#include <thread>

#include "Sprite.hpp"
#include "Resource.hpp"

using Time = std::chrono::time_point<std::chrono::steady_clock>;

class Harvestable   : public Sprite
                    , public Resource

{
protected:
    const unsigned growthTime_ = 2000; //ms
    unsigned deltaTime = 0;
    Time timeFromLatestHarvest;
    bool isGrown_ = true;
    
public:
    Harvestable() = delete;
    Harvestable(sf::Vector2f position, sf::Vector2i size, const std::string textureFile);
    virtual ~Harvestable() = default;

    void draw(sf::RenderWindow& i_window) override;
    void organize();

    virtual void setIsGrown(const bool isGrown);
    virtual inline bool isGrown() {return this->isGrown_;}
};

#endif
