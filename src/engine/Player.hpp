#pragma once

#include <iostream>
#include <cmath>
#include "Entity.hpp"


class Player : public Entity
{
private:
    static constexpr float max_speed = 7.5f;
    static float diag_speed;
    static constexpr float speed_coef = max_speed / 100;
    static constexpr int zero_zone = 10;
public:
    Player();
    void update() override;
};