#include "Player.hpp"

Player::Player()
{

}

void Player::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        move(0, -5);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        move(-5, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        move(0, 5);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        move(5, 0);
    
}