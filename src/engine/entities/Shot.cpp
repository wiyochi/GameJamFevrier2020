#include "Shot.hpp"

Shot::Shot(sf::Vector2f const & pos) : Entity(sf::Vector2f(50, 50)), _path(nullptr)
{  
    _sprite.setPosition(pos);
    _sprite.setTexture(TextureManager::getInstance().getTexture("shots/Bullet-1"));
}

void Shot::update()
{
    if (_path != nullptr)
        _path->update();
    else 
        move(Shot::speed, 0);
}

bool Shot::isDead()
{
    return false;
}