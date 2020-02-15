#pragma once

#include <vector>
#include <string>

#include "Entity.hpp"
#include "../../graphics/TextureManager.hpp"
#include "Shot.hpp"
#include "../Path.hpp"

class Enemy : public Entity
{
private:
    std::vector<Shot *> _shots;
    int _shots_cpt;
    Path* _path;
public:
    Enemy(sf::Vector2f const &, std::string const &);
    ~Enemy();
    void update() override;
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    void setPath(Path * p) {_path = p;}
};