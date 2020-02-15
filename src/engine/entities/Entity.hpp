#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
protected:
    sf::RectangleShape _sprite;
public:
    Entity();
    Entity(sf::Vector2f const &);
    virtual void update();
    void draw(sf::RenderTarget &, sf::RenderStates) const override;

    void move(sf::Vector2f const &);
    void move(float x, float y);

    bool colide(Entity *) const;
};