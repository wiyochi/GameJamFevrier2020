#pragma once

#include <vector>
#include "SFML/Graphics.hpp"

#include "entities/Entity.hpp"
#include "entities/Player.hpp"
#include "entities/Enemy.hpp"
#include "../graphics/TextureManager.hpp"
#include "Builder.hpp"
#include "entities/Item.hpp"
#include "Pattern.hpp"

class World : public sf::Drawable
{
private:
    static std::mt19937 gen;
    static std::normal_distribution<> dist_time;
    static std::uniform_int_distribution<> dist_spawn;

    Player _player;
    std::vector<Enemy*> _enemis;
    std::vector<Item*> _items;
    sf::RectangleShape _background;
    int _old_life;
    std::vector<sf::RectangleShape> _life_bar;
    sf::Text _player_life;
    int _frameCounterPattern;
    int _framePattern;

    int _frameCounterItem;
    int _frameItem;
public:
    World();
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    void update();
    Player & getPlayer() {return _player;}
};