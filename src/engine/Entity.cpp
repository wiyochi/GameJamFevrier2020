#include "Entity.hpp"

Entity::Entity()
{
    _sprite.setSize(sf::Vector2f(50, 50));
    _sprite.setPosition(200, 200);
    _sprite.setFillColor(sf::Color::Red);
}

void Entity::update()
{

}

void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(_sprite);
}


void Entity::move(sf::Vector2f const & vec)
{
    _sprite.move(vec);
}

void Entity::move(float x, float y)
{
    _sprite.move(x, y);
}