#pragma once
#ifndef ADVENTURER
#define ADVENTURER

#include <memory>

#include "Collider.hpp"
#include "Mob.hpp"
#include "Harvestable.hpp"
#include "HarvestableManager.hpp"
#include "Utils.hpp"
#include "Inventory.hpp"

using Sprites = std::vector<std::shared_ptr<Sprite>>;
using HarvestableManagerPtr = std::shared_ptr<HarvestableManager>;

class Adventurer : public Mob
{
protected:
    Inventory inventory_;
    bool isJumping = false;

public:
    Adventurer(sf::Vector2f position
                , sf::Vector2i size
                , const std::string& textureFile
                , const float speed
                , const int HP);
    virtual ~Adventurer() = default;

    void harvest(std::shared_ptr<Harvestable>& harvestable);
    void controlHarvestable(HarvestableManagerPtr haverstableManager);
    void control();
    void draw(sf::RenderWindow& i_window) override {Moveable::draw(i_window);};

};
#endif
