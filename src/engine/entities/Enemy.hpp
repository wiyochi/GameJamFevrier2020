#pragma once

#include <vector>

#include "Entity.hpp"
#include "Shot.hpp"

class Enemy : public Entity
{
private:
    std::vector<Shot *> _shots;
    int _shots_cpt;
public:
    Enemy(sf::Vector2f const &);
    void update() override;
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
};