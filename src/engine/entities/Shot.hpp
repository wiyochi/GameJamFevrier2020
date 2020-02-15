#pragma once

#include "Entity.hpp"
#include "../../graphics/TextureManager.hpp"

class Shot : public Entity
{
private:
    static constexpr float speed = 5;
public:
    Shot(sf::Vector2f const &);
    void update() override;
    bool isDead();
};