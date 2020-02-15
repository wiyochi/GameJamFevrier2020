#include "Shot.hpp"

Shot::Shot()
{
    _sprite.setSize(sf::Vector2f(20, 20));
}

void Shot::update()
{
    move(speed, 0);
}

bool Shot::isDead()
{
    return false;
}