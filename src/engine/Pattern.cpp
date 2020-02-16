#include "Pattern.hpp"

std::mt19937 Pattern::gen(256);
std::uniform_int_distribution<> Pattern::dist(1, 5);

int Pattern::getPattern(int type, std::vector<Enemy*>& enemis)
{
    int frames = 1200;
    switch (type)
    {
    case 1:
        for (int i = 0; i < 4; i++)
            enemis.push_back(Builder::createEnemy(Builder::NX, sf::Vector2f(2000, -500 + i*100)));
        for (int i = 0; i < 4; i++)
            enemis.push_back(Builder::createEnemy(Builder::RX, sf::Vector2f(2000, 1100 + i*100)));
        for (int i = 0; i < 3; i++)
            enemis.push_back(Builder::createEnemy(Builder::MW, sf::Vector2f(1850, 500 + i*100)));
        frames = 1200;
        break;
    case 2:
        enemis.push_back(Builder::createEnemy(Builder::WM, sf::Vector2f(1850, 200)));
        enemis.push_back(Builder::createEnemy(Builder::WM, sf::Vector2f(1850, 700)));
        enemis.push_back(Builder::createEnemy(Builder::WM, sf::Vector2f(1850, 1100)));
        enemis.push_back(Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(2000, 200)));
        enemis.push_back(Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(3500, 700)));
        frames = 1200;
        break;
    case 3:
        enemis.push_back(Builder::createEnemy(Builder::I, sf::Vector2f(1850, 200)));
        enemis.push_back(Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(2000, 200)));
        enemis.push_back(Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(2500, 400)));
        enemis.push_back(Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(2600, 600)));
        enemis.push_back(Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(3100, 800)));
        enemis.push_back(Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(3900, 700)));
        enemis.push_back(Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(4400, 500)));
        enemis.push_back(Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(4900, 300)));
        frames = 1200;
        break;
    case 4:
        enemis.push_back(Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(2000, 200)));
        enemis.push_back(Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(2500, 400)));
        enemis.push_back(Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(2600, 600)));
        enemis.push_back(Builder::createEnemy(Builder::KAMIKAZE, sf::Vector2f(3100, 800)));
        for (int i = 0; i < 4; i++)
            enemis.push_back(Builder::createEnemy(Builder::RX, sf::Vector2f(2000, 1100 + i*100)));
        frames = 1200;
        break;
    case 5:
        enemis.push_back(Builder::createEnemy(Builder::I, sf::Vector2f(1850, -100)));
        enemis.push_back(Builder::createEnemy(Builder::I, sf::Vector2f(1500, 100)));
        enemis.push_back(Builder::createEnemy(Builder::WM, sf::Vector2f(1850, 600)));
        enemis.push_back(Builder::createEnemy(Builder::WM, sf::Vector2f(1850, 800)));
        frames = 1200;
        break;
    default:
        break;
    }
    return frames;
}

int Pattern::getRandomPattern(std::vector<Enemy*>& enemis)
{
    return getPattern(dist(gen), enemis);
}