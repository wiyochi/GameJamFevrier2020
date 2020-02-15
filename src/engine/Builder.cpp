#include "Builder.hpp"

Enemy * Builder::createEnemy(TYPE type, sf::Vector2f const & pos, short path_start)
{
    Enemy * pe = nullptr;
    Path * path = nullptr;
    switch (type)
    {
    case KAMIKAZE:
        pe = new Enemy(sf::Vector2f(100, 100), "enemies/2/1");

        path = new Path(pe);

        path->addPosition(sf::Vector3f(-2000, 0, 5));
        break;
    case XX:
        break;
    case WM:
        break;
    case I:
        break;
    case O:
        break;
    default:
        pe = new Enemy(sf::Vector2f(500, 500), "enemies/1/1");

        path = new Path(pe);

        path->addPosition(sf::Vector3f(50, 50, 5));
        path->addPosition(sf::Vector3f(0, 400, 5));
        path->addPosition(sf::Vector3f(-200, -50, 1));
        path->addPosition(sf::Vector3f(150, -400, 5));

        break;
    }

    pe->setPosition(pos.x, pos.y);
    pe->setPath(path);
    return pe;
}