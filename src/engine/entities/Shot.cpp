#include "Shot.hpp"

Shot::Shot(sf::Vector2f const & pos) : Entity(sf::Vector2f(20, 20))
{  
    _sprite.setPosition(pos);
    _sprite.setTexture(TextureManager::getInstance().getTexture("shots/Bullet-1"));
}

void Shot::update()
{
    move(speed, 0);
}

bool Shot::isDead()
{
    return false;
}