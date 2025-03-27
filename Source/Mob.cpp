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
    , creature_(HP)
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

void Mob::attack(std::unique_ptr<Mob>& target)
{   
    updateWeaponPosition();
    if (Collider::isColliding(weapon->getRange(), target))
        weapon->attack(target->getCreature());
}

void Mob::control(const EdgePlatforms& edgePlatforms) 
{
    for(const auto& edgePlatform : edgePlatforms)
    {
        if (Collider::isColliding(this->platform_, edgePlatform))
        {
            if (velocity_.x < 0) //Going left
                velocity_.x = this->speed_;
            else
                velocity_.x = -this->speed_;
        }
    }   
}

void Mob::draw(sf::RenderWindow& i_window)
{
    sprite_.setTextureRect(sf::IntRect(size_.x * (currentFrame_ / 48), static_cast<int>(aimDirection) * size_.y, size_.x, size_.y));
    i_window.draw(sprite_);

    if (currentFrame_ <  48 * xFrames_ - 1)
        currentFrame_++;
    else
        currentFrame_ = 0;
}

void Mob::jump()
{
    if(isOnGround)
    {
        velocity_.y = -3.f;
        isOnGround = false;
    }
}

void Mob::updatePosition(const Platforms& platforms)
{
    creature_.update();
    Moveable::updatePosition(platforms);
    updateWeaponPosition();
}

void Mob::updateWeaponPosition()
{
    if (aimDirection == Direction::LEFT)
        weapon->updatePosition(this->getPosition()
                               - sf::Vector2f{weapon->getRange().getSize().x - this->getSize().x, 0.f});
    else
        weapon->updatePosition(this->getPosition());
}
