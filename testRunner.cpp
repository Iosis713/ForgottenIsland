#include <iostream>
#include <gtest/gtest.h>
#include <tuple>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Source/Headers/Sprite.hpp"

class SourceSpriteFixture : public testing::TestWithParam<std::tuple<sf::Vector2f, bool>>
{
public:
    std::shared_ptr<Sprite> sourceSprite = std::make_shared<Sprite>(sf::Vector2f{500.f, 500.f}, sf::Vector2i{50, 50}, "../Source/Images/Human.png");
};

TEST_P(SourceSpriteFixture, CollisionTest)
{
    std::tuple<sf::Vector2f, bool> tuple = GetParam();
    sf::Vector2f targetPosition = std::get<0>(tuple);
    std::shared_ptr<Sprite> targetSprite = std::make_shared<Sprite>(targetPosition, sf::Vector2i{50, 50}, "../Source/Images/Human.png");

}

INSTANTIATE_TEST_CASE_P(CollisionT, SourceSpriteFixture, testing::Values
    (
        std::make_tuple(sf::Vector2f(450.f, 450.f), true),//VERTICES
        std::make_tuple(sf::Vector2f(550.f, 450.f), true),
        std::make_tuple(sf::Vector2f(450.f, 550.f), true),
        std::make_tuple(sf::Vector2f(550.f, 450.f), false),
        std::make_tuple(sf::Vector2f(470.f, 450.f), true),//EDGES
        std::make_tuple(sf::Vector2f(450.f, 470.f), true),
        std::make_tuple(sf::Vector2f(470.f, 550.f), false),
        std::make_tuple(sf::Vector2f(550.f, 470.f), false),
        std::make_tuple(sf::Vector2f(470.f, 480.f), true)));


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}