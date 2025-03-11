#pragma once
#ifndef SPRITE
#define SPRITE

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

class Sprite
{
protected:
    sf::Vector2i size_;
    sf::Sprite sprite_;
    const std::string textureFile_;
    
public: 
    
    Sprite() = default;
    Sprite(sf::Vector2f position, sf::Vector2i size, const std::string textureFile); 
    virtual ~Sprite() = default;
    
    virtual void draw(sf::RenderWindow& i_window);

    //GETTERS
    const sf::Vector2f getPosition() const;
    const sf::Vector2i getSize() const;
    const sf::Sprite& getSprite() const;

    //SETTERS
    void setPosition(const sf::Vector2f& position);

};

#endif
