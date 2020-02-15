#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
private:
    sf::RectangleShape _sprite;
public:
    Entity();
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
};