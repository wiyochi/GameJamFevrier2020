#include "Item.hpp"

Item::Item(TYPE type, sf::Vector2f const & pos) : Entity(sf::Vector2f(50, 50)), _isDead(false)
{
    switch (type)
    {
        case MORE_FIRE:
            _sprite.setTexture(TextureManager::getInstance().getTexture("element_01"));
            break;
    }
    setPosition(pos.x, pos.y);
}

void Item::update()
{
    move(-1, 0);
}