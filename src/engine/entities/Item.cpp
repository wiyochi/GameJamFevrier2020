#include "Item.hpp"

Item::Item(std::string const & texture, sf::Vector2f const & pos) : Entity(sf::Vector2f(50, 50)), _isDead(false)
{
    _sprite.setTexture(TextureManager::getInstance().getTexture(texture));
    setPosition(pos.x, pos.y);
}

Item * Item::createItem(TYPE t, sf::Vector2f const & pos)
{
    switch (t)
    {
    case MORE_FIRE:
        return new Item("element_01", pos);
        break;
    }
}

void Item::update()
{
    move(-1, 0);
}