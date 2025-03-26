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
#include "Source/Headers/HarvestableManager.hpp"
#include "Source/Headers/Adventurer.hpp"
#include "Source/Headers/MapCreator.hpp"


void fpsDisplay(int& fps, sf::Clock& clock, sf::Text& fpsText, sf::RenderWindow& window);

using spritePtr = std::shared_ptr<Sprite>;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "ForgottenIsland");
    
    sf::Clock clock;
    int fps = 0;
    sf::Font font;
    font.loadFromFile("../Source/Arial.ttf");
    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(24);
    fpsText.setFillColor(sf::Color::Yellow);
    fpsText.setPosition({SCREEN_WIDTH - 200, 10});

    std::shared_ptr<Adventurer> player = std::make_shared<Adventurer>(sf::Vector2f{300, 150}
                                                                        , sf::Vector2i{60, 100}
                                                                        , "../Source/Images/Human.png"
                                                                        , 0.5f
                                                                        , 50);

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

    std::shared_ptr<Mob> snail = std::make_shared<Mob>(sf::Vector2f{600, 500}
                                            , Snail.size_
                                            , Snail.filepath_
                                            , 0.1f
                                            , 10
                                            , Snail.xFrames_
                                            , Snail.yFrames_);
    
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
        player->updatePosition(mapCreator.getPlatforms());
        player->controlHarvestable(harvestManager);

        snail->control(mapCreator.getEdgePlatforms());
        snail->updatePosition(mapCreator.getPlatforms());

        harvestManager->organizeAll();

        window.clear();
        window.draw(staticBackground);
        fpsDisplay(fps, clock, fpsText, window);
        harvestManager->drawAll(window);
        player->draw(window);
        snail->draw(window);
        window.display();
    }
    return 0;
}

void fpsDisplay(int& fps, sf::Clock& clock, sf::Text& fpsText, sf::RenderWindow& window)
{
    fps++;
        if (clock.getElapsedTime().asSeconds() >= 1.0f)
        {
            fpsText.setString(std::format("FPS: {}", fps));
            fps = 0;
            clock.restart();
        }
    window.draw(fpsText);
};