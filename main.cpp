#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Source/Headers/Global.hpp"
#include "Source/Headers/Sprite.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ForgottenIsland");
    
    Sprite sprite(sf::Vector2f{300, 150}, sf::Vector2i{60, 100});

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        sprite.setPosition({900.f, 450.f});

        window.clear();
        sprite.draw(window);
        window.display();
    }

    return 0;
}

