#pragma once
#ifndef SPRITE
#define SPRITE

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

class Sprite
{
protected:
    //sf::Vector2f position_;
    sf::Vector2i size_;
    sf::Sprite sprite_;
    
public: 
    
    Sprite() = default;
    Sprite(sf::Vector2f position, sf::Vector2i size); 
    virtual ~Sprite() = default;
    
    void draw(sf::RenderWindow& i_window);

    //GETTERS
    const auto getPosition() const;

    //SETTERS
    void setPosition(sf::Vector2f position);

};

#endif
