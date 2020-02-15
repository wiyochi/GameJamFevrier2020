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
    void setPosition(float x, float y) {_sprite.setPosition(x, y);}
    sf::Vector2f getPosition() const { return _sprite.getPosition(); }

    bool colide(Entity *) const;
};