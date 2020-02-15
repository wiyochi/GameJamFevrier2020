#include "Player.hpp"

float Player::diag_speed = max_speed * max_speed / sqrt(max_speed * max_speed + max_speed * max_speed);

Player::Player()
{

}

void Player::update()
{

    if (sf::Joystick::isConnected(0))
    {
        float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
        float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
       
        if (abs(x) < zero_zone) x = 0;
        if (abs(y) < zero_zone) y = 0;
        move(x * speed_coef , y * speed_coef);
    } else 
    {
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            || (!sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) // Diag gauche
            {
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    move(-max_speed, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Diag gauche
            {
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    move(max_speed, 0);
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) // Monte
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) // Diag gauche
            {
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    move(-diag_speed, -diag_speed);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Diag droite
                move(diag_speed, -diag_speed);
            else
                move(0, -max_speed);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // Descend
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) // Diag gauche
            {
                if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    move(-diag_speed, diag_speed);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Diag droite
                move(diag_speed, diag_speed);
            else 
                move(0, max_speed);
        }
    }
}