#pragma once

#include "Entity.hpp"
#include "../../graphics/TextureManager.hpp"

class Item : public Entity
{
private:
    bool _isDead;
public:
    enum TYPE {MORE_FIRE};
    Item(TYPE, sf::Vector2f const &);
    void update() override;
    bool isDead() const {return _isDead;}
    void use() {_isDead = true;}
};