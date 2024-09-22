#include <chrono>
#include <iostream>
#include <thread>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Source/Headers/Global.hpp"
#include "Source/Headers/Sprite.hpp"
#include "Source/Headers/Moveable.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ForgottenIsland");
    
    Sprite sprite(sf::Vector2f{300, 150}, sf::Vector2i{60, 100}, "../Source/Images/Human.png");

    Moveable moveable(sf::Vector2f{300, 150}, sf::Vector2i{60, 100}, "../Source/Images/Human.png");


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        moveable.move({3.f, 3.f});

        window.clear();
        sprite.draw(window);
        moveable.draw(window);
        window.display();

        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(20ms);
        }
    }

    return 0;
}

