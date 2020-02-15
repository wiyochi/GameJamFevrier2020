#include "World.hpp"

World::World()
{
    _enemis.push_back(new Enemy(sf::Vector2f(50, 50)));
}

void World::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(_player);

    for (auto && pe : _enemis) target.draw(*pe);
}

void World::update()
{
    _player.update();
    for (auto && pe : _enemis)
    {
        if (_player.colide(pe))
        {
            _player.decreaseLife();
        }
    }
}