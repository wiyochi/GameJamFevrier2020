#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f const & size, std::string const & texture_path, int fire_speed) : Entity(size), _shots_cpt(0), _fire_speed(fire_speed), _isAlive(true)
{
    _sprite.setTexture(TextureManager::getInstance().getTexture(texture_path));
    _sprite.scale(sf::Vector2f(-1, 1));
}

Enemy::~Enemy()
{
    delete _path;
}

void Enemy::update()
{
    _shots.erase(std::remove_if(_shots.begin(), _shots.end(), [](auto s){return s->getPosition().x < -100;}), _shots.end());
    if (isAlive())
    {
        _path->update();
        if (_shots_cpt == 0)
        {
            Shot * s = new Shot(_sprite.getPosition());
            Path * p = new Path(s);

            for (auto && v : _model)
            {
                p->addPosition(v);
            }

            s->setPath(p);
            _shots.push_back(s);
            _shots_cpt = _fire_speed;
        }
        _shots_cpt--;
    }
    for(auto && ps : _shots)
        ps->update();
}

void Enemy::draw(sf::RenderTarget & target, sf::RenderStates states) const 
{
    if(isAlive())
        Entity::draw(target, states);

    for(auto && ps : _shots)
        target.draw(*ps);
}

void Enemy::setShotPathModel(int nb, ...)
{
    if (nb != 0)
    {
        va_list args;
        va_start(args, nb);
    
        for (int i = 0; i < nb; ++i) {
            sf::Vector3f * vec = va_arg(args, sf::Vector3f*);
            _model.push_back(sf::Vector3f(vec->x, vec->y, vec->z));
            delete vec;
        }
    
        va_end(args);
    } else
    {
        _model.push_back(sf::Vector3f(-2000, 0, 10));
    }
    
}