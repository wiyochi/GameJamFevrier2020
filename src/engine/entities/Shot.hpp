#pragma once

#include "Entity.hpp"
#include "../Path.hpp"
#include "../../graphics/TextureManager.hpp"

class Shot : public Entity
{
private:
    static constexpr float speed = 15;
    Path * _path;
public:
    Shot(sf::Vector2f const &);
    void update() override;
    bool isDead();
    void setPath(Path * p) {_path = p;}
};