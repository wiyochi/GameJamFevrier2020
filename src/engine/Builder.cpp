#include "Builder.hpp"

Enemy * Builder::createEnemy(TYPE type, sf::Vector2f const & pos, short path_start)
{
    Enemy * pe = nullptr;
    Path * path = nullptr;
    switch (type)
    {
    case KAMIKAZE:
        pe = new Enemy(sf::Vector2f(100, 100), "enemies/1");
        path = new Path(pe);
        path->addPosition(sf::Vector3f(-2000, 0, 10));
        pe->setShotPathModel();
        break;
    case NX:
        pe = new Enemy(sf::Vector2f(100, 100), "enemies/2");
        path = new Path(pe);
        path->addPosition(sf::Vector3f(-1400, 1100, 5));
        pe->setShotPathModel();
        break;
    case RX:
        pe = new Enemy(sf::Vector2f(100, 100), "enemies/2");
        path = new Path(pe);
        path->addPosition(sf::Vector3f(-1400, -1100, 5));
        pe->setShotPathModel();
        break;
    case WM:
        pe = new Enemy(sf::Vector2f(100, 100), "enemies/3", 1);
        path = new Path(pe);
        path->addPosition(sf::Vector3f(0, -200, 5));
        path->addPosition(sf::Vector3f(0, 200, 5));
        pe->setShotPathModel();
        break;
    case MW:
        pe = new Enemy(sf::Vector2f(100, 100), "enemies/3", 20);
        path = new Path(pe);
        path->addPosition(sf::Vector3f(0, 200, 5));
        path->addPosition(sf::Vector3f(0, -200, 5));
        pe->setShotPathModel();
        break;
    case I:
        pe = new Enemy(sf::Vector2f(100, 100), "enemies/4");
        path = new Path(pe);
        path->addPosition(sf::Vector3f(0, 500, 5));
        path->addPosition(sf::Vector3f(0, 100, 1));
        path->addPosition(sf::Vector3f(0, 480, 6));
        path->addPosition(sf::Vector3f(0, -480, 1));
        path->addPosition(sf::Vector3f(0, -100, 6));
        path->addPosition(sf::Vector3f(0, -500, 5));
        pe->setShotPathModel();
        break;
    case O:
        pe = new Enemy(sf::Vector2f(100, 100), "enemies/5");
        path = new Path(pe);
        path->addPosition(sf::Vector3f(120, -200, 5));
        path->addPosition(sf::Vector3f(100, 0, 5));
        path->addPosition(sf::Vector3f(120, 200, 5));
        path->addPosition(sf::Vector3f(0, 200, 5));
        path->addPosition(sf::Vector3f(-120, 200, 5));
        path->addPosition(sf::Vector3f(-200, 0, 5));
        path->addPosition(sf::Vector3f(-120, -200, 5));
        path->addPosition(sf::Vector3f(0, -200, 5));
        pe->setShotPathModel();
        break;
    default:
        pe = new Enemy(sf::Vector2f(500, 500), "enemies/6");

        path = new Path(pe);

        path->addPosition(sf::Vector3f(50, 50, 5));
        path->addPosition(sf::Vector3f(0, 400, 5));
        path->addPosition(sf::Vector3f(-200, -50, 1));
        path->addPosition(sf::Vector3f(150, -400, 5));
        pe->setShotPathModel();

        break;
    }

    pe->setPosition(pos.x, pos.y);
    pe->setPath(path);
    return pe;
}