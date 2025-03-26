#include "Headers/Adventurer.hpp"

Adventurer::Adventurer(sf::Vector2f position
                       , sf::Vector2i size
                       , const std::string& textureFile
                       , const float speed
                       , const int HP)
    : Mob(position, size, textureFile, speed, HP)
{}

void Adventurer::control()
{
    velocity_.x = 0.f;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity_.x = speed_;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocity_.x = -speed_;    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and !isOnGround)
        velocity_.y = speed_;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
        jump();

    move(velocity_);
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
