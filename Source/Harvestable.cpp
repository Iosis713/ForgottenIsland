#include "Headers/Harvestable.hpp"

Harvestable::Harvestable(sf::Vector2f position, sf::Vector2i size, const std::string textureFile)
    : Sprite(position, size, textureFile)
{
    timeFromLatestHarvest = std::chrono::steady_clock::now();
}

void Harvestable::draw(sf::RenderWindow& i_window)
{
    sf::Texture texture;

    texture.loadFromFile(textureFile_);
    sprite_.setTexture(texture);
    sprite_.setTextureRect(sf::IntRect(size_.x * static_cast<int>(isGrown_), 0, size_.x, size_.y));
    i_window.draw(sprite_);
}

void Harvestable::setIsGrown(const bool isGrown)
{
    if(isGrown == false)
        timeFromLatestHarvest = std::chrono::steady_clock::now();

    isGrown_ = isGrown;
}

void Harvestable::organize()
{
    deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>
                (std::chrono::steady_clock::now() - timeFromLatestHarvest).count();

    if(!isGrown_ and deltaTime > growthTime_)
        isGrown_ = true;

}

