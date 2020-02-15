#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f const & size, std::string const & texture_path) : Entity(size), _shots_cpt(0)
{
    _sprite.setTexture(TextureManager::getInstance().getTexture(texture_path));
    _sprite.scale(sf::Vector2f(-1, 1));
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