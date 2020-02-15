#include "Path.hpp"

Path::Path(Entity* entity) :
    _entity(entity),
    _positionIndex(0)
{
}

Path::~Path()
{
}

float Path::getMaxX() const
{
    float max = std::numeric_limits<float>::min();
    for (auto &&pos : _positions)
    {
        if (pos.x > max)
            max = pos.x;
    }
    return max;
}

void Path::addPosition(sf::Vector2f const & pos)
{
    _positions.push_back(pos);
    _objective = _positions[0];

    float angle = std::atan(_positions[_positionIndex].y / _positions[_positionIndex].x);
    _movement.x = std::abs(std::cos(angle) * speed) * ((_objective.x < 0) ? -1.f : 1.f);
    _movement.y = std::abs(std::sin(angle) * speed) * ((_objective.y < 0) ? -1.f : 1.f);
}

void Path::update()
{
    if (std::abs(_objective.x) >= eps_x)
    {
        _entity->move(_movement.x, 0);
        _objective.x -= _movement.x;
    }
    if (std::abs(_objective.y) >= eps_y)
    {
        _entity->move(0, _movement.y);
        _objective.y -= _movement.y;
    }

    if (std::abs(_objective.y) < eps_y && std::abs(_objective.x) < eps_x)
    {
        _positionIndex = (_positionIndex + 1) % _positions.size();
        _objective = _positions[_positionIndex];

        float angle = std::atan(_positions[_positionIndex].y / _positions[_positionIndex].x);
        _movement.x = std::abs(std::cos(angle) * speed) * ((_objective.x < 0) ? -1.f : 1.f);
        _movement.y = std::abs(std::sin(angle) * speed) * ((_objective.y < 0) ? -1.f : 1.f);
    }
}