#include "Headers/MapCreator.hpp"
#include <ranges>

MapCreator::MapCreator()
{
    createMap();
}

void MapCreator::drawMap(sf::RenderWindow& i_window)
{
    for (const auto& platform : platforms_)
        platform->draw(i_window);
}

void MapCreator::createMap()
{
    platforms_.push_back({std::make_shared<Platform>(sf::Vector2f(700.f, 500.f), GreenGround.size_, GreenGround.filepath_)});
    platforms_.push_back({std::make_shared<Platform>(sf::Vector2f(780.f, 500.f), GreenGround.size_, GreenGround.filepath_)});

    //bottom of the visible map
    for (size_t cell = 0; cell < static_cast<size_t>(SCREEN_WIDTH/GreenGround.size_.x); cell++)
    {
        platforms_.push_back({std::make_shared<Platform>(sf::Vector2f(cell * GreenGround.size_.x, SCREEN_HEIGHT - 3 * GreenGround.size_.y), GreenGround.size_, GreenGround.filepath_)});

    }

}
