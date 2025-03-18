#include "Headers/Moveable.hpp"

Moveable::Moveable(sf::Vector2f position
                , sf::Vector2i size
                , const std::string textureFile
                , float speed)
    : Sprite(position, size, textureFile)
    , speed_(speed)
{}

void Moveable::move(const sf::Vector2f& distance)
{
    sprite_.move(distance);

}

void Moveable::checkCollisionWithPlatform(const Platforms& platforms)
{
    const sf::FloatRect moveableBounds = sprite_.getGlobalBounds();
    const auto platformIt = std::ranges::find_if(platforms, [&](const auto& platform)
        {
            return moveableBounds.intersects(platform->getPlatform().getGlobalBounds());
        });
    
    if (platformIt != platforms.end())
    {
        const sf::FloatRect platformBounds = platformIt->get()->getPlatform().getGlobalBounds();
        setPosition({sprite_.getPosition().x, platformBounds.top - moveableBounds.height});
        velocity_.y = 0;
        isOnGround = true;
    }
    else
    {
        isOnGround = false;
    }
}