#include "Headers/Adventurer.hpp"

Adventurer::Adventurer(sf::Vector2f position
                        , sf::Vector2i size
                        , const std::string textureFile
                        , float speed)
    : Controllable(position, size, textureFile, speed)
{}

int Adventurer::harvest(std::shared_ptr<Harvestable> harvestable)
{
    //need to be updated with respect to mouse click on entity
    if(harvestable->isGrown())
    {
        harvestable->setIsGrown(false);
        int drop = Utils().randomGenerator(1, 7);
        return drop;
    }

    return 0;
}
