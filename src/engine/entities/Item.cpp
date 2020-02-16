#include "Item.hpp"

Item::Item(TYPE type, sf::Vector2f const & pos) : Entity(sf::Vector2f(50, 50)), _isDead(false), _type(type)
{
    switch (type)
    {
        case MORE_FIRE:
            _sprite.setTexture(TextureManager::getInstance().getTexture("element_01"));
            break;
        case ANGLE_FIRE:
            _sprite.setTexture(TextureManager::getInstance().getTexture("element_02"));
            break;
    }
    setPosition(pos.x, pos.y);
}

void Item::update()
{
    move(-1, 0);
}