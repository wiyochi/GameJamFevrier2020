#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.hpp"


class World : public sf::Drawable
{
private:
    Entity _player;
public:
    World();
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
};