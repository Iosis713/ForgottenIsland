#pragma once
#ifndef MAP_CREATOR
#define MAP_CREATOR

#include "Global.hpp"
#include "Sprite.hpp"
#include "Platform.hpp"
#include <tuple>
#include <memory>
#include <utility>

using SpritePtr = std::shared_ptr<Sprite>;
using PlatformPtr = std::shared_ptr<Platform>;
using Platforms = std::vector<PlatformPtr>;
using EdgePlatforms = std::vector<sf::RectangleShape>;

class MapCreator
{
private:
    Platforms platforms_{};
    EdgePlatforms edgePlatforms_{};
    void createMap();
    void createLineOfPlatforms(const sf::Vector2f& startPosition, const size_t numberOfCells);
    
public:
    MapCreator();
    ~MapCreator() = default;
    void drawMap(sf::RenderTarget& target) const;
    const Platforms& getPlatforms() const {return this->platforms_;};
    const EdgePlatforms& getEdgePlatforms() const {return this->edgePlatforms_;};
};

#endif
