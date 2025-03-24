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
    const size_t xFrames_ = 0;
    const size_t yFrames_ = 0;

    TextureParameters() = delete;
    
    TextureParameters(const sf::Vector2i& offset, const sf::Vector2i& size, const std::string& filepath, const size_t xFrames, const size_t yFrames)
        : offset_(offset)
        , size_(size)
        , filepath_(filepath)
        , xFrames_(xFrames)
        , yFrames_(yFrames)
        {};

    TextureParameters(const sf::Vector2i& offset, const sf::Vector2i& size, const std::string& filepath)
        : TextureParameters(offset, size, filepath, 0, 0)
        {};

    ~TextureParameters() = default;
};

const static TextureParameters GreenGround(sf::Vector2i(0, 10), sf::Vector2i(80, 70), "../Source/Images/Downloaded/Assets/Tiles.png");
const static TextureParameters Snail(sf::Vector2i(0, 0), sf::Vector2i(72, 48), "../Source/Images/Downloaded/Mob/Snail/Snail.png", 8, 2); 
#endif
