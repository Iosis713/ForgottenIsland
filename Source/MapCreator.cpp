#include "Headers/MapCreator.hpp"
#include <ranges>

MapCreator::MapCreator()
{
    createMap();
}

void MapCreator::drawMap(sf::RenderTarget& target) const
{
    for (const auto& platform : platforms_)
        platform->drawPlatform(target);
}

void MapCreator::createLineOfPlatforms(const sf::Vector2f& startPosition, const size_t numberOfCells)
{
    //some platforms
    for (size_t cell = 0; cell < numberOfCells; cell++)
    {
        if (cell == 0 || cell == (numberOfCells - 1))
        {
            platforms_.push_back({std::make_shared<Platform>(sf::Vector2f(startPosition.x + cell * GreenGround.size_.x, startPosition.y), GreenGround.size_, GreenGround.filepath_, true)});
        }
        else
            platforms_.push_back({std::make_shared<Platform>(sf::Vector2f(startPosition.x + cell * GreenGround.size_.x, startPosition.y), GreenGround.size_, GreenGround.filepath_)});
    }
}


void MapCreator::createMap()
{
    createLineOfPlatforms({500.f, 800.f}, 6);
    createLineOfPlatforms({1200.f, 800.f}, 6);
    createLineOfPlatforms({150.f, 650.f}, 8);
    createLineOfPlatforms({1000.f, 650.f}, 7);
    createLineOfPlatforms({700.f, 450.f}, 8);
    createLineOfPlatforms({100.f, 300.f}, 12);
    createLineOfPlatforms({1100.f, 150.f}, 8);
    createLineOfPlatforms({0.f, static_cast<float>(SCREEN_HEIGHT - 3.5 * GreenGround.size_.y)}, static_cast<size_t>(SCREEN_WIDTH/GreenGround.size_.x)); //bottom of the map

    for (auto& platform : platforms_)
    {
        if (platform->IsEdgePlatform())
        {
            sf::RectangleShape edgePlatform({static_cast<float>(platform->getSize().x/4), static_cast<float>(platform->getSize().y)});
            edgePlatform.setPosition(static_cast<float>(platform->getPosition().x + 0.5 * (platform->getSize().x - edgePlatform.getSize().x)), static_cast<float>(platform->getPosition().y - edgePlatform.getSize().y));
            edgePlatforms_.push_back(edgePlatform);
        }  
    }
}
