#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
private:
    sf::RectangleShape _sprite;
public:
    Entity();
    virtual void update();
    void draw(sf::RenderTarget &, sf::RenderStates) const override;

    void move(sf::Vector2f const &);
    void move(float x, float y);
};