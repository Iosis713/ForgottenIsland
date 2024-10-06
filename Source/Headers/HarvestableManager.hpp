#pragma once
#ifndef HARVESTABLE_MANAGER
#define HARVESTABLE_MANAGER

#include <vector>
#include <memory>

#include "Harvestable.hpp"

using Manager = std::vector<std::shared_ptr<Harvestable>>;

struct HarvestableManager
{
    Manager manager_;
    
    HarvestableManager() = default;
    ~HarvestableManager() = default;
    
    void drawAll(sf::RenderWindow& i_window);
    void organizeAll();

    template<typename HarvestableType>
    void addNew(sf::Vector2f position, sf::Vector2i size, const std::string textureFile)
    {
        manager_.push_back(std::make_shared<HarvestableType>(position, size, textureFile));
    }
};
#endif