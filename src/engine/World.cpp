#include "World.hpp"

World::World()
{

}

void World::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(_player);
}

void World::update()
{
    _player.update();
}