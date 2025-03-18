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

class MapCreator
{
private:
    Platforms platforms_{};
    void createMap();
    
public:
    MapCreator();
    ~MapCreator() = default;
    void drawMap(sf::RenderWindow& i_window);
    const Platforms& getPlatforms() {return this->platforms_;};
};




#endif
