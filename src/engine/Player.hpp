#pragma once

#include "Entity.hpp"

class Player : public Entity
{
public:
    Player();
    void update() override;
};