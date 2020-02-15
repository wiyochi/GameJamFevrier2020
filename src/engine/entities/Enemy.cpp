#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f const & size) : Entity(size)
{
    _sprite.setTexture(TextureManager::getInstance().getTexture("enemies/1/1"));
}

void Enemy::update()
{
}