#pragma once
#ifndef GLOBAL
#define GLOBAL

constexpr int SCREEN_WIDTH = 1920;
constexpr int SCREEN_HEIGHT = 1200;

#include <SFML/Graphics.hpp>

struct TextureParameters
{
    const sf::Vector2i offset_{};
    const sf::Vector2i size_{};
    const std::string filepath_{};

    TextureParameters() = delete;
    TextureParameters(const sf::Vector2i& offset, const sf::Vector2i& size, const std::string& filepath)
        : offset_(offset)
        , size_(size)
        , filepath_(filepath)
        {};

    ~TextureParameters() = default;
};

const static TextureParameters GreenGround(sf::Vector2i(0, 10), sf::Vector2i(80, 70), "../Source/Images/Downloaded/Assets/Tiles.png");

#endif
