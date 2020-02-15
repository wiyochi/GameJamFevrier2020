#pragma once

#include <vector>
#include "SFML/Graphics.hpp"

#include "entities/Entity.hpp"
#include "entities/Player.hpp"
#include "entities/Enemy.hpp"

class World : public sf::Drawable
{
private:
    Player _player;
    std::vector<Enemy*> _enemis;
public:
    World();
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    void update();
    Player & getPlayer() {return _player;}
};