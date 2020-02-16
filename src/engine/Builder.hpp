#pragma once

#include "entities/Enemy.hpp"

class Builder
{
public:
    enum TYPE { KAMIKAZE, NX, RX, WM, MW, I, O};
    static Enemy * createEnemy(TYPE, sf::Vector2f const &, short = 0);
};