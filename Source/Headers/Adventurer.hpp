#pragma once
#ifndef ADVENTURER
#define ADVENTURER

#include <memory>

#include "Collider.hpp"
#include "Controllable.hpp"
#include "Harvestable.hpp"
#include "HarvestableManager.hpp"
#include "Utils.hpp"
#include "Inventory.hpp"
using Sprites = std::vector<std::shared_ptr<Sprite>>;
using HarvestableManagerPtr = std::shared_ptr<HarvestableManager>;
class Adventurer : public Controllable
{
protected:
    Inventory inventory_;
    Sprites collidingSprites_;

public:
    Adventurer(sf::Vector2f position
                , sf::Vector2i size
                , const std::string textureFile
                , float speed);
    virtual ~Adventurer() = default;

    void getCollidingSprites(Sprites sprites);
    void harvest(std::shared_ptr<Harvestable>& harvestable);
    void controlHarvestable(HarvestableManagerPtr haverstableManager);

};
#endif
