#include "World.hpp"

World::World() : _background(sf::Vector2f(1920*2, 1080)), _old_life(Player::max_life),
    _frameCounter(0),
    _framePattern(240)
{
    TextureManager::getInstance().getTexture("hearth_b");
    for (int i = 0; i < 5; ++i)
    {
        sf::RectangleShape b(sf::Vector2f(50, 50));
        b.setFillColor(sf::Color::Red);
        b.setTexture(TextureManager::getInstance().getTexture("hearth"));
        b.setPosition(i * 50, 0);
        _life_bar.push_back(b);
    }
    _items.push_back(Item::createItem(Item::MORE_FIRE, sf::Vector2f(1000, 400)));
    _items.push_back(Item::createItem(Item::MORE_FIRE, sf::Vector2f(2000, 400)));
    _items.push_back(Item::createItem(Item::MORE_FIRE, sf::Vector2f(3000, 400)));

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

    for (auto&& i : _items)
        target.draw(*i);
}

void World::update()
{
    _frameCounter++;

    for (auto&& i : _items)
    {
        i->update();
        if (_player.collide(i) && !i->isDead())
        {
            _player.increaseStats(0);
            i->use();
        }
    }

    _items.erase(std::remove_if(_items.begin(), _items.end(), [](auto i){return i->isDead();}), _items.end());

    if (_frameCounter > _framePattern)
    {
        _framePattern = Pattern::getRandomPattern(_enemis);
        _frameCounter = 0;
    }

    _background.move(-5, 0);
    if(_background.getPosition().x == -1920) _background.move(1920, 0);
    _player.update();
    if (_old_life != _player.getLife())
    {
        _life_bar[_player.getLife()].setTexture(TextureManager::getInstance().getTexture("hearth_b"));
    }

    for (auto&& s : _player.getShots())
    {
        for (auto && pe : _enemis)
        {
            if (s->collide(pe))
            {
                pe->kill();
            }
        }
    }

    _enemis.erase(std::remove_if(_enemis.begin(), _enemis.end(), [](auto e){return e->isDeletable();}), _enemis.end());

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