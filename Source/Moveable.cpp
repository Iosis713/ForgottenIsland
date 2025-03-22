#include "Headers/Moveable.hpp"
#include "Headers/Collider.hpp"

Moveable::Moveable(const sf::Vector2f position
                , const sf::Vector2i size
                , const std::string& textureFile
                , const float speed)
    : Sprite(position, size, textureFile)
    , speed_(speed)
{
    platform_.setSize({static_cast<float>(size.x), static_cast<float>(size.y/20)});
    platform_.setPosition(position.x, position.y + sprite_.getGlobalBounds().height - platform_.getSize().y); //empty field offset
}

void Moveable::move(const sf::Vector2f& distance)
{
    sprite_.move(distance);
    platform_.move(distance);
}

void Moveable::checkCollisionWithPlatform(const Platforms& platforms)
{
    const sf::FloatRect moveableBounds = sprite_.getGlobalBounds();
    const auto platformIt = std::ranges::find_if(platforms, [&](const auto& platform)
        {
            return Collider::isColliding(this->platform_, platform->getPlatform());
        });
    
    if (platformIt != platforms.end() && velocity_.y >= 0.f)
    {
        setPosition({sprite_.getPosition().x, platformIt->get()->getPlatform().getGlobalBounds().top 
                                              - moveableBounds.height});
        platform_.setPosition({sprite_.getPosition().x, sprite_.getPosition().y
                                                        + size_.y 
                                                        - platform_.getSize().y});
        velocity_.y = 0.f;
        isOnGround = true;
    }
    else
    {
        isOnGround = false;
    }
}