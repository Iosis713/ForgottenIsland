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

class Adventurer : public Controllable
{
protected:
    Inventory inventory_;

public:
    Adventurer(sf::Vector2f position
                , sf::Vector2i size
                , const std::string textureFile
                , float speed);
    virtual ~Adventurer() = default;

    void harvest(std::shared_ptr<Harvestable>& harvestable);

    void control() override;

};
#endif
