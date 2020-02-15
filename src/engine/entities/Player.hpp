#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "Shot.hpp"
#include "Entity.hpp"


class Player : public Entity
{
private:
    static constexpr float max_speed = 7.5f;
    static float diag_speed;
    static constexpr float speed_coef = max_speed / 100;
    static constexpr int zero_zone = 10;

    std::vector<Shot *> _shots;
    int _shots_cpt; // Compte le dT entre 2 tires

    void move_inputs();
    void shot_inputs();
    void delete_shots();
public:
    Player();
    void update() override;
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    void shot();
};