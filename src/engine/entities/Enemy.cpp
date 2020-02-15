#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f const & size) : Entity(size), _shots_cpt(0)
{
    _sprite.setTexture(TextureManager::getInstance().getTexture("enemies/1/1"));
    _path = new Path(this);

    _path->addPosition(sf::Vector3f(50, 50, 5));
    _path->addPosition(sf::Vector3f(0, 400, 5));
    _path->addPosition(sf::Vector3f(-200, -50, 1));
    _path->addPosition(sf::Vector3f(150, -400, 5));
}

Enemy::~Enemy()
{
    delete _path;
}

void Enemy::update()
{
    _path->update();

    constexpr auto max_dt = 120;
    if (_shots_cpt == 0)
    {
        _shots.push_back(new Shot(_sprite.getPosition()));
        _shots_cpt = max_dt;
    }
    _shots_cpt--;


    for(auto && ps : _shots)
        ps->update();
}

void Enemy::draw(sf::RenderTarget & target, sf::RenderStates states) const 
{
    Entity::draw(target, states);

    for(auto && ps : _shots)
        target.draw(*ps);
}