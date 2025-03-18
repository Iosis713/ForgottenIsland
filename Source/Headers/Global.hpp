#pragma once
#ifndef GLOBAL
#define GLOBAL

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1200;

#include <tuple>
#include <SFML/Graphics.hpp>

using TextureParameters = std::tuple<sf::Vector2i, sf::Vector2i, std::string>; //offset, size, path
const TextureParameters GreenGround = std::make_tuple<sf::Vector2i, sf::Vector2i, std::string>(sf::Vector2i(0, 10), sf::Vector2i(80, 70), "../Source/Images/Downloaded/Assets/Tiles.png");


#endif
