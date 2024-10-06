#include "Headers/Adventurer.hpp"

Adventurer::Adventurer(sf::Vector2f position
                        , sf::Vector2i size
                        , const std::string textureFile
                        , float speed)
    : Controllable(position, size, textureFile, speed)
{}

int Adventurer::harvest(std::shared_ptr<Harvestable> harvestable)
{
    if (harvestable->isGrown() and sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        harvestable->setIsGrown(false);
        return Utils().randomGenerator(1, 7);
    }

    return 0;
}

void Adventurer::control()
{
    Controllable::control();
}
