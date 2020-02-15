#include "Player.hpp"

float Player::diag_speed = max_speed * max_speed / sqrt(max_speed * max_speed + max_speed * max_speed);

Player::Player() : Entity(), _shots_cpt(0)
{
    _sprite.setFillColor(sf::Color::Blue);
}

void Player::delete_shots()
{
   _shots.erase(std::remove_if(_shots.begin(), _shots.end(), [](Shot * s) {return s->isDead();}), _shots.end());
}

void Player::move_inputs()
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

void Player::shot_inputs()
{
    if (sf::Joystick::isConnected(0))
    {
        if (sf::Joystick::isButtonPressed(0, 0) && _shots_cpt == 0)
        {
            shot();
        }
    } else
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _shots_cpt == 0)
        {
            shot();
        }
    }


    if (_shots_cpt != 0)
        _shots_cpt--;
}

void Player::shot()
{
    constexpr int max_dT = 10;
    if (_shots_cpt == 0)
    {
        _shots.push_back(new Shot());
        _shots_cpt = max_dT;
    }
}

void Player::update()
{
    move_inputs();
    shot_inputs();
    delete_shots();

    for (auto && s : _shots)
        s->update();
}   

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    Entity::draw(target, states);
    for (auto&& s : _shots)
        target.draw(*s);
}