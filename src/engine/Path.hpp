#ifndef PATH_HPP
#define PATH_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "entities/Entity.hpp"

class Path
{
public:
    Path(Entity* entity);
    ~Path();

    float getMaxX() const;
    void addPosition(sf::Vector3f const & pos);
    void update();

private:
    static constexpr float eps_x = 5.f;
    static constexpr float eps_y = 5.f;

    std::vector<sf::Vector3f> _positions;
    sf::Vector3f _objective;
    Entity * _entity;
    unsigned _positionIndex;
    sf::Vector2f _movement;
};

#endif