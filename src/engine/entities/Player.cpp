#include "Player.hpp"

float Player::diag_speed = max_speed * max_speed / sqrt(max_speed * max_speed + max_speed * max_speed);

Player::Player() : Entity(sf::Vector2f(200, 200)), _shots_cpt(0), _life_cpt(0), _life(max_life), _nb_shots(1), _angle_shots(0)
{
    //_sprite.setTexture(TextureManager::getInstance().getTexture("player/1"));
    _animation = new Animated(_sprite, "player", 12);
}

Player::~Player()
{
    delete _animation;
    for (auto && s : _shots)
        delete s;
}

void Player::delete_shots()
{
   _shots.erase(std::remove_if(_shots.begin(), _shots.end(), [](Shot * s) {
       
       
       if(s->getPosition().x > 2050)
       {
           delete s;
           return true;
       }
       return false;
       
       }), _shots.end());
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                move(0, -max_speed);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) // Diag gauche
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                move(0, max_speed);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) // Diag gauche
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

void Player::move(float x, float y)
{
    if (x > 0 && _sprite.getPosition().x + _sprite.getSize().x / 2 >= 1920) x = 0;
    if (x < 0 && _sprite.getPosition().x - _sprite.getSize().x / 2 <= -10) x = 0;

    if (y > 0 && _sprite.getPosition().y + _sprite.getSize().y / 2 >= 1030) y = 0;
    if (y < 0 && _sprite.getPosition().y - _sprite.getSize().y / 2 <= 50) y = 0;
    Entity::move(x, y);
}

void Player::move(sf::Vector2f const & speed)
{
    move(speed.x, speed.y);
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
        constexpr float height_fire = 40;
        auto pos = _sprite.getPosition();
        pos.x += _sprite.getSize().x / 2;
        pos.y -= height_fire * (_nb_shots - 1) / 2;
        for (int i = 0; i < _nb_shots; ++i)
        {
            _shots.push_back(new Shot(pos, "shots/Bullet-2"));
            pos.y += height_fire;
        }
 
        auto pos1 = _sprite.getPosition();
        auto pos2 = _sprite.getPosition();
        pos1.y += _sprite.getSize().y / 2;
        pos2.y -= _sprite.getSize().y / 2;
        for (int i = 0; i < _angle_shots; ++i)
        {
            Shot* up = new Shot(pos1, "shots/Bullet-2");
            Path * upp = new Path(up);
            upp->addPosition(sf::Vector3f(2000, 500, 15));
            up->setPath(upp);
 
 
            Shot* down = new Shot(pos2, "shots/Bullet-2");
            Path * downp = new Path(down);
            downp->addPosition(sf::Vector3f(2000, -500, 15));
            down->setPath(downp);
 
            _shots.push_back(up);
            _shots.push_back(down);
            pos1.x -= height_fire;
            pos1.y -= height_fire;
            pos2.x -= height_fire;
            pos2.y += height_fire;
        }
        _shots_cpt = max_dT;
    }
}

void Player::decreaseLife()
{  
    if (_life > 0) 
    {
        if (_life_cpt == 0)
        {
            _life--;
            _life_cpt = max_dT;
        }
    }
}

void Player::update()
{
    _animation->update();
    move_inputs();
    shot_inputs();
    delete_shots();

    for (auto && s : _shots)
        s->update();

    
    if (_life_cpt != 0)
    {
        _life_cpt--;
        
        _sprite.setFillColor(sf::Color(255, 255 - (int) (255.0 * _life_cpt / max_dT), 255 - (int) (255.0 * (_life_cpt) / max_dT)));
    }
}   

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    Entity::draw(target, states);
    for (auto&& s : _shots)
        target.draw(*s);
}

void Player::increaseStats(int stats)
{
    switch(stats)
    {
        case 0:
            _nb_shots++;
            break;
        case 1:
            _angle_shots++;
            break;
    }
}