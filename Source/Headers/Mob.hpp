#pragma once
#ifndef MOB
#define MOB

#include <memory>

#include "Moveable.hpp"
#include "Alive.hpp"
#include "Weapon.hpp"

class Mob : public Moveable
{
protected:
    std::shared_ptr<Weapon> weapon = std::make_shared<HarmByTouch>(2, 4);
    Alive creature_{1};
    const int xFrames_ = 0;
    const int yFrames_ = 0;
    int currentFrame_ = 0;
    
public:
    Mob() = delete;
    virtual ~Mob() = default;
    Mob(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile, const float speed, const int HP, const int xFrames, const int yFrames);
    Mob(const sf::Vector2f position, const sf::Vector2i size, const std::string& textureFile, const float speed, const int HP);
    
    void attack(std::unique_ptr<Mob>& target);
    void control() override {move(velocity_);};
    void control(const EdgePlatforms& edgePlatforms);
    void draw(sf::RenderWindow& i_window) override;
    
    Alive& getCreature() {return this->creature_;};
    std::shared_ptr<Weapon>& getWeapon() {return this->weapon;};
    int getHP() const {return this->creature_.getHP();};
    void setWeapon(std::shared_ptr<Weapon> newWeapon) {weapon = newWeapon;};

};

enum class Direction : int
{
    LEFT = 0,
    RIGHT = 1
};

#endif
