#pragma once
#ifndef MAP_CREATOR
#define MAP_CREATOR

#include "Sprite.hpp"
#include <tuple>
#include <memory>
#include <utility>

using SpritePtr = std::shared_ptr<Sprite>;
using TextureParameters = std::tuple<sf::Vector2i, sf::Vector2i, std::string>; //offset, size, path
using SpriteWithParam = std::pair<SpritePtr, TextureParameters>;
using SpritesWithParams = std::vector<SpriteWithParam>;

static const TextureParameters GreenGround = std::make_tuple<sf::Vector2i, sf::Vector2i, std::string>(sf::Vector2i(0, 0), sf::Vector2i(80, 80), "../Source/Images/Downloaded/Assets/Tiles.png");

class MapCreator
{
private:
    SpritesWithParams spritesWithParams_{};

    void createMap();
    void setUpMap();


public:
    MapCreator();
    ~MapCreator() = default;
    void drawMap(sf::RenderWindow& i_window);
};




#endif
