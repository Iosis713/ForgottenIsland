#include "Headers/Adventurer.hpp"

Adventurer::Adventurer(sf::Vector2f position
                        , sf::Vector2i size
                        , const std::string textureFile
                        , float speed)
    : Controllable(position, size, textureFile, speed)
{
    collidingSprites_.reserve(5);
}

void Adventurer::controlHarvestable(HarvestableManagerPtr harvestableManager)
{
    for (auto& harvestable : harvestableManager->manager_)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && Collider::isColliding(this, harvestable))
                harvest(harvestable);
        }
}

void Adventurer::harvest(std::shared_ptr<Harvestable>& harvestable)
{
    if (harvestable && harvestable->isGrown())
    {
        harvestable->setIsGrown(false);
        harvestable->amount_ = static_cast<unsigned>(Utils().randomGenerator(1, 7));
        inventory_.add(harvestable);
    }
}

void Adventurer::getCollidingSprites(Sprites sprites)
{
    collidingSprites_.clear();
    Collider collider{};
    for (const auto& sprite : sprites)
    {
        if(collider.isColliding(this, sprite))
            collidingSprites_.push_back(sprite);
    }
}
