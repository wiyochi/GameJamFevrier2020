#include "Entity.hpp"

Entity::Entity() : Entity(sf::Vector2f(50, 50))
{
    _sprite.setPosition(200, 200);
    _sprite.setFillColor(sf::Color(1., 0., 1.));
}

Entity::Entity(sf::Vector2f const & size)
{
    _sprite.setSize(size);
    _sprite.setOrigin(size.x / 2, size.y / 2);
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

bool Entity::colide(Entity * e) const
{
    return _sprite.getGlobalBounds().intersects(e->_sprite.getGlobalBounds());
}