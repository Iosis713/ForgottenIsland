#include "Headers/Adventurer.hpp"

Adventurer::Adventurer(sf::Vector2f position
                        , sf::Vector2i size
                        , const std::string textureFile
                        , float speed)
    : Controllable(position, size, textureFile, speed)
{
    collidingSprites_.reserve(5);
}

void Adventurer::harvest(std::shared_ptr<Harvestable>& harvestable)
{
    if (harvestable && harvestable->isGrown() and sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        harvestable->setIsGrown(false);
        int tempAmount = Utils().randomGenerator(1, 7);
        harvestable->amount_ = static_cast<unsigned>(tempAmount);
        std::cout << "Casted to unsigned value = " << static_cast<unsigned>(tempAmount) << '\n';
        inventory_.add(harvestable);
        
        //MANUAL TEST
        std::cout << "Inventory first item amount: " << inventory_.getItems()[0]->amount_ << ", ";
        std::cout << "Size of inventory: " << inventory_.getItems().size() << '\n';
        std::cout << '\n' << '\n';
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
