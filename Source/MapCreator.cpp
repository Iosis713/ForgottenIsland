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
    platforms_.push_back({std::make_shared<Platform>(sf::Vector2f(700.f, 500.f), std::get<1>(GreenGround), std::get<2>(GreenGround))});
    platforms_.push_back({std::make_shared<Platform>(sf::Vector2f(780.f, 500.f), std::get<1>(GreenGround), std::get<2>(GreenGround))});
}
