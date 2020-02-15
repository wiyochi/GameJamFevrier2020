#pragma once

#include "Entity.hpp"

class Shot : public Entity
{
private:
    static constexpr float speed = 5;
public:
    Shot();
    void update() override;
    bool isDead();
};