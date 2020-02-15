#ifndef PATH_HPP
#define PATH_HPP

#include <vector>
#include <SFML/Graphics.hpp>

class Path
{
public:
    Path();
    ~Path();

private:
    std::vector<sf::Vector2f> _positions;
};

#endif