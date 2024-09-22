#include "Headers/Collider.hpp"

bool Collider::isColliding(spritePtr source, spritePtr target)
{
    //origin set to the middle of sprite
    /*sf::Vector2f sourcePosition = {source->getPosition().x - source->getSize().x
                                    , source->getPosition().y - source->getSize().y};
    sf::Rect

    sf::Rect sourceRect(sourcePosition, source->getSize());
    
    sf::Vector2f targetPosition = {target->getPosition().x - target->getSize().x
                                    , target->getPosition().y - target->getSize().y};

    */

   if(source->getSprite().getGlobalBounds().intersects(
      target->getSprite().getGlobalBounds()))
   {
        return true;
   }
   return false;

}