#include "World.hpp"

std::mt19937 World::gen(457);
std::normal_distribution<> World::dist_time(1600, 200);
std::uniform_int_distribution<> World::dist_spawn(200, 800);
std::uniform_int_distribution<> World::dist_type(0, 1);

World::World() : _background(sf::Vector2f(1920*2, 1080)), _old_life(Player::max_life),
    _frameCounterPattern(0),
    _framePattern(240),
    _frameCounterItem(0),
    _frameItem(400)
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
    _frameCounterPattern++;
    _frameCounterItem++;

    for (auto&& i : _items)
    {
        i->update();
        if (_player.collide(i) && !i->isDead())
        {
            _player.increaseStats(i->getType());
            i->use();
        }
    }

    _items.erase(std::remove_if(_items.begin(), _items.end(), [](auto i){return i->isDead();}), _items.end());

    if (_frameCounterPattern > _framePattern)
    {
        _framePattern = Pattern::getRandomPattern(_enemis);
        _frameCounterPattern = 0;
    }

    if (_frameCounterItem > _frameItem)
    {
        _items.push_back(new Item(static_cast<Item::TYPE>(dist_type(gen)), sf::Vector2f(2000, dist_spawn(gen))));
        _frameItem = dist_time(gen);
        _frameCounterItem = 0;
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
                pe->hurt();
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