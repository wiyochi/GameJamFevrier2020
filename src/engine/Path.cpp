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
}

void Path::update()
{
    if (std::abs(_objective.x) >= eps_x)
    {
        float angle = std::atan(_positions[_positionIndex].y / _positions[_positionIndex].x);
        float nx = std::abs(std::cos(angle) * speed) * ((_objective.x < 0) ? -1.f : 1.f);
        _entity->move(nx, 0);
        _objective.x -= nx;
    }
    if (std::abs(_objective.y) >= eps_y)
    {
        float ny = std::abs(std::sin(std::atan(_positions[_positionIndex].y / _positions[_positionIndex].x)) * speed) * ((_objective.y < 0) ? -1.f : 1.f);
        _entity->move(0, ny);
        _objective.y -= ny;
    }

    if (std::abs(_objective.y) < eps_y && std::abs(_objective.x) < eps_x)
    {
        _positionIndex = (_positionIndex + 1) % _positions.size();
        _objective = _positions[_positionIndex];
    }
}