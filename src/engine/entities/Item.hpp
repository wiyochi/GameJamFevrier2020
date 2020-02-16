#pragma once

#include "Entity.hpp"
#include "../../graphics/TextureManager.hpp"

class Item : public Entity
{
private:
    Item(std::string const &, sf::Vector2f const &);
    bool _isDead;
public:
    enum TYPE {MORE_FIRE};
    static Item* createItem(TYPE t, sf::Vector2f const &);
    void update() override;
    bool isDead() const {return _isDead;}
    void use() {_isDead = true;}
};