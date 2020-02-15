#include "World.hpp"

World::World() : _background(sf::Vector2f(1920*2, 1080))
{
    auto pe = new Enemy(sf::Vector2f(50, 50));
    _enemis.push_back(pe);
    pe->setPosition(300, 100);
    TextureManager::getInstance().getTexture("background")->setRepeated(true);
    _background.setTextureRect(sf::IntRect(0, 0, 1920*2, 1080));
    _background.setTexture(TextureManager::getInstance().getTexture("background"));
}

void World::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(_background);
    target.draw(_player);

    for (auto && pe : _enemis) target.draw(*pe);
}

void World::update()
{
    _background.move(-5, 0);
    if(_background.getPosition().x == -1920) _background.move(1920, 0);
    _player.update();
    for (auto && pe : _enemis)
    {
        pe->update();
        if (_player.colide(pe))
        {
            _player.decreaseLife();
        }
    }
}