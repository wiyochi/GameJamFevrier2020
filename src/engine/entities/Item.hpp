#pragma once

#include "Entity.hpp"
#include "../../graphics/TextureManager.hpp"

class Item : public Entity
{
public:
    enum TYPE {MORE_FIRE, ANGLE_FIRE};
    Item(TYPE, sf::Vector2f const &);
    void update() override;
    bool isDead() const {return _isDead;}
    void use() {_isDead = true;}
    TYPE getType() const { return _type; }

private:
    bool _isDead;
    TYPE _type;
};