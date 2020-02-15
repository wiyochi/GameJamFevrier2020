#pragma once

#include <vector>
#include "SFML/Graphics.hpp"

#include "entities/Entity.hpp"
#include "entities/Player.hpp"
#include "entities/Enemy.hpp"
#include "../graphics/TextureManager.hpp"
#include "Builder.hpp"

class World : public sf::Drawable
{
private:
    Player _player;
    std::vector<Enemy*> _enemis;
    sf::RectangleShape _background;
public:
    World();
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    void update();
    Player & getPlayer() {return _player;}
};