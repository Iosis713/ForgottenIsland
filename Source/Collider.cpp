#include "Headers/Collider.hpp"

bool Collider::isColliding(spritePtr source, spritePtr target)
{
   if(source->getSprite().getGlobalBounds().intersects(
      target->getSprite().getGlobalBounds()))
   {
        return true;
   }
   return false;

}