#include "World.hpp"

World::World()
{
    auto pe = new Enemy(sf::Vector2f(10, 10));
    _enemis.push_back(pe);
    pe->setPosition(300, 100);
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