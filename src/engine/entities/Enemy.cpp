#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f const & size, std::string const & texture_path, int fire_speed) :
    Entity(size),
    _shots_cpt(0),
    _fire_speed(fire_speed),
    _isAlive(true),
    _lifeCounter(0),
    _life(2)
{
    //_sprite.setTexture(TextureManager::getInstance().getTexture(texture_path));
    _animation = new Animated(_sprite, texture_path, 12);
    _sprite.scale(sf::Vector2f(-1, 1));
}

Enemy::~Enemy()
{
    delete _path;
    for (auto &&s : _shots)
    {
        delete s;
    }
    
    delete _animation;
}

void Enemy::update()
{
    _animation->update();
    _shots.erase(std::remove_if(_shots.begin(), _shots.end(), [](auto s){
        if (s->getPosition().x < -100)
        {
            delete s;
            return true;
        } return false;}), 
    _shots.end());
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

    if (_lifeCounter != 0)
    {
        _lifeCounter--;
        
        _sprite.setFillColor(sf::Color(255, 255 - (int) (255.0 * _lifeCounter / max_dt), 255 - (int) (255.0 * (_lifeCounter) / max_dt)));
    }
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

void Enemy::hurt()
{
    if (_life > 0) 
    {
        if (_lifeCounter == 0)
        {
            _life--;
            _lifeCounter = max_dt;
        }
    }
    else
    {
        kill();
    }
}