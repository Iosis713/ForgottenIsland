#include <chrono>
#include <iostream>
#include <thread>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Source/Headers/Global.hpp"
#include "Source/Headers/Sprite.hpp"
#include "Source/Headers/Collider.hpp"
#include "Source/Headers/Moveable.hpp"
#include "Source/Headers/Harvestable.hpp"

using spritePtr = std::shared_ptr<Sprite>;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ForgottenIsland");
    
    spritePtr sprite = std::make_shared<Sprite>(sf::Vector2f{300, 150}, sf::Vector2i{60, 100}, "../Source/Images/Human.png");

    std::shared_ptr<Moveable> moveable = std::make_shared<Moveable>(sf::Vector2f{300, 150}, sf::Vector2i{60, 100}, "../Source/Images/Human.png");

    std::shared_ptr<Harvestable> harvestable = std::make_shared<Harvestable>(sf::Vector2f{700, 700}, sf::Vector2i {200, 250}, "../Source/Images/Tree.png");

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        moveable->move({3.f, 3.f});

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
            harvestable->setIsGrown(true);

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            harvestable->setIsGrown(false);

        window.clear();
        sprite->draw(window);
        moveable->draw(window);
        harvestable->draw(window);
        window.display();

        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(20ms);
        }
    }

    return 0;
}

