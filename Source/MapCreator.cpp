#include "Headers/MapCreator.hpp"
#include <ranges>

MapCreator::MapCreator()
{
    createMap();
    setUpMap();
}

void MapCreator::drawMap(sf::RenderWindow& i_window)
{
    for (const auto& spriteWithParam : spritesWithParams_)
        i_window.draw(spriteWithParam.first->getSprite());
}

void MapCreator::createMap()
{
    spritesWithParams_.push_back({std::make_shared<Sprite>(sf::Vector2f(700.f, 500.f), std::get<1>(GreenGround), std::get<2>(GreenGround)), GreenGround});
    spritesWithParams_.push_back({std::make_shared<Sprite>(sf::Vector2f(780.f, 500.f), std::get<1>(GreenGround), std::get<2>(GreenGround)), GreenGround});
}

void MapCreator::setUpMap()
{
    std::ranges::for_each(spritesWithParams_, [&](const auto& spriteWithparam){
        const auto& [sprite, textureParam] = spriteWithparam;
        sprite->getSprite().setTextureRect(sf::IntRect(std::get<0>(textureParam), {sprite->getSize().x, sprite->getSize().y}));
    });
}