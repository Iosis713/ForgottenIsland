#include "Headers/Mob.hpp"
#include "Headers/Collider.hpp"

Mob::Mob(const sf::Vector2f position
    , const sf::Vector2i size
    , const std::string& textureFile
    , const float speed
    , const int HP
    , const int xFrames
    , const int yFrames)
    : Moveable(position, size, textureFile, speed)
    , Alive(HP)
    , xFrames_(xFrames)
    , yFrames_(yFrames)
{
    velocity_.x = -speed;
    platform_.setSize({static_cast<float>(size.x), static_cast<float>(size.y/20)});
    platform_.setPosition(position.x, position.y + sprite_.getGlobalBounds().height - platform_.getSize().y); //empty field offset
};

Mob::Mob(const sf::Vector2f position
         , const sf::Vector2i size
         , const std::string& textureFile
         , const float speed
         , const int HP)
    : Mob(position, size, textureFile, speed, HP, 0, 0)
{};

void Mob::control(const EdgePlatforms& edgePlatforms) 
{
    if (!isOnGround)
        velocity_.y = 2.f;
    else
        velocity_.y = 0.f;

    for(const auto& edgePlatform : edgePlatforms)
    if (Collider::isColliding(this->platform_, edgePlatform))
    {
        if (velocity_.x < 0) //Going left
            velocity_.x = this->speed_;
        else
            velocity_.x = -this->speed_;
    }
    control();
}

void Mob::draw(sf::RenderWindow& i_window)
{
    using enum Direction;
    const int direction = velocity_.x < 0 ? static_cast<int>(LEFT) : static_cast<int>(RIGHT);
    sprite_.setTextureRect(sf::IntRect(size_.x * (currentFrame_ / 6), direction * size_.y, size_.x, size_.y));
    i_window.draw(sprite_);

    if (currentFrame_ <  6 * xFrames_ - 1)
        currentFrame_++;
    else
        currentFrame_ = 0;
}