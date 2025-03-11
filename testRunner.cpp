#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <tuple>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Source/Headers/Global.hpp"
#include "Source/Headers/Sprite.hpp"
#include "Source/Headers/Collider.hpp"
#include "Source/Headers/Resource.hpp"
#include "Source/Headers/Inventory.hpp"

class SourceSpriteFixture : public testing::TestWithParam<std::tuple<sf::Vector2f, bool>>
{
public:
    std::shared_ptr<Sprite> sourceSprite = std::make_shared<Sprite>(sf::Vector2f{500.f, 500.f}, sf::Vector2i{50, 50}, "../Source/Images/Human.png");
};

TEST_P(SourceSpriteFixture, Collision_TEST)
{
    std::tuple<sf::Vector2f, bool> tuple = GetParam();
    sf::Vector2f targetPosition = std::get<0>(tuple);
    std::shared_ptr<Sprite> targetSprite = std::make_shared<Sprite>(targetPosition, sf::Vector2i{50, 50}, "../Source/Images/Human.png");

    sf::RenderWindow window (sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TEST");
    sourceSprite->draw(window);
    targetSprite->draw(window);

    ASSERT_EQ(Collider::isColliding(sourceSprite, targetSprite), std::get<1>(tuple));
};

INSTANTIATE_TEST_CASE_P(CollisionT, SourceSpriteFixture, testing::Values
    (
        std::make_tuple(sf::Vector2f(450.f, 450.f), true),//VERTICES
        std::make_tuple(sf::Vector2f(550.f, 450.f), true),
        std::make_tuple(sf::Vector2f(450.f, 550.f), true),
        std::make_tuple(sf::Vector2f(550.f, 450.f), true),
        std::make_tuple(sf::Vector2f(470.f, 450.f), true),//EDGES
        std::make_tuple(sf::Vector2f(450.f, 470.f), true),
        std::make_tuple(sf::Vector2f(470.f, 550.f), true),
        std::make_tuple(sf::Vector2f(550.f, 470.f), true),
        std::make_tuple(sf::Vector2f(470.f, 480.f), true),
        std::make_tuple(sf::Vector2f(440.f, 440.f), false) /*Out of range*/
    ));

class InventoryFixture : public testing::Test
{
protected:
    Inventory inventory;

public:
    void SetUp() override;
};

//____________________________SORTING TEST______________________________//

TEST_F(InventoryFixture, InventorySortingByAmount_TEST)
{
    //WHEN
    inventory.sortByAmount();

    //THEN
    ASSERT_EQ(inventory.getItems()[0]->amount_, 70);
}

TEST_F(InventoryFixture, InventorySortingByName_TEST)
{
    //WHEN
    inventory.sortByName();

    //THEN
    ASSERT_EQ(inventory.getItems()[0]->name_, "Ash");
}   

TEST_F(InventoryFixture, InventorySortingByUnitValue_TEST)
{
    //WHEN
    inventory.sortByUnitValue();

    //THEN
    ASSERT_EQ(inventory.getItems()[0]->value_, 10);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

void InventoryFixture::SetUp()
{
    inventory.add(std::make_shared<Resource>(ResourceName::Wheat, "Wheat", 10, 160));
    inventory.add(std::make_shared<Resource>(ResourceName::Ash, "Ash", 30, 100));
    inventory.add(std::make_shared<Resource>(ResourceName::Iron, "Iron", 20, 80));
    inventory.add(std::make_shared<Resource>(ResourceName::Rock, "Rock", 40, 70));
}