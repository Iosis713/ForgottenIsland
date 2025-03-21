#include <chrono>
#include <iostream>
#include <thread>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Source/Headers/Global.hpp"
#include "Source/Headers/Sprite.hpp"
#include "Source/Headers/Collider.hpp"
#include "Source/Headers/Moveable.hpp"
#include "Source/Headers/Controllable.hpp"
#include "Source/Headers/Harvestable.hpp"
#include "Source/Headers/HarvestableManager.hpp"
#include "Source/Headers/Adventurer.hpp"
#include "Source/Headers/MapCreator.hpp"

using spritePtr = std::shared_ptr<Sprite>;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ForgottenIsland");
    
    std::shared_ptr<Adventurer> player = std::make_shared<Adventurer>(sf::Vector2f{300, 150}
                                                                        , sf::Vector2i{60, 100}
                                                                        , "../Source/Images/Human.png"
                                                                        , 8.f);

    std::shared_ptr<HarvestableManager> harvestManager = std::make_shared<HarvestableManager>();
    
    harvestManager->addNew<Harvestable>(sf::Vector2f{700, 600}
                                        , sf::Vector2i {200, 250}
                                        , "../Source/Images/Tree.png");

    harvestManager->addNew<Harvestable>(sf::Vector2f{1000, 400}
                                        , sf::Vector2i {200, 250}
                                        , "../Source/Images/Tree.png");

    harvestManager->addNew<Harvestable>(sf::Vector2f{800, 250}
                                        , sf::Vector2i {200, 250}
                                        , "../Source/Images/Tree.png");

    harvestManager->addNew<Harvestable>(sf::Vector2f{300, 300}
                                        , sf::Vector2i {200, 250}
                                        , "../Source/Images/Tree.png");
    
    sf::RenderTexture staticLayer;
    staticLayer.create(SCREEN_WIDTH, SCREEN_HEIGHT);
    staticLayer.clear();

    MapCreator mapCreator;
    mapCreator.drawMap(staticLayer);
    staticLayer.display();         
    const static sf::Sprite staticBackground(staticLayer.getTexture());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        player->control();
        player->checkCollisionWithPlatform(mapCreator.getPlatforms());
        player->controlHarvestable(harvestManager);

        harvestManager->organizeAll();

        window.clear();
        window.draw(staticBackground);
        harvestManager->drawAll(window);
        player->draw(window);
        window.display();

        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(20ms);
        }
    }

    return 0;
}

