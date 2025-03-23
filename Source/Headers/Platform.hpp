#pragma once
#ifndef PLATFORM
#define PLATFROM

#include "Sprite.hpp"

class Platform : public Sprite
{
protected:
    const bool isEdgePlatform_ = false;
    sf::RectangleShape platform_{};

public:
    Platform() = delete;
    Platform(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile, const bool isEdgePlatform);
    Platform(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile);
    virtual ~Platform() = default;
    const sf::RectangleShape& getPlatform() {return this->platform_;};
    bool IsEdgePlatform() const {return this->isEdgePlatform_;};

    void drawPlatform(sf::RenderTarget& target) ;
};

#endif
