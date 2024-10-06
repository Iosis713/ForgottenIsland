#include "Headers/HarvestableManager.hpp"

void HarvestableManager::drawAll(sf::RenderWindow& i_window)
{
    for(auto& harvestable : manager_)
    {
        harvestable->draw(i_window);
    }
}

void HarvestableManager::organizeAll()
{
    for(auto& harvestable : manager_)
    {
        harvestable->organize();
    }
}
