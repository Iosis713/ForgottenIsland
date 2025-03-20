#pragma once
#ifndef PLATFORM
#define PLATFROM

#include "Sprite.hpp"
#include "Global.hpp"

class Platform : public Sprite
{
protected:
    sf::RectangleShape platform_{};

public:
    Platform() = delete;
    Platform(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile);
    virtual ~Platform() = default;
    const sf::RectangleShape& getPlatform() {return this->platform_;};
};

#endif
