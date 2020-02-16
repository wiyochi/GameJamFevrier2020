#include "World.hpp"

World::World() : _background(sf::Vector2f(1920*2, 1080))
{
    for (int i = 0; i < 5; ++i)
    {
        sf::RectangleShape b(sf::Vector2f(50, 50));
        b.setFillColor(sf::Color::Red);
        b.setTexture(TextureManager::getInstance().getTexture("hearth"));
        b.setPosition(i * 50, 0);
        _life_bar.push_back(b);
    }
    auto pe = Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(400, 200));
    _enemis.push_back(pe);
    pe->setPosition(4000, 200);
    auto p2 = Builder::createEnemy(Builder::RX, sf::Vector2f(400, 200));
    _enemis.push_back(p2);
    p2->setPosition(2000, 1200);

    for (int i = 0; i < 10; ++i)
    {
        auto p3 = Builder::createEnemy(Builder::NX, sf::Vector2f(400, 200));
        _enemis.push_back(p3);
        p3->setPosition(2000, 200 + i * 40);
    }

    auto p4 = Builder::createEnemy(Builder::WM, sf::Vector2f(400, 200));
    _enemis.push_back(p4);
    p4->setPosition(1800, 200);

    auto p5 = Builder::createEnemy(Builder::MW, sf::Vector2f(400, 200));
    _enemis.push_back(p5);
    p5->setPosition(1800, 200);

    auto p6 = Builder::createEnemy(Builder::I, sf::Vector2f(400, 200));
    _enemis.push_back(p6);
    p6->setPosition(1800, 0);

    auto p7 = Builder::createEnemy(Builder::O, sf::Vector2f(400, 200));
    _enemis.push_back(p7);
    p7->setPosition(1600, 500);

    TextureManager::getInstance().getTexture("background")->setRepeated(true);
    _background.setTextureRect(sf::IntRect(0, 0, 1920*2, 1080));
    _background.setTexture(TextureManager::getInstance().getTexture("background"));
}

void World::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(_background);
    target.draw(_player);

    for (auto && pe : _enemis) target.draw(*pe);

    for (auto&& b : _life_bar)
        target.draw(b);
}

void World::update()
{
    _background.move(-5, 0);
    if(_background.getPosition().x == -1920) _background.move(1920, 0);
    _player.update();
    if (_old_life != _player.getLife())
    {
        _life_bar[_player.getLife()].setTexture(TextureManager::getInstance().getTexture("hearth_b"));
    }
    for (auto && pe : _enemis)
    {
        pe->update();
        if (_player.collide(pe))
        {
            _player.decreaseLife();
        } else 
        {
            for (auto && ps : pe->getShots())
            {
                if (_player.collide(ps))
                    _player.decreaseLife();
            }
        }
    }
}