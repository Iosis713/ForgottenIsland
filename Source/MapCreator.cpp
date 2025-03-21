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

void MapCreator::createMap()
{
    //some platforms
    for (size_t cell = 0; cell < 6; cell++)
        platforms_.push_back({std::make_shared<Platform>(sf::Vector2f(500.f + cell * GreenGround.size_.x, 800.f), GreenGround.size_, GreenGround.filepath_)});

    for (size_t cell = 0; cell < 4; cell++)
        platforms_.push_back({std::make_shared<Platform>(sf::Vector2f(1200.f + cell * GreenGround.size_.x, 800.f), GreenGround.size_, GreenGround.filepath_)});

    for (size_t cell = 0; cell < 8; cell++)
    {
        platforms_.push_back({std::make_shared<Platform>(sf::Vector2f(150.f + cell * GreenGround.size_.x, 650.f), GreenGround.size_, GreenGround.filepath_)});
        platforms_.push_back({std::make_shared<Platform>(sf::Vector2f(150.f + (10 + cell) * GreenGround.size_.x, 650.f), GreenGround.size_, GreenGround.filepath_)});
    }

    //bottom of the visible map
    for (size_t cell = 0; cell < static_cast<size_t>(SCREEN_WIDTH/GreenGround.size_.x); cell++)
        platforms_.push_back({std::make_shared<Platform>(sf::Vector2f(cell * GreenGround.size_.x, SCREEN_HEIGHT - 3 * GreenGround.size_.y), GreenGround.size_, GreenGround.filepath_)});

}
