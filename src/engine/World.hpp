#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.hpp"
#include "Player.hpp"


class World : public sf::Drawable
{
private:
    Player _player;
public:
    World();
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    void update();
};