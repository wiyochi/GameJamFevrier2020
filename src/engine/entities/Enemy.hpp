#pragma once

#include "Entity.hpp"
#include "../../graphics/TextureManager.hpp"

class Enemy : public Entity
{
private:

public:
    Enemy(sf::Vector2f const &);
    void update() override;
};